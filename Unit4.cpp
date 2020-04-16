//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDebug *frmDebug;
//---------------------------------------------------------------------------
__fastcall TfrmDebug::TfrmDebug(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmDebug::Button1Click(TObject *Sender)
{
    //MainForm->CppWebBrowser1->Stop();
    //Sleep(500);
    //MainForm->loginSuccess=0;
    //MainForm->CppWebBrowser1->Navigate((wchar_t*)(Edit1->Text.c_str()));
    //Sleep(500);
    MainForm->edDebug->Lines=RichEdit1->Lines;
    Close();
}
//---------------------------------------------------------------------------
