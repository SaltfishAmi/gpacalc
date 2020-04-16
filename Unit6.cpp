//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormShow(TObject *Sender)
{
    Edit1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
    yesno=0;
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
    int invalid =   Edit1->Text.Pos("\\") |
                    Edit1->Text.Pos("/") |
                    Edit1->Text.Pos(":") |
                    Edit1->Text.Pos("*") |
                    Edit1->Text.Pos("?") |
                    Edit1->Text.Pos("\"") |
                    Edit1->Text.Pos("<") |
                    Edit1->Text.Pos(">") |
                    Edit1->Text.Pos("|") ;
    if(invalid){
        MessageDlg("文件名不能包含下列任何字符:\n        \\ / : * ? \" < > |",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        Edit1->SelectAll();
        return;
    }
    if(Edit1->Text.IsEmpty()){
        MessageDlg("请输入文件名！",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2) ),1);
        Edit1->SetFocus();
        return;
    }
    filename=Edit1->Text+".gpml";
    yesno=1;
    Close();
}
//---------------------------------------------------------------------------
