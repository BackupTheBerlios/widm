//---------------------------------------------------------------------------

#ifndef FfrmExecutieH
#define FfrmExecutieH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FfrmTestwin.h"
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfrmExecutie : public TfrmTestwin
{
__published:	// IDE-managed Components
        TLabel *lblPercentage;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall lblPercentageClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmExecutie(TComponent* Owner, String uitv, int percentage = -1);
        void __fastcall onTimered();
        void LoginCallback(String name);
        void showPercentage (int percentage);

        String uitvaller;
        bool done;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmExecutie *frmExecutie;
//---------------------------------------------------------------------------
#endif
