//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmTestlogin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTestLogin *frmTestLogin;
//---------------------------------------------------------------------------
__fastcall TfrmTestLogin::TfrmTestLogin(TComponent* Owner, TfrmTestwin *par)
  : TForm(Owner)
{
  parent = par;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestLogin::Button2Click(TObject *Sender)
{
  Close();
  parent->LoginCloseCallback();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTestLogin::Button1Click(TObject *Sender)
{
  parent->LoginCallback(txtName->Text);
}
//---------------------------------------------------------------------------

