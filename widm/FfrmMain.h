//---------------------------------------------------------------------------

#ifndef FfrmMainH
#define FfrmMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *mnuMain;
        TMenuItem *Bestand1;
        TMenuItem *Nieuwewerkomgeving1;
        TMenuItem *Opslaanwerkomgeving1;
        TMenuItem *Sluitenwerkcomgeving1;
        TMenuItem *N1;
        TMenuItem *Afsluiten1;
        TMenuItem *Opslaanals1;
        TPanel *Panel1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
