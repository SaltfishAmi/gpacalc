//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", MainForm);
USEFORM("Unit2.cpp", AboutBox);
USEFORM("Unit3.cpp", frmEditCourse);
USEFORM("Unit4.cpp", frmDebug);
USEFORM("Unit5.cpp", frmScratch);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit7.cpp", Form7);
USEFORM("Unit8.cpp", frmGuess);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "SEU GPA Calc";
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->CreateForm(__classid(TfrmEditCourse), &frmEditCourse);
         Application->CreateForm(__classid(TfrmDebug), &frmDebug);
         Application->CreateForm(__classid(TForm6), &Form6);
         Application->CreateForm(__classid(TForm7), &Form7);
         Application->CreateForm(__classid(TfrmGuess), &frmGuess);
         Application->Run();
    }
    catch (Exception &exception)
    {
         //MessageDlg("程序出错了，请将以下的错误信息报告给作者：\n"+exception.Message+"\n程序将立即退出。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2)),1);
         //Application->Terminate();
         Application->ShowException(&exception);
    }
    catch (...)
    {
        try
        {
            throw Exception("");
        }
        catch (Exception &exception)
        {
            //MessageDlg("程序出错了，请将以下的错误信息报告给作者：\n"+exception.Message+"\n程序将立即退出。",mtError,(System::Set<TMsgDlgBtn, mbYes, mbHelp> () << TMsgDlgBtn(2)),1);
            //Application->Terminate();
            Application->ShowException(&exception);
        }
    }
    return 0;
}
//---------------------------------------------------------------------------

