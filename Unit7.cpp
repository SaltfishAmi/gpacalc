//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __stdcall CrnListDir(String strDir, TStrings *lst, String fileFmt)
{
    WIN32_FIND_DATA wfd;
    lst->Clear();
    HANDLE hFind = ::FindFirstFile((strDir + "\\" + fileFmt).c_str(), &wfd);
    if(INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            if (strcmp(wfd.cFileName, ".") !=0 && strcmp(wfd.cFileName, "..") != 0)
            lst->Add(wfd.cFileName);
        }while(::FindNextFile(hFind, &wfd));
    }
    ::FindClose(hFind);

    return lst->Count;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormShow(TObject *Sender)
{
    ListBox1->Clear();
    CrnListDir(ExtractFilePath(Application->ExeName), ListBox1->Items, "*.gpml");
/*	String additionalPath="";
    String tmp = "*.gpml";
    do {
        if(tmp.Pos("\\")==0){
            additionalPath=additionalPath+"";
            break;
        }
        else {
            additionalPath = additionalPath + tmp.SetLength(tmp.Pos("\\"));
            DeleteBeforeW("\\",tmp);
        }
    } while(1); */
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
    yesno=0;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button1Click(TObject *Sender)
{
    if(ListBox1->ItemIndex!=-1){
        filename = ListBox1->Items->Strings[ListBox1->ItemIndex];
        yesno=1;
        Close();
    }
}
//---------------------------------------------------------------------------


