//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmExecutie.h"
#include "FfrmGeneral.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FfrmTestwin"
#pragma resource "*.dfm"
TfrmExecutie *frmExecutie;
//---------------------------------------------------------------------------
__fastcall TfrmExecutie::TfrmExecutie(TComponent* Owner, String uitv, int percentage)
        : TfrmTestwin(Owner, percentage == -1)
{
        if (percentage != -1) showPercentage (percentage);
        uitvaller = uitv;
        done = false;
}
//---------------------------------------------------------------------------

void TfrmExecutie::showPercentage (int percentage) {
   lblPercentage->Visible = true;
   lblPercentage->Font->Height = lblPercentage->Height;
   lblPercentage->Caption = String(percentage) + "%";
}

void __fastcall TfrmExecutie::onTimered() {
        showLogin();
}

void TfrmExecutie::LoginCallback(String name) {
        for (int curkandi = 0; curkandi < frmGeneral->lstKandi->Items->Count; curkandi++) {
          if (frmGeneral->lstKandi->Items->Item[curkandi]->Caption == name) {
            closeLogin();
            if (name == uitvaller) {
              redScreen(true);
              done = true;
            } else
              greenScreen();
            return;
          }
        }

        Application->MessageBox("Onbekende naam!", "Error", MB_ICONERROR);
}
void __fastcall TfrmExecutie::FormClose(TObject *Sender,
      TCloseAction &Action)
{
       for (int t = 0; t < frmGeneral->lstKandi->Items->Count; t++) {
                TListItem *item = frmGeneral->lstKandi->Items->Item[t];
                if (item->Caption == uitvaller) {
                        if (item->SubItems->Strings[0] == "") return;
                        int ret = Application->MessageBox("Uitvaller(s) op non-actief zetten?", "Vraag", MB_ICONQUESTION|MB_YESNO);
                        if (ret == IDYES) {
                                ((KandiData*)item->Data)->flags |= FLAG_ACTIVE;
                                item->SubItems->Strings[0] = "";
                                return;
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmExecutie::lblPercentageClick(TObject *Sender)
{
  lblPercentage->Visible = false;
  showLogin();        
}
//---------------------------------------------------------------------------

void __fastcall TfrmExecutie::FormKeyPress(TObject *Sender, char &Key)
{
  if (Key == ' ') tmrTimer (Sender);        
}
//---------------------------------------------------------------------------


void __fastcall TfrmExecutie::FormResize(TObject *Sender)
{
   lblPercentage->Font->Height = lblPercentage->Height;
}
//---------------------------------------------------------------------------

