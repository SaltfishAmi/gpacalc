//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmEditCourse : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TButton *btnOK;
    TButton *btnCancel;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *edOrName;
    TEdit *edOrXf;
    TEdit *edOrGr;
    TCheckBox *chOrInc;
    TEdit *edNwName;
    TEdit *edNwXf;
    TEdit *edNwGr;
    TCheckBox *chNwInc;
    TLabel *lblZero;
    TLabel *lblFive;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOKClick(TObject *Sender);
    void __fastcall lblZeroClick(TObject *Sender);
    void __fastcall lblFiveClick(TObject *Sender);
    void __fastcall Validate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmEditCourse(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEditCourse *frmEditCourse;
//---------------------------------------------------------------------------
#endif
