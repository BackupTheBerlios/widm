//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "FfrmTest.h"
#include "FfrmVraag.h"
#include "FfrmGeneral.h"
#include "FfrmTesttest.h"
#include "FfrmExecutie.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTest *frmTest;
//---------------------------------------------------------------------------
__fastcall TfrmTest::TfrmTest(TComponent* Owner)
        : TFrame(Owner)
{
        questions = new TComponentList();
        addNewQuestion();
}

__fastcall TfrmTest::~TfrmTest() {
        delete questions;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTest::onVraagResize(TObject *Sender)
{
        int t;
        for (t = 0; t < questions->Count; t++)
                if (questions->Items[t] == Sender) break;

        while (++t < questions->Count)
                ((TControl*)questions->Items[t])->Top =
                        ((TControl*)questions->Items[t-1])->Top + ((TControl*)questions->Items[t-1])->Height;

        pnlBelow->Top = ((TControl*)questions->Items[t-1])->Top + ((TControl*)questions->Items[t-1])->Height + 9;
        Height = pnlBelow->Top + pnlBelow->Height + 1;
}

void TfrmTest::addNewQuestion() {
        TfrmVraag *vr = new TfrmVraag(this);
        Height += vr->Height;
        vr->Name = "";
        vr->Top = pnlBelow->Top - 9;
        vr->Left = lblVragen->Left;
        if (questions->Count == 0)
                vr->Width = Width - vr->Left - 1;
        else
                vr->Width = ((TControl*)questions->Items[0])->Width;
        questions->Add(vr);
        vr->Anchors << akRight;
        vr->Parent = this;
        vr->OnResize = onVraagResize;
        vr->Show();
        pnlBelow->Top = vr->Top + vr->Height + 9;
}


void TfrmTest::reload(TfrmGeneral *frm, String name) {
        TListView *namen;
        frm->updateQuestionsList();
        /* call reload() for all current questions */
        for (int t = 0; t < questions->Count; t++)
                ((TfrmVraag*)questions->Items[t])->reload();

        /* refresh contestant data */
        int t, y;
        for (t = lstUitslag->Items->Count - 1; t >= 0; t--) {
                for (y = 0; y < frm->lstKandi->Items->Count; y++) {
                        if (lstUitslag->Items->Item[t]->Caption ==
                            frm->lstKandi->Items->Item[y]->Caption) {
                                lstUitslag->Items->Item[t]->SubItems->Strings[0] =
                                        frm->lstKandi->Items->Item[y]->SubItems->Strings[0];
                                break;
                        }
                }
                if (y == frm->lstKandi->Items->Count) {
                        /* contestant removed */
                        lstUitslag->Items->Delete(t);
                }
        }

        for (y = 0; y < frm->lstKandi->Items->Count; y++) {
                for (t = lstUitslag->Items->Count - 1; t >= 0; t--) {
                        if (lstUitslag->Items->Item[t]->Caption ==
                            frm->lstKandi->Items->Item[y]->Caption)
                                break;
                }
                if (t == -1) {
                        /* contestant added */
                        TListItem *item = lstUitslag->Items->Add();
                        item->Caption = frm->lstKandi->Items->Item[y]->Caption;
                        item->SubItems->Add(frm->lstKandi->Items->Item[y]->SubItems->Strings[0]);
                        item->SubItems->Add("");
                        item->SubItems->Add("");
                        item->SubItems->Add("");
                        item->SubItems->Add("");
                        item->SubItems->Add("");
                }
        }

        /* set visibility of results */
        if (frmGeneral->optAW->Checked) {
                lstUitslag->Columns->Items[4]->Width = 50;
                lstUitslag->Columns->Items[6]->Width = 50;
        } else {
                lstUitslag->Columns->Items[4]->Width = 0;
                lstUitslag->Columns->Items[6]->Width = 0;
        }

        /* update status */
        lblTitel->Caption = name;

        frm->updateSurveyList();

        TStringList *list = new TStringList();
        for (int t = 0; t < questions->Count; t++) {
                TfrmVraag *vr = (TfrmVraag *)questions->Items[t];;
                if (vr->chkSurvey->Checked)
                        frm->checkSurveyValid(vr->cboVraag->Text, list);
        }

        String tetesten;
        for (int t = 0; t < lstUitslag->Items->Count; t++) {
                if (lstUitslag->Items->Item[t]->SubItems->Strings[2] == "" &&
                    lstUitslag->Items->Item[t]->SubItems->Strings[0] != "") {
                        if (tetesten != "") tetesten += ",";
                        tetesten += lstUitslag->Items->Item[t]->Caption;
                }
        }

        if (list->Count == 0) {
                if (tetesten != "")
                        lblStatus->Caption = "De volgende mensen moeten de test nog maken: " + tetesten;
                else
                        lblStatus->Caption = "Klaar voor executie";
        } else {
                lblStatus->Caption = "De volgende mensen moeten nog een survey afnemen: " + list->CommaText;
        }
        delete list;
}

void __fastcall TfrmTest::onVraagEdit(TObject *Sender) {
        if (Sender == questions->Items[questions->Count - 1])
                addNewQuestion();
}

void __fastcall TfrmTest::onVraagRemove(TObject *Sender) {
        int ix = questions->IndexOf((TComponent *)Sender);
        TfrmVraag *que = (TfrmVraag*)Sender;
        int hei = que->Height;
        if (questions->Count == 1) return;
        for (int t = ix + 1; t < questions->Count; t++)
                ((TControl*)questions->Items[t])->Top -= hei;
        que->Parent = NULL; // TODO delete?
        pnlBelow->Top -= que->Height;
        Height -= que->Height;
        questions->Extract(que);
}

//---------------------------------------------------------------------------


void __fastcall TfrmTest::lstUitslagClick(TObject *Sender)
{
        TListItem *sel = lstUitslag->Selected;
        if (!sel) return;

        String status = sel->SubItems->Strings[1];
        if (status == "vrijstelling")
                chkVrij->Checked = true;
        else
                chkVrij->Checked = false;

        if (status != "" && status[1] >= '0' && status[1] <= '9')
                txtPas->Text = status.SubString(1, status.Pos(" ") - 1);
        else
                txtPas->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TfrmTest::chkVrijClick(TObject *Sender)
{
        TListItem *sel = lstUitslag->Selected;
        if (!sel) return;

        if (chkVrij->Checked)
                sel->SubItems->Strings[1] = "vrijstelling";
        else
                sel->SubItems->Strings[1] = "";
}
//---------------------------------------------------------------------------

void __fastcall TfrmTest::txtPasChange(TObject *Sender)
{
        TListItem *sel = lstUitslag->Selected;
        if (!sel) return;

        if (txtPas->Text != "")
                sel->SubItems->Strings[1] = txtPas->Text + " pasvragen";
        else
                sel->SubItems->Strings[1] = "";

}
//---------------------------------------------------------------------------

void __fastcall TfrmTest::cmdDeletePersClick(TObject *Sender)
{
        TListItem *sel = lstUitslag->Selected;
        if (!sel) return;

        sel->SubItems->Strings[2] = "";
        sel->SubItems->Strings[3] = "";
        sel->SubItems->Strings[4] = "";
        sel->SubItems->Strings[5] = "";
}
//---------------------------------------------------------------------------

void __fastcall TfrmTest::cmdTestClick(TObject *Sender)
{
        String mol = frmGeneral->getMol();
        if (mol == "") {
                Application->MessageBox("Kies eerst een mol!", "Fout", MB_ICONERROR);
                return;
        }
        TfrmTesttest *test = new TfrmTesttest(this);
        test->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTest::Button2Click(TObject *Sender)
{
        String uitv = uitvaller();
        if (uitv == "") {
                Application->MessageBox("Nog niet klaar voor executie!", "Fout", MB_ICONERROR);
                return;
        }
        TfrmExecutie *exec = new TfrmExecutie(this, uitv,
                                              chkPercentage->Checked ? rightPercentage () : -1);
        exec->ShowModal();
        // todo: delete exec?
        chkExecutie->Checked = true;
//        Application->MessageBox(uitvaller().c_str(), "Info", 0);
}

unsigned long aantalGoed (TListItem *i) {
  return i->SubItems->Strings[3].SubString(1, i->SubItems->Strings[3].Pos(" ") - 1).ToIntDef(0);
}

// geeft waarde terug: hoe lager, hoe eerder eruit
unsigned long uitval_value(TListItem *i, String mol) {
        if (i->Caption == mol || i->SubItems->Strings[0] == "") return 1<<31;

        int ival = aantalGoed (i);
        int itijd = i->SubItems->Strings[5].ToIntDef(0);

        return (ival << 24) + ((1<<24) - itijd);
}

//---------------------------------------------------------------------------

String TfrmTest::uitvaller() {
        String mol = frmGeneral->getMol();
        String uitvaller;
        unsigned long u_val, utmp;

        if (lstUitslag->Items->Count == 0) return "";

        uitvaller = lstUitslag->Items->Item[0]->Caption;
        u_val = uitval_value(lstUitslag->Items->Item[0], mol);


        for (int t = 1; t < lstUitslag->Items->Count; t++) {
          if (lstUitslag->Items->Item[t]->Caption == mol ||
              lstUitslag->Items->Item[t]->SubItems->Strings[1] == "vrijstelling")
            continue;
          if (lstUitslag->Items->Item[t]->SubItems->Strings[2] != "" &&  // TODO: this makes no sense
              lstUitslag->Items->Item[t]->SubItems->Strings[2] == "") return "";

          utmp = uitval_value(lstUitslag->Items->Item[t], mol);
          if (utmp < u_val) {
            uitvaller = lstUitslag->Items->Item[t]->Caption;
            u_val = utmp;
          }
        }

        return uitvaller;
}

TStringList *exitorder(TStringList *namen, String uitvaller);
void __fastcall TfrmTest::Button1Click(TObject *Sender)
{
        String uv = uitvaller();
        if (uv == "") {
                Application->MessageBox("Nog niet klaar voor executie!", "Error", MB_ICONERROR);
                return;
        }
        TStringList *namen = new TStringList(), *ret;
        for (int t = 0; t < lstUitslag->Items->Count; t++)
                if (lstUitslag->Items->Item[t]->SubItems->Strings[0] != "")
                        namen->Add(lstUitslag->Items->Item[t]->Caption);

        ret = exitorder(namen, uv);

        Application->MessageBox(ret->Text.c_str(), "Executievolgorde", MB_ICONINFORMATION);
        delete ret;
        delete namen;
}
//---------------------------------------------------------------------------

void TfrmTest::opslaan(TIniFile *file, String section) {
        file->WriteString(section, "Executed", chkExecutie->Checked?"ja":"nee");

        for (int t = 0; t < questions->Count; t++)
                ((TfrmVraag*)questions->Items[t])->opslaan(file, section);

        for (int t = 0; t < lstUitslag->Items->Count; t++)
                file->WriteString(section, String("Kandi") + t,
                  lstUitslag->Items->Item[t]->Caption + "," + lstUitslag->Items->Item[t]->SubItems->CommaText);
}

void TfrmTest::openen(TIniFile *file, String section) {
        chkExecutie->Checked = (file->ReadString(section, "Executed", "nee") == "ja");

        TStringList *tmp = new TStringList();

        lstUitslag->Items->Clear();

        for (int t = 0; ; t++) {
                String kandi = file->ReadString(section, String("Kandi") + t, "");
                if (kandi == "") break;
                TListItem *newit = lstUitslag->Items->Add();
                tmp->CommaText = kandi;
                newit->Caption = tmp->Strings[0];
                tmp->Delete(0);
                newit->SubItems->AddStrings(tmp);
                while (newit->SubItems->Count < 6) newit->SubItems->Add("");
        }

        tmp->Clear();
        file->ReadSection(section, tmp);
        for (int t = 0; t < tmp->Count; t++) {
                if (tmp->Strings[t].SubString(1,6)!="Vraag:" ||
                    tmp->Strings[t].Pos(":survey") == 0) continue;
                String temp = tmp->Strings[t].SubString(7, tmp->Strings[t].Length());
                temp = temp.SubString(1, temp.Length() - 7);
                if (temp == "") continue;
                addNewQuestion();
                ((TfrmVraag*)questions->Items[questions->Count - 2])->openen(file, section, temp);
        }

        delete tmp;

        reload(frmGeneral, section.SubString(6, section.Length()));

}

int TfrmTest::rightPercentage () {
  String mol = frmGeneral->getMol();
  String uitvaller;
  int aantalvragen = 0, ngoed = 0;

  for (int t = 0; t < lstUitslag->Items->Count; t++) {
    if (lstUitslag->Items->Item[t]->Caption == mol ||
        lstUitslag->Items->Item[t]->SubItems->Strings[1] == "vrijstelling")
      continue;

    if (lstUitslag->Items->Item[t]->SubItems->Strings[2] == "") continue; /* hasn't made test */

    ngoed += aantalGoed (lstUitslag->Items->Item[t]);
    aantalvragen += questions->Count - 1;
  }

  if (aantalvragen == 0) return 100; else return (ngoed * 100) / aantalvragen;
}

void __fastcall TfrmTest::cmdPercentageClick(TObject *Sender)
{
  if (lstUitslag->Items->Count == 0) {
    Application->MessageBox ("Nog geen uitslagen!", "Fout", MB_ICONERROR);
    return;
  }

  Application->MessageBox ((String ("Percentage goed: ") + rightPercentage()).c_str(), "Info", MB_ICONERROR);
}
//---------------------------------------------------------------------------

