//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("widm.res");
USEFORM("FfrmGeneral.cpp", frmGeneral);
USEFORM("FfrmTest.cpp", frmTest); /* TFrame: File Type */
USEFORM("FfrmVraag.cpp", frmVraag); /* TFrame: File Type */
USEFORM("FfrmAntwoord.cpp", frmAntwoord); /* TFrame: File Type */
USEFORM("FfrmTestwin.cpp", frmTestwin);
USEFORM("FfrmTestlogin.cpp", frmTestLogin);
USEFORM("FfrmSurvey.cpp", frmSurvey);
USEFORM("FfrmTesttest.cpp", frmTesttest);
USEUNIT("exitorder.cpp");
USEFORM("FfrmExecutie.cpp", frmExecutie);
USE("TODO.txt", File);
USE("ChangeLog.txt", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfrmGeneral), &frmGeneral);
//                 Application->CreateForm(__classid(TfrmTesttest), &frmTesttest);
//                 Application->CreateForm(__classid(TfrmExecutie), &frmExecutie);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
