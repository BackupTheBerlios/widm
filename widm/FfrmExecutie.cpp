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
__fastcall TfrmExecutie::TfrmExecutie(TComponent* Owner, String uitv)
        : TfrmTestwin(Owner)
{
        uitvaller = uitv;
        done = false;
}
//---------------------------------------------------------------------------

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
                        int ret = Application->MessageBox("Persoon op non-actief zetten?", "Vraag", MB_ICONQUESTION|MB_YESNO);
                        if (ret == IDYES) {
                                ((KandiData*)item->Data)->flags |= FLAG_ACTIVE;
                                item->SubItems->Strings[0] = "";
                                return;
                        }
                }
        }
}
//---------------------------------------------------------------------------

