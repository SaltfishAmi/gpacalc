//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmDebug : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TButton *Button1;
    TRichEdit *RichEdit1;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmDebug(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDebug *frmDebug;
//---------------------------------------------------------------------------
#endif
