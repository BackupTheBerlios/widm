//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmTest.h"
#include "FfrmVraag.h"
#include "FfrmAntwoord.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmVraag *frmVraag;
//---------------------------------------------------------------------------
__fastcall TfrmVraag::TfrmVraag(TComponent* Owner)
        : TFrame(Owner)
{
        answers = new TComponentList();
        addNewAnswer();

        reload();
}

__fastcall TfrmVraag::~TfrmVraag() {
        delete answers;
}
//---------------------------------------------------------------------------

void TfrmVraag::reload() {
        /* let user pre-select questions */
        cboVraag->Items->Clear();
        if (!frmGeneral->vragen) return;
        for (int t = 0; t < frmGeneral->vragen->Count; t++) {
                Vraag *v = (Vraag*)frmGeneral->vragen->Items[t];
                cboVraag->Items->Add(v->vraag);
        }

        for (int t = 0; t < answers->Count; t++)
                ((TfrmAntwoord*)answers->Items[t])->update();

        if (cboVraag->Text != "") cboVraagChange(NULL);

}

void TfrmVraag::addNewAnswer() {
        TfrmAntwoord *aw = new TfrmAntwoord(this);
        aw->Name = "";
        aw->Top = Height - 7;
        aw->Left = lblAw->Left;
        aw->Width = Width - lblAw->Left - 1;
        aw->Anchors << akRight;
        aw->Parent = this;
        aw->Show();
        Height += aw->Height;
        answers->Add(aw);
}

void TfrmVraag::answerChangedNotification(TComponent* Owner) {
        if (Owner == answers->Items[answers->Count - 1])
                addNewAnswer();
}


void TfrmVraag::answerDeletedNotification(TComponent* Owner) {
        int ix = answers->IndexOf(Owner);
        TfrmAntwoord *ans = (TfrmAntwoord*)Owner;
        int hei = ans->Height;
        if (answers->Count == 1) return;
        for (int t = ix + 1; t < answers->Count; t++)
                ((TControl*)answers->Items[t])->Top -= hei;
        ans->Parent = NULL; // TODO delete?
        Height -= ans->Height;
        answers->Extract(ans);
}

void __fastcall TfrmVraag::cboVraagChange(TObject *Sender)
{
        Vraag *v = hasQuestion(frmGeneral->vragen, cboVraag->Text);
        if (v) {
                chkSurvey->Checked = v->is_survey;
                for (int t = answers->Count - 1; t >= 1; t--)
                        answerDeletedNotification(answers->Items[t]);
                for (int t = 0; t < v->antwoorden->Count; t++) {
                        addNewAnswer();
                        TfrmAntwoord *a = (TfrmAntwoord*)answers->Items[answers->Count-2];
                        a->txtVraag->Text = v->antwoorden->Names[t];
                        a->cboNaam->Text = v->antwoorden->Values[a->txtVraag->Text];
                }
        }
        ((TfrmTest*)Parent)->onVraagEdit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVraag::Button1Click(TObject *Sender)
{
        ((TfrmTest*)Parent)->onVraagRemove(this);
}
//---------------------------------------------------------------------------

void TfrmVraag::opslaan(TIniFile *f, String section) {
        String key = "Vraag:" + cboVraag->Text;
        f->WriteString(section, key + ":survey", chkSurvey->Checked?"ja":"nee");
        for (int t = 0; t < answers->Count; t++) {
                TfrmAntwoord *a = (TfrmAntwoord*)answers->Items[t];
                f->WriteString(section, key + ":aw" + a->txtVraag->Text, a->cboNaam->Text);
        }
}

void TfrmVraag::openen(TIniFile *f, String section, String vraag) {
        cboVraag->Text = vraag;
        chkSurvey->Checked = (f->ReadString(section, "Vraag:" + vraag + ":survey", "") == "ja");

        TStringList *list = new TStringList();

        f->ReadSection(section, list);

        for (int t = 0; t < list->Count; t++) {
                if (list->Strings[t].SubString(1, vraag.Length() + 9) == "Vraag:" + vraag + ":aw") {
                        String tmp = list->Strings[t].SubString(vraag.Length() + 10, list->Strings[t].Length());
                        addNewAnswer();
                        TfrmAntwoord *tmpa = (TfrmAntwoord*)answers->Items[answers->Count - 2];
                        tmpa->txtVraag->Text = tmp;
                        tmpa->cboNaam->Text = f->ReadString(section, list->Strings[t], "");
                }
        }

        delete list;
}

