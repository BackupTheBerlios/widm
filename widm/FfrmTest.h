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
        TPanel *pnlBelow;
        TLabel *Label2;
        TLabel *lblVragen;
        TListView *lstUitslag;
        TCheckBox *chkVrij;
        TLabel *Label4;
        TEdit *txtPas;
        TButton *cmdDeletePers;
        TGroupBox *GroupBox1;
        TCheckBox *chkExecutie;
        TLabel *Label5;
        TLabel *lblStatus;
        TLabel *Label1;
        TEdit *txtAantal;
        TButton *cmdTest;
        TButton *Button1;
        TButton *Button2;
        TButton *cmdPercentage;
        TCheckBox *chkPercentage;
        void __fastcall lstUitslagClick(TObject *Sender);
        void __fastcall chkVrijClick(TObject *Sender);
        void __fastcall txtPasChange(TObject *Sender);
        void __fastcall cmdDeletePersClick(TObject *Sender);
        void __fastcall cmdTestClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall cmdPercentageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmTest(TComponent* Owner);
        virtual __fastcall ~TfrmTest();
        void __fastcall onVraagResize(TObject *Sender);
        void __fastcall onVraagEdit(TObject *Sender);
        void __fastcall onVraagRemove(TObject *Sender);

        void reload(TfrmGeneral *frm, String name);
        void addNewQuestion();
        String uitvaller();
        int rightPercentage ();

        void opslaan(TIniFile *file, String section);
        void openen(TIniFile *file, String section);

        TfrmGeneral *bla;
        TComponentList *questions;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTest *frmTest;
//---------------------------------------------------------------------------
#endif
