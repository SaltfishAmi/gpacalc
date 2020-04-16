//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::OKButtonClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormShow(TObject *Sender)
{
    Version->Caption = RichEdit1->Lines->operator [](0);
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::RichEdit1MouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if(Shift.Contains(ssLeft))Handled=true;
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Button1Click(TObject *Sender)
{
    RichEdit1->SelectAll();
    RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------

