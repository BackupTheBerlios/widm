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
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmExecutie(TComponent* Owner, String uitv);
        void __fastcall onTimered();
        void LoginCallback(String name);
        String uitvaller;
        bool done;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmExecutie *frmExecutie;
//---------------------------------------------------------------------------
#endif
