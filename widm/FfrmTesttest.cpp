//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmTesttest.h"
#include "FfrmVraag.h"
#include "FfrmAntwoord.h"
#include "FfrmGeneral.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FfrmTestwin"
#pragma resource "*.dfm"
TfrmTesttest *frmTesttest;
//---------------------------------------------------------------------------
__fastcall TfrmTesttest::TfrmTesttest(TComponent* Owner)
        : TfrmTestwin(Owner)
{
        test = (TfrmTest *)Owner;
        mol = frmGeneral->getMol();
        moldat = NULL;
        for (int t = 0; t < frmGeneral->lstKandi->Items->Count; t++)
          if (frmGeneral->lstKandi->Items->Item[t]->Caption == mol)
            moldat = (KandiData *)frmGeneral->lstKandi->Items->Item[t]->Data;
}
//---------------------------------------------------------------------------

/* check whether the answer is correct */
static bool isQuestionRight (String answer, TfrmVraag *v, String mol, KandiData *moldat) {
  if (answer == "Pas deze vraag") /* pass question */
    return true;

  if (v->chkSurvey->Checked) { /* survey question: check if answer same as the mole */
    if (!moldat) return false;
    if (moldat->list->Values[v->cboVraag->Text] == answer)
      return true;
  } else { /* normal question */
    TfrmAntwoord *a = v->getAnswer (answer);
    if (a && a->isGood (mol)) return true;
  }

  return false;
}

void __fastcall TfrmTesttest::onButtonClick(TObject *Sender) {
  for (int x = 0; x < nitems; x++) {
    if (buttons[x] == Sender) {
      if (labels[x]->Caption == "Pas deze vraag")
        pasvragen--;
      if (isQuestionRight (labels[x]->Caption, (TfrmVraag *)test->questions->Items[cur], mol, moldat))
        ngoed++;
      if (aws != "") aws += ",";
      aws += labels[x]->Caption;
    }
  }
  next();
}

void TfrmTesttest::next() {
  cur++;
  if (cur >= test->questions->Count - 1) {
    hidebuttons();
    imgMol->Visible = false;
    lblQ->Visible = false;
    /* save results */
    TListItem *it = test->lstUitslag->Items->Item[curkandi];
    it->SubItems->Strings[2] = "*";
    it->SubItems->Strings[3] = String(ngoed) + " goed";
    it->SubItems->Strings[4] = aws;
    TDateTime diff = Time() - begin;
    unsigned short hour, min, sec, msec;
    DecodeTime(diff, hour, min, sec, msec);
    it->SubItems->Strings[5] = hour * 8600000 + min * 60000 + sec * 1000 + msec;
    showLogin();
  } else {
    TfrmVraag *v = (TfrmVraag *)test->questions->Items[cur];
    TStringList *list = new TStringList();
    for (int t = 0; t < v->answers->Count; t++) {
      TfrmAntwoord *a = (TfrmAntwoord *)v->answers->Items[t];
      if (a->txtVraag->Text != "")
        list->Add(a->txtVraag->Text);
    }
    if (pasvragen > 0) list->Add("Pas deze vraag");

    setvraag(v->cboVraag->Text, list);
  }
}


void TfrmTesttest::LoginCallback(String name) {
        for (curkandi = 0; curkandi < frmGeneral->lstKandi->Items->Count; curkandi++) {
          if (test->lstUitslag->Items->Item[curkandi]->Caption == name) {
            if (test->lstUitslag->Items->Item[curkandi]->SubItems->Strings[2] != "") {
                Application->MessageBox("Test al gedaan!", "Error", MB_ICONERROR);
                return;
            }
            String status = test->lstUitslag->Items->Item[curkandi]->SubItems->Strings[1];
            if (status != "" && status[1] >= '0' && status[1] <= '9')
            pasvragen = status.SubString(1, status.Pos(" ") - 1).ToIntDef(0);

            kandi = (KandiData*)frmGeneral->lstKandi->Items->Item[curkandi]->Data;

            closeLogin();

            cur = -1;
            ngoed = 0;
            begin = Time();
            imgMol->Visible = true;
            lblQ->Visible = true;
            next();

            return;
          }
        }

        Application->MessageBox("Onbekende naam!", "Error", MB_ICONERROR);

}

void __fastcall TfrmTesttest::FormClick(TObject *Sender)
{
login = new TfrmTestLogin(this, this);        
}
//---------------------------------------------------------------------------

