//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "SHDocVw_OCX.h"
#include "XStringGrid.hpp"
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <OleCtrls.hpp>
extern int aCol, aRow;
extern int scratched[149];
extern int scrIndex;
extern AnsiString filename;
extern int yesno;
float Grade2Gp(AnsiString Gr);
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *grGeneral;
    TGroupBox *grXf;
    TEdit *edXf;
    TRadioButton *rdp0;
    TRadioButton *rdp5;
    TGroupBox *grGr;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *edGr;
    TRadioButton *rdPnt;
    TRadioButton *rdLvl;
    TTrackBar *trkLvl;
    TButton *btnAdd;
    TButton *btnCalc;
    TLabel *Label7;
    TCppWebBrowser *CppWebBrowser1;
    TXStringGrid *StringGrid1;
    TButton *btnMode;
    TGroupBox *grAutomate;
    TLabel *Label9;
    TEdit *edCardId;
    TLabel *Label10;
    TEdit *edCardPw;
    TLabel *Label11;
    TEdit *edVercode;
    TButton *btnGetVercode;
    TButton *btnLogin;
    TTimer *tmVercode;
    TLabel *Label12;
    TTimer *tmLogin;
    TLabel *labLength;
    TLabel *Label13;
    TButton *btnReAddCourses;
    TPopupMenu *ppmOnGrid;
    TMenuItem *mitDelete;
    TMenuItem *C1;
    TMenuItem *mitExclude;
    TMenuItem *R1;
    TMenuItem *mitClear;
    TMenuItem *mitExclAll;
    TMenuItem *mitIncludeAll;
    TMenuItem *mitEditCourse;
    TEdit *edName;
    TLabel *Label14;
    TRichEdit *edDebug;
    TCppWebBrowser *CppWebBrowser2;
    TRadioButton *chkScratch;
    TButton *btnInput;
    TButton *btnOutput;
    TLabel *Label15;
    TMenuItem *mitScra;
    TMenuItem *N1;
    TRadioButton *chkNormal;
    TRadioButton *chkGuess;
    TButton *btnVPN;
    TLabel *Label8;
    void __fastcall rdLvlClick(TObject *Sender);
    void __fastcall rdPntClick(TObject *Sender);
    void __fastcall btnAddClick(TObject *Sender);
    void __fastcall btnCalcClick(TObject *Sender);
    void __fastcall Label7Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnModeClick(TObject *Sender);
    void __fastcall btnGetVercodeClick(TObject *Sender);
    void __fastcall tmVercodeTimer(TObject *Sender);
    void __fastcall btnLoginClick(TObject *Sender);
    void __fastcall CppWebBrowser1DownloadComplete(TObject *Sender);
    void __fastcall Label12Click(TObject *Sender);
    void __fastcall tmLoginTimer(TObject *Sender);
    void __fastcall edCardPwChange(TObject *Sender);
    void __fastcall labLengthMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall labLengthMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall labLengthMouseLeave(TObject *Sender);
    void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall StringGrid1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall mitExcludeClick(TObject *Sender);
    void __fastcall mitDeleteClick(TObject *Sender);
    void __fastcall mitClearClick(TObject *Sender);
    void __fastcall btnReAddCoursesClick(TObject *Sender);
    void __fastcall mitExclAllClick(TObject *Sender);
    void __fastcall mitIncludeAllClick(TObject *Sender);
    void __fastcall mitEditCourseClick(TObject *Sender);
    void __fastcall edNameEnter(TObject *Sender);
    void __fastcall edNameExit(TObject *Sender);
    void __fastcall edXfEnter(TObject *Sender);
    void __fastcall edXfExit(TObject *Sender);
    void __fastcall Label14Click(TObject *Sender);
    void __fastcall chkScratchClick(TObject *Sender);
    void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall btnOutputClick(TObject *Sender);
    void __fastcall btnInputClick(TObject *Sender);
    void __fastcall StringGrid1MouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
    void __fastcall StringGrid1MouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
    void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall StringGrid1CellProps(TObject *Sender, TCanvas *Canvas,
          TAlignment &Alignment, AnsiString &CellText,
          TGridDrawState AState, int Row, int Col);
    void __fastcall mitScraClick(TObject *Sender);
    void __fastcall StringGrid1DblClick(TObject *Sender);
    void __fastcall edGrKeyPress(TObject *Sender, char &Key);
    void __fastcall CppWebBrowser1NavigateError(TObject *Sender,
          LPDISPATCH pDisp, Variant *URL, Variant *Frame,
          Variant *StatusCode, VARIANT_BOOL *Cancel);
    void __fastcall btnVPNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
    AnsiString WEB2HTMLCode(TCppWebBrowser *CppWebBrowser);
    void __fastcall WebPostData(TCppWebBrowser *CppWebBrowser, String sURL, String sPostData);

};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
