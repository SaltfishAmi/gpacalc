//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmScratch *frmScratch;
int started = 0;
int lefted=0;
//---------------------------------------------------------------------------
__fastcall TfrmScratch::TfrmScratch(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmScratch::Button1Click(TObject *Sender)
{
    scratched[scrIndex]=1;
    MainForm->StringGrid1->Repaint();
    started = 0;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmScratch::Shape1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if(started&&Shift.Contains(ssShift)){((TShape*)Sender)->Visible=false;
    Label1->Visible=true;}
}
//---------------------------------------------------------------------------
void __fastcall TfrmScratch::Button3Click(TObject *Sender)
{
    started = 1;
    Button3->Visible=false;
    Button1->Enabled=true;
    //Label1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmScratch::Button2Click(TObject *Sender)
{
    started = 0;
    Close();
}
//---------------------------------------------------------------------------



