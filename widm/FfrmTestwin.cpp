//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "FfrmTestwin.h"
#include "FfrmTestlogin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTestwin *frmTestwin;
//---------------------------------------------------------------------------
__fastcall TfrmTestwin::TfrmTestwin(TComponent* Owner)
  : TForm(Owner)
{
  login = new TfrmTestLogin(this, this);
}

__fastcall TfrmTestwin::~TfrmTestwin() {
  if (buttons) free(buttons);
  if (labels) free(labels);
  delete login;
}

bool row2(int width, int height, int n) {
  if (216 + 40 * n > height) return true; else return false;
}

int basex(int width, int height, int n) {
  if (row2(width, height, n))
    return 176 + 40*n - ((height - 216)/40*40 + 40);
  else
    return 176 + 40*n;
}

int basey(int width, int height, int n) {
  if (row2(width, height, n)) return (width / 2) + 32; else return 32;
}

void TfrmTestwin::hidebuttons() {
  int t;
  if (buttons) {
    for (t = 0; t < nitems; t++) {
      buttons[t]->Hide();
      labels[t]->Hide();
    }
  }
}

void TfrmTestwin::setvraag(String vraag, TStringList *list) {
  int t;
  imgMol->Visible = true;
  lblQ->Visible = true;
  hidebuttons();
  lblQ->Caption = vraag;
  if (list->Count > nitems) {
    buttons = (TButton**)realloc(buttons, list->Count * sizeof(TButton *));
    labels = (TLabel**)realloc(labels, list->Count * sizeof(TLabel *));
    for (t = nitems; t < list->Count; t++) {
      /* button */
      buttons[t] = new TButton(this);
      buttons[t]->Left = basey(ClientWidth, ClientHeight, t);
      buttons[t]->Top = basex(ClientWidth, ClientHeight, t);
      buttons[t]->Width = 32;
      buttons[t]->Height = 32;
      buttons[t]->Parent = this;
      buttons[t]->Tag = t;
      buttons[t]->OnClick = onButtonClick;
      /* label */
      labels[t] = new TLabel(this);
      labels[t]->Left = basey(ClientWidth, ClientHeight, t) + 40;
      labels[t]->Top = basex(ClientWidth, ClientHeight, t);
      labels[t]->Font->Name = "Comic Sans MS";
      labels[t]->Font->Size = 16;
      labels[t]->Font->Color = clYellow;
      labels[t]->AutoSize = true;
      labels[t]->Parent = this;
    }
    nitems = list->Count;
  }
  for (t = 0; t < list->Count; t++) {
    /* button */
    buttons[t]->Show();
    /* label */
    labels[t]->Caption = list->Strings[t];
    labels[t]->Show();
  }
  delete list;
}

void __fastcall TfrmTestwin::onButtonClick(TObject *Sender)
{
//  TButton *button = (TButton*)Sender;
//  if (labels[button->Tag]->Caption == "Pas deze vraag") n_pasvragen--;
//  test->feed(labels[button->Tag]->Caption.c_str());
//  test->cur++;
//  if (test->cur >= test->questions->Count) {
//    TDateTime diff = Time() - begin;
//    unsigned short hour, min, sec, msec;
//    DecodeTime(diff, hour, min, sec, msec);
//    if (name != "Test") test->write(hour * 8600000 + min * 60000 + sec * 1000 + msec);
//    hidebuttons();
//    test->cur = 0;
//    frmLogin->txtName->Text = "";
//    frmLogin->ShowModal();
//    return;
//  }
//  loadtest();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTestwin::FormCreate(TObject *Sender)
{
  BorderStyle = bsNone; // remove borders and titlebar
  WindowState = wsMaximized; // go fullscreen

}
//---------------------------------------------------------------------------

void __fastcall TfrmTestwin::FormShow(TObject *Sender)
{
  buttons = NULL;
  labels = NULL;
  nitems = 0;
  
}
//---------------------------------------------------------------------------

void TfrmTestwin::LoginCallback(String naam) {
//  if (name_set(txtName->Text)) {
//    if (FileExists(frmTest->file.SubString(1, frmTest->file.Length() - 4) + name_c + ".txt")) {
//      Application->MessageBox("You already did this test!", "Error", MB_ICONERROR);
//      return;
//    }
//    /* get the number of pass questions */
//    TIniFile *f = new TIniFile(frmTest->file.SubString(1, strlen(DIR)) + "vrij" + frmTest->file.SubString(strlen(DIR) + 1, frmTest->file.Length() - strlen(DIR)));
//    frmTest->n_pasvragen = f->ReadInteger("Pasvragen", name, 0);
//    delete f;
//  } else if (txtName->Text == "Test") {
//    name = "Test";
//    frmTest->n_pasvragen = 0;
//  } else return;

//  Close();
//  frmTest->lblName->Caption = name;
//  frmTest->imgMol->Visible = true;
//  frmTest->lblQ->Visible = true;
//  frmTest->lblName->Visible = true;
//  frmTest->loadtest();
}

void TfrmTestwin::LoginCloseCallback() {
        closeLogin();
        Close();
}

void __fastcall TfrmTestwin::onTimered() {
  tmr->Enabled = false;
}

void __fastcall TfrmTestwin::tmrTimer(TObject *Sender)
{
  tmr->Enabled = false;
  imgRed->Visible = false;
  imgGreen->Visible = false;
  onTimered();
}
//---------------------------------------------------------------------------

void TfrmTestwin::redScreen(bool leave) {
    hidebuttons();

    imgMol->Visible = false;
    lblQ->Visible = false;

    imgRed->Visible = true;
    if (!leave) tmr->Enabled = true;
}

void TfrmTestwin::greenScreen() {
    hidebuttons();

    imgMol->Visible = false;
    lblQ->Visible = false;

    imgGreen->Visible = true;
    tmr->Enabled = true;
}

void TfrmTestwin::showLogin() {
    login->txtName->Text = "";
    login->ShowModal();
}

void TfrmTestwin::closeLogin() {
    login->Close();
}
void __fastcall TfrmTestwin::FormActivate(TObject *Sender)
{
  showLogin();

}
//---------------------------------------------------------------------------

