//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmSurvey.h"
#include "FfrmGeneral.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FfrmTestwin"
#pragma resource "*.dfm"
TfrmSurvey *frmSurvey;
//---------------------------------------------------------------------------
__fastcall TfrmSurvey::TfrmSurvey(TComponent* Owner)
        : TfrmTestwin(Owner)
{
/*
  void redScreen();
  void greenScreen();
  void showLogin();

  virtual void __fastcall onButtonClick(TObject *Sender);
  virtual void __fastcall onTimered();
  virtual void LoginCloseCallback();
  virtual void LoginCallback(String name);

  void setvraag(String vraag, TStringList *antwoorden);
  void hidebuttons();
*/
}

void __fastcall TfrmSurvey::onButtonClick(TObject *Sender) {
  for (int x = 0; x < nitems; x++) {
    if (buttons[x] == Sender) {
//      int ix = kandi->list->Add(lblQ->Caption);
//      kandi->list->Names[ix] = lblQ->Caption;
//      kandi->list->Values[ix] = labels[x]->Caption;
      kandi->list->Add(lblQ->Caption + "=" + labels[x]->Caption);
    }
  }
  next();
}

void __fastcall TfrmSurvey::onTimered() {
        showLogin();
}

void TfrmSurvey::next() {
  if (cur >= frmGeneral->surveys->Count) {
    if (frmGeneral->lstKandi->Items->Item[curkandi]->SubItems->Strings[1] != "")
      redScreen();
    else
      greenScreen();
  } else {
    Vraag *v = hasQuestion(frmGeneral->vragen, frmGeneral->surveys->Strings[cur]);
    if (v) {
      TStringList *list = new TStringList();
      for (int t = 0; t < v->antwoorden->Count; t++)
        list->Add(v->antwoorden->Names[t]);
      setvraag(frmGeneral->surveys->Strings[cur], list);
//      delete list;
      cur++;
    } else next();
  }
}


void TfrmSurvey::LoginCallback(String name) {
        for (curkandi = 0; curkandi < frmGeneral->lstKandi->Items->Count; curkandi++) {
          if (frmGeneral->lstKandi->Items->Item[curkandi]->Caption == name) {
            if (frmGeneral->lstKandi->Items->Item[curkandi]->SubItems->Strings[2] != "te doen") {
                Application->MessageBox("Survey al gedaan!", "Error", MB_ICONERROR);
                return;
            }
            kandi = (KandiData*)frmGeneral->lstKandi->Items->Item[curkandi]->Data;
            frmGeneral->lstKandi->Items->Item[curkandi]->SubItems->Strings[2] = "klaar";

            closeLogin();

            cur = 0;
            next();

            return;
          }
        }

        Application->MessageBox("Onbekende naam!", "Error", MB_ICONERROR);

}

//---------------------------------------------------------------------------

