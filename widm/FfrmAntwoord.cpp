//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FfrmAntwoord.h"
#include "FfrmVraag.h"
#include "FfrmGeneral.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAntwoord *frmAntwoord;
//---------------------------------------------------------------------------
__fastcall TfrmAntwoord::TfrmAntwoord(TComponent* Owner)
        : TFrame(Owner)
{
        update();

}
//---------------------------------------------------------------------------

void __fastcall TfrmAntwoord::cmdDeleteClick(TObject *Sender)
{
        TfrmVraag *vr = (TfrmVraag *)Parent;
        vr->answerDeletedNotification(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmAntwoord::txtVraagChange(TObject *Sender)
{
        TfrmVraag *vr = (TfrmVraag *)Parent;
        vr->answerChangedNotification(this);

}
//---------------------------------------------------------------------------

void TfrmAntwoord::update() {
        /* initialiseer de namen */
        cboNaam->Items->Clear();
        cboNaam->Items->Add("Mol");
        for (int t = 0; t < frmGeneral->lstKandi->Items->Count; t++)
                cboNaam->Items->Add(frmGeneral->lstKandi->Items->Item[t]->Caption);
}
