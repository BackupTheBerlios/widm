//---------------------------------------------------------------------------

class TfrmTest;

#ifndef FfrmTestH
#define FfrmTestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <inifiles.hpp>

#include "FfrmGeneral.h"
//---------------------------------------------------------------------------
class TfrmTest : public TFrame
{
__published:	// IDE-managed Components
        TLabel *lblTitel;
        TCheckBox *chkExecutie;
        TPanel *pnlBelow;
        TLabel *Label2;
        TLabel *lblVragen;
        TListView *lstUitslag;
        TCheckBox *chkVrij;
        TLabel *Label4;
        TEdit *txtPas;
        TButton *cmdDeletePers;
        TButton *Button1;
        TButton *Button2;
        TButton *cmdTest;
        TLabel *Label5;
        TLabel *lblStatus;
        void __fastcall lstUitslagClick(TObject *Sender);
        void __fastcall chkVrijClick(TObject *Sender);
        void __fastcall txtPasChange(TObject *Sender);
        void __fastcall cmdDeletePersClick(TObject *Sender);
        void __fastcall cmdTestClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmTest(TComponent* Owner);
        virtual __fastcall ~TfrmTest();
        TfrmGeneral *bla;
        void reload(TfrmGeneral *frm, String name);
        TComponentList *questions;
        void addNewQuestion();
        void __fastcall onVraagResize(TObject *Sender);
        void __fastcall onVraagEdit(TObject *Sender);
        void __fastcall onVraagRemove(TObject *Sender);
        String uitvaller();

        void opslaan(TIniFile *file, String section);
        void openen(TIniFile *file, String section);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTest *frmTest;
//---------------------------------------------------------------------------
#endif
