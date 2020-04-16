//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEditCourse *frmEditCourse;
//---------------------------------------------------------------------------
__fastcall TfrmEditCourse::TfrmEditCourse(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditCourse::FormShow(TObject *Sender)
{
    edOrName->Text = MainForm->StringGrid1->Cells[0][aRow];
    edOrXf->Text = MainForm->StringGrid1->Cells[1][aRow];
    edOrGr->Text = MainForm->StringGrid1->Cells[2][aRow];
    edNwName->Text = edOrName->Text;
    edNwXf->Text = AnsiString((int)(edOrXf->Text.ToDouble()));
    edNwGr->Text = edOrGr->Text;
    chOrInc->Checked = (MainForm->StringGrid1->Cells[6][aRow]=="Yes"?true:false) ;
    chNwInc->Checked = chOrInc->Checked;
    if(edOrXf->Text.ToDouble() ==  ((double)((int)(edOrXf->Text.ToDouble()))) ) {
        lblZero->Color = clHighlight;
        lblZero->Font->Color = clWindow;
        lblFive->Color = clBtnFace;
        lblFive->Font->Color = clWindowText;
    } else {
        lblFive->Color = clHighlight;
        lblFive->Font->Color = clWindow;
        lblZero->Color = clBtnFace;
        lblZero->Font->Color = clWindowText;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditCourse::btnCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditCourse::btnOKClick(TObject *Sender)
{
    float NewXf;
    float NewGp = -1.000000;
    if(!edNwXf->Text.IsEmpty())  {
        if(edNwXf->Text.ToIntDef(-1)<0){
            MessageDlg("请检查课程学分数输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
            return;
        }
        NewXf = edNwXf->Text.ToIntDef(-1) + (lblFive->Color==clHighlight?0.5:0.0);
    }
    if(!edNwGr->Text.IsEmpty())  {
        NewGp = Grade2Gp(edNwGr->Text);
        if ((int)NewGp == -1) {
            MessageDlg("请检查课程成绩输入是否正确。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
            return;
        }
    }
    if(!edNwName->Text.IsEmpty())
        MainForm->StringGrid1->Cells[0][aRow]=edNwName->Text;
    if(!edNwXf->Text.IsEmpty()){
        AnsiString XfDisp;
        if(NewXf == (double)((int)(NewXf))) XfDisp = AnsiString(NewXf)+".0";
        else XfDisp = AnsiString(NewXf);
        MainForm->StringGrid1->Cells[1][aRow]= XfDisp;
    }
    if(!edNwGr->Text.IsEmpty()){
        MainForm->StringGrid1->Cells[2][aRow]=edNwGr->Text;
        AnsiString gpdisp=AnsiString(NewGp)+".0000";
        if ((int)NewGp == -2) gpdisp="0.0000";
        gpdisp=gpdisp.SetLength(3);
        if(gpdisp[3]=='7')gpdisp=gpdisp.SetLength(2)+"8";
        MainForm->StringGrid1->Cells[5][aRow]=gpdisp;
    }
    MainForm->StringGrid1->Cells[6][aRow]=(chNwInc->Checked==true?"Yes":"");
    //MainForm->doCalc[aRow-1]=(chNwInc->Checked==true?1:0);
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditCourse::lblZeroClick(TObject *Sender)
{
    lblZero->Color = clHighlight;
    lblZero->Font->Color = clWindow;
    lblFive->Color = clBtnFace;
    lblFive->Font->Color = clWindowText;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditCourse::lblFiveClick(TObject *Sender)
{
    lblFive->Color = clHighlight;
    lblFive->Font->Color = clWindow;
    lblZero->Color = clBtnFace;
    lblZero->Font->Color = clWindowText;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditCourse::Validate(TObject *Sender)
{
    if( edNwName->Text.IsEmpty() &&
        edNwXf->Text.IsEmpty() &&
        edNwGr->Text.IsEmpty() &&
        chNwInc->Checked == chOrInc->Checked )
        btnOK->Enabled = false;
    else btnOK->Enabled = true;
}
//---------------------------------------------------------------------------
