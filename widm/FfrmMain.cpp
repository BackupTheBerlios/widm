//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmMain.h"
#include "FfrmGeneral.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
#include "FfrmTests.h"
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
        TForm *childwin = new TfrmTests(this);
        childwin->Show();
        if (!frmGeneral) frmGeneral = new TfrmGeneral(this);
//        frmGeneral->WindowState = wsMaximized;
        frmGeneral->Show();
}
//---------------------------------------------------------------------------
