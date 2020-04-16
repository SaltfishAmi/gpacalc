//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit8.h"
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGuess *frmGuess;

int top, floor, target;
int isGP=0;

//---------------------------------------------------------------------------
__fastcall TfrmGuess::TfrmGuess(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

AnsiString gendisp() {
    if(isGP==0)
        return (AnsiString(floor) + "-" + AnsiString(top));
    else
        return (AnsiString(floor/10)+"."+AnsiString(floor%10)+"-"+AnsiString(top/10)+"."+AnsiString(top%10));

}
void __fastcall TfrmGuess::Edit2KeyPress(TObject *Sender, char &Key)
{
    if(Key==8)return;
    if(Key==13)return;
    if(!isGP&&(Key>'9'||Key<'0')){ Key=0; return; }
    if(isGP&&((Key>'9'||Key<'0')&&Key!='.')){ Key=0; return; }
    if(isGP&&Edit2->Text.Pos(".")!=0&&Key=='.'&&Edit2->SelLength==0)Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGuess::Button2Click(TObject *Sender)
{
    int operand;
    if(!isGP){
        operand = Edit2->Text.ToInt();
    } else {
        operand = (Edit2->Text.ToDouble()*10);
    }
    if(operand>top || operand<floor){
        ShowMessage("请输入 "+gendisp()+" 之间的数字。");
        return;
    }
    if(operand == target) {
        Label2->Caption = Edit2->Text;
        Edit2->Text = "";
        Label1->Caption = "恭喜！";
        Button2->Enabled=false;
        Button1->Enabled=true;
        Button1->Default=true;
    }
    else if(operand < target) {
        floor = operand;
        Edit2->Text = "";
        Label2->Caption=gendisp();
        Label1->Caption = "小了！";
    }
    else if(operand > target) {
        top = operand;
        Edit2->Text = "";
        Label2->Caption=gendisp();
        Label1->Caption = "大了！";
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmGuess::FormShow(TObject *Sender)
{
    if(isGP){
        top=48;
        floor=0;
    } else {
        top=100;
        floor=0;
    }
//    current=0;
    Button2->Enabled=true;
    Button2->Default=true;
    Button1->Enabled=false;
    Label2->Caption=gendisp();
    Label1->Caption="开始！";
}
//---------------------------------------------------------------------------

void __fastcall TfrmGuess::Button3Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmGuess::Button1Click(TObject *Sender)
{
    scratched[scrIndex]=1;
    MainForm->StringGrid1->Repaint();
    Close();
}
//---------------------------------------------------------------------------

