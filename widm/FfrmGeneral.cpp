//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "FfrmGeneral.h"
#include "FfrmTest.h"
#include "FfrmVraag.h"
#include "FfrmAntwoord.h"
#include "FfrmSurvey.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FfrmTest"
#pragma resource "*.dfm"
TfrmGeneral *frmGeneral;

KandiData::KandiData() { list = new TStringList(); flags = 0; }
KandiData::~KandiData() { delete list; }

__fastcall Vraag::Vraag() { antwoorden = new TStringList(); }
__fastcall Vraag::~Vraag() { delete antwoorden; }

//---------------------------------------------------------------------------
__fastcall TfrmGeneral::TfrmGeneral(TComponent* Owner)
        : TForm(Owner)
{
        surveys = new TStringList();
        vragen = new TObjectList();
        curTest = NULL;
}

__fastcall TfrmGeneral::~TfrmGeneral() {
        delete surveys;
        surveys = NULL;
        delete vragen;
        vragen = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::Button2Click(TObject *Sender)
{
        TListItem *item = lstKandi->Items->Add();
        item->Caption = "Nieuwe speler";
        item->SubItems->Add("*");
        item->SubItems->Add("");
//        if (surveys->Count == 0)
//          item->SubItems->Add("n/a");
//        else
          item->SubItems->Add("te doen");
        item->Data = new KandiData();
        lstKandi->Selected = item;
        item->EditCaption();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::lstKandiSelectItem(TObject *Sender,
      TListItem *Item, bool Selected)
{
        KandiData *dat = (KandiData*)Item->Data;
        if (optAW->Checked) {
          if (dat->flags & FLAG_MOLE)
            chkMol->Checked = true;
          else
            chkMol->Checked = false;
        }

        if (dat->flags & FLAG_ACTIVE)
          chkActief->Checked = false;
        else
          chkActief->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::setmol(TListItem *item, bool ismol) {
        if (!item) return;

        if (ismol) {
          for (int t = 0; t < lstKandi->Items->Count; t++) {
            ((KandiData*)lstKandi->Items->Item[t]->Data)->flags &= ~FLAG_MOLE;
            lstKandi->Items->Item[t]->SubItems->Strings[1] = "";
          }
          ((KandiData*)item->Data)->flags |= FLAG_MOLE;
          item->SubItems->Strings[1] = "*";
        } else {
          ((KandiData*)item->Data)->flags &= ~FLAG_MOLE;
          item->SubItems->Strings[1] = "";
        }
}

void __fastcall TfrmGeneral::chkMolClick(TObject *Sender)
{
        if (chkMol->Enabled) setmol(lstKandi->Selected, chkMol->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::optAWClick(TObject *Sender)
{
        lstKandi->Columns->Items[2]->Width = 50;
        lstKandi->Columns->Items[3]->Width = 0;
        chkMol->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::optNAWClick(TObject *Sender)
{
        lstKandi->Columns->Items[2]->Width = 0;
        lstKandi->Columns->Items[3]->Width = 50;

        chkMol->Enabled = false;
        chkMol->Checked = false;

}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::chkActiefClick(TObject *Sender)
{
        TListItem *item = lstKandi->Selected;

        if (chkActief->Checked) {
          ((KandiData*)item->Data)->flags &= ~FLAG_ACTIVE;
          item->SubItems->Strings[0] = "*";
        } else {
          ((KandiData*)item->Data)->flags |= FLAG_ACTIVE;
          item->SubItems->Strings[0] = "";
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::Button3Click(TObject *Sender)
{
        TListItem *item = lstKandi->Selected;
        if (item) lstKandi->Items->Delete(item->Index);
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::Button1Click(TObject *Sender)
{
        if (lstKandi->Items->Count == 0) {
                Application->MessageBox("Geen kandidaten!", "Fout", MB_ICONERROR);
                return;
        };
        randomize();
        int x = random(lstKandi->Items->Count);
        setmol(lstKandi->Items->Item[x], true);
}

void __fastcall TfrmGeneral::Button4Click(TObject *Sender)
{
        TListItem *item = lstKandi->Selected;
        if (item) {
                KandiData *dat = (KandiData *)item->Data;
                dat->list->Clear();
//                if (surveys->Count == 0)
//                  item->SubItems->Strings[2] = "n/a";
//                else
                  item->SubItems->Strings[2] = "te doen";
        }
}

//---------------------------------------------------------------------------




void __fastcall TfrmGeneral::Button6Click(TObject *Sender)
{
        TListItem *item = lstTests->Items->Add();
        TfrmTest *test = new TfrmTest(tsTests);
        item->Caption = "Nieuwe test";
        test->Parent = tsTests;
        test->Name = "";
        item->Data = test;
        lstTests->Selected = item;
        item->EditCaption();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::lstTestsSelectItem(TObject *Sender,
      TListItem *Item, bool Selected)
{
        if (curTest) curTest->Hide();
        curTest = (TfrmTest*)Item->Data;
        if (curTest == NULL) return;
        curTest->Align = alClient;
        curTest->Visible = true;
        curTest->reload(this, Item->Caption);
        curTest->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::Button7Click(TObject *Sender)
{
        TListItem *item = lstTests->Selected;
        if (item) {
                TfrmTest *test = (TfrmTest*)item->Data;
                test->Visible = false;
                test->Parent = NULL;
                tsTests->RemoveControl (test);
                /* TODO: this causes an 'abstract error */
//                delete test;
                curTest = NULL;
                lstTests->Items->Delete(item->Index);
        }

}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::lstTestsChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
        if (Change == ctText && Item == lstTests->Selected)
                curTest->reload(this, Item->Caption);
}
//---------------------------------------------------------------------------


void __fastcall TfrmGeneral::tsTestsEnter(TObject *Sender)
{
        if (curTest) curTest->Hide();
}
//---------------------------------------------------------------------------
Vraag *hasQuestion(TObjectList *l, String quest) {
        for (int t = 0; t < l->Count; t++) {
                Vraag *v = (Vraag *)l->Items[t];
                if (v->vraag == quest) return v;
        }
        return NULL;
}

void TfrmGeneral::updateQuestionsList() {
        if (!vragen) return;
        vragen->Clear();
        TfrmTest *test;
        TfrmVraag *vraag;
        TfrmAntwoord *aw;
        Vraag *vr;
        for (int t = 0; t < lstTests->Items->Count; t++) {
                test = (TfrmTest *)lstTests->Items->Item[t]->Data;
                for (int z = 0; z < test->questions->Count; z++) {
                        vraag = (TfrmVraag *)test->questions->Items[z];
                        if (vraag->cboVraag->Text == "") continue;
                        vr = new Vraag();
                        vr->vraag = vraag->cboVraag->Text;
                        vr->is_survey = vraag->chkSurvey->Checked;
                        for (int x = 0; x < vraag->answers->Count; x++) {
                                aw = (TfrmAntwoord*)vraag->answers->Items[x];
                                if (aw->txtVraag->Text == "") continue;
                                vr->antwoorden->Add(aw->txtVraag->Text + "=" + aw->cboNaam->Text);
                        }
                        if (!hasQuestion(vragen, vr->vraag)) vragen->Add(vr);
                }
        }
}

void TfrmGeneral::updateSurveyList() {
        /* update surveys */
        if (!surveys) return;
        surveys->Clear();
        for (int t = 0; t < vragen->Count; t++) {
                if (((Vraag *)vragen->Items[t])->is_survey)
                        surveys->Add(((Vraag *)vragen->Items[t])->vraag);
        }

        /* for users, remove questions not in the list and update status */
        for (int t = 0; t < lstKandi->Items->Count; t++) {
                KandiData *dat = (KandiData *)lstKandi->Items->Item[t]->Data;
                for (int z = dat->list->Count - 1; z >= 0; z--)
                        if (surveys->IndexOf(dat->list->Names[z]) == -1)
                                dat->list->Delete(z);

//                if (surveys->Count == 0)
//                        lstKandi->Items->Item[t]->SubItems->Strings[2] = "n/a";
                /*else */if (dat->list->Count == surveys->Count)
                        lstKandi->Items->Item[t]->SubItems->Strings[2] = "klaar";
                else
                        lstKandi->Items->Item[t]->SubItems->Strings[2] = "te doen";
        }



}

void TfrmGeneral::checkSurveyValid(String question, TStringList *names) {
        /* check whether everything is done */
        int z;
        for (int t = 0; t < lstKandi->Items->Count; t++) {
                KandiData *dat = (KandiData *)lstKandi->Items->Item[t]->Data;
                for (z = 0; z < dat->list->Count; z++)
                        if (dat->list->Names[z] == question) break;
                if (z == dat->list->Count)
                  if (names->IndexOf(lstKandi->Items->Item[t]->Caption) == -1)
                        names->Add(lstKandi->Items->Item[t]->Caption);
        }
}


void __fastcall TfrmGeneral::tsAlgemeenEnter(TObject *Sender)
{
        updateQuestionsList();
        updateSurveyList();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::About1Click(TObject *Sender)
{
        Application->MessageBox(
                "Wie Is De Mol 2.0\n\n"
                "Executiesoftware voor het spelen van Wie Is De Mol.\n"
                "Copyright (C) Meilof Veeningen, 2004-2005. Voor meer informatie:\n"
                "http://home.wanadoo.nl/meilof/, of mail meilof@wanadoo.nl.\n\n"
                "Dit programma is vrije software verspreid onder de voorwaarden\n"
                "van de GNU General Public License. Dit houdt onder andere in\n"
                "dat de broncode van de software bijgeleverd hoort te zijn. Is\n"
                "dit niet het geval, ga dan naar de homepage of neem contact op\n"
                "met de auteur.", "Over Wie Is De Mol", MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

String TfrmGeneral::getMol() {
        for (int t = 0; t < lstKandi->Items->Count; t++) {
                if (lstKandi->Items->Item[t]->SubItems->Strings[1] != "")
                        return lstKandi->Items->Item[t]->Caption;
        }
        return "";
}

void __fastcall TfrmGeneral::Button5Click(TObject *Sender)
{
        String mol = getMol();
        if (mol == "") {
                Application->MessageBox("Kies eerst een mol!", "Fout", MB_ICONERROR);
                return;
        }
        TfrmSurvey *survey = new TfrmSurvey(this);
        survey->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TfrmGeneral::Openproject1Click(TObject *Sender)
{
        if (filename != "") {
                int ret = Application->MessageBox("Vorig project opslaan?", "Vraag", MB_ICONQUESTION|MB_YESNOCANCEL);
                if (ret == IDOK) opslaan();
                else if (ret == IDCANCEL) return;
        }
        if (dlgOpen->Execute()) {
                filename = dlgOpen->FileName;
                openen();
        }
}
//---------------------------------------------------------------------------

void TfrmGeneral::openen() {
        Caption = "Wie Is De Mol - " + filename;
        TIniFile *file = new TIniFile(filename);
        if (!file) {
                Application->MessageBox("Fout bij openen!", "Fout", MB_ICONERROR);
                return;
        }

        /* data leegmaken */
        surveys->Clear();
        vragen->Clear();
        lstKandi->Items->Clear(); /* TODO: delete kandidata etc */
        lstTests->Items->Clear();
        if (curTest) curTest->Hide(); curTest = NULL;

        /* laad general */
        String tmp;
        TListItem *tli;
        TStringList *li = new TStringList();
        KandiData *dat;
        optAW->Checked = (file->ReadString("General", "Modus", "aw") == "aw");

        for (int t = 0; true; t++) {
             tmp = file->ReadString("General", String("Kandi") + t, "");
             if (tmp == "") break;
             li->CommaText = tmp;
             tli = lstKandi->Items->Add();
             tli->Caption = li->Strings[0];
             li->Delete(0);
             tli->SubItems->AddStrings(li);
             while (tli->SubItems->Count < 3) tli->SubItems->Add("");

             dat = new KandiData();
             dat->flags = file->ReadInteger("General", String("Kandi") + t + ":flags", 0);
             dat->list->CommaText = "\"" + file->ReadString("General", String("Kandi") + t + ":survey", "") + "\"";

             tli->Data = dat;
        }

        /* load tests */
        li->Clear();
        file->ReadSections(li);

        for (int t = 0; t < li->Count; t++) {
                if (li->Strings[t].SubString(1, 5) == "Test:") {
                        TListItem *i = lstTests->Items->Add();
                        TfrmTest *test;
                        i->Caption = li->Strings[t].SubString(6, li->Strings[t].Length());
                        i->Data = test = new TfrmTest(this);
                        test->Parent = tsTests;
                        test->Align = alClient;
                        test->Name = "";
                        test->openen(file, li->Strings[t]);
                        test->Hide();
                }
        }

        delete file;

}

void TfrmGeneral::opslaan() {
        /* save "general" tab */
        Caption = "Wie Is De Mol - " + filename;
        TIniFile *file = new TIniFile(filename);
        if (!file) {
                Application->MessageBox("Fout bij openen!", "Fout", MB_ICONERROR);
                return;
        }

        file->WriteString("General", "Modus", optAW->Checked?"aw":"naw");
        for (int t = 0; t < lstKandi->Items->Count; t++) {
                KandiData *dat = (KandiData *)lstKandi->Items->Item[t]->Data;
                file->WriteString("General", String("Kandi") + t,
                  lstKandi->Items->Item[t]->Caption + "," + lstKandi->Items->Item[t]->SubItems->CommaText);
                file->WriteInteger("General", String("Kandi") + t + ":flags", dat->flags);
                file->WriteString("General", String("Kandi") + t + ":survey", dat->list->CommaText);
        }

        /* save tests */
        for (int t = 0; t < lstTests->Items->Count; t++)
                ((TfrmTest *)lstTests->Items->Item[t]->Data)->opslaan(file, "Test:" + lstTests->Items->Item[t]->Caption);

        file->UpdateFile();
        delete file;
}

void __fastcall TfrmGeneral::Saveproject1Click(TObject *Sender)
{
        if (filename == "") {
                Saveprojectas1Click(Sender);
                return;
        } else {
                opslaan();
        }
}
//---------------------------------------------------------------------------


void __fastcall TfrmGeneral::Saveprojectas1Click(TObject *Sender)
{
        if (dlgSave->Execute()) {
                filename = dlgSave->FileName;
                opslaan();
        }
}
//---------------------------------------------------------------------------


void __fastcall TfrmGeneral::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        int ret = Application->MessageBox("Project bewaren?", "Vraag", MB_ICONQUESTION|MB_YESNOCANCEL);
        if (ret == IDYES) {
                if (filename == "") {
                        Saveprojectas1Click(Sender);
                        return;
                } else {
                        opslaan();
                }
        } else if (ret == IDCANCEL) {
                Action = caNone;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGeneral::lstKandiEdited(TObject *Sender,
      TListItem *Item, AnsiString &S)
{
     if (S == Item->Caption) return;

     for (int t = 0; t < lstKandi->Items->Count; t++) {
       if (lstKandi->Items->Item[t]->Caption == S) {
         Application->MessageBox("Die naam bestaat al!", "Fout!", MB_ICONERROR);
         S = Item->Caption;
         return;
       }
     }
}
//---------------------------------------------------------------------------



