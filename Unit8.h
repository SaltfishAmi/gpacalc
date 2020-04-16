//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmGuess : public TForm
{
__published:	// IDE-managed Components
    TButton *Button2;
    TEdit *Edit2;
    TLabel *Label2;
    TButton *Button1;
    TButton *Button3;
    TLabel *Label1;
    void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmGuess(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGuess *frmGuess;
//---------------------------------------------------------------------------
#endif
extern int target;
extern int isGP;
