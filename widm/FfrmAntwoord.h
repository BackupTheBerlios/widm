//---------------------------------------------------------------------------


#ifndef FfrmAntwoordH
#define FfrmAntwoordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmAntwoord : public TFrame
{
__published:	// IDE-managed Components
        TButton *cmdDelete;
        TComboBox *cboNaam;
        TEdit *txtVraag;
        void __fastcall cmdDeleteClick(TObject *Sender);
        void __fastcall txtVraagChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmAntwoord(TComponent* Owner);
        void update();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAntwoord *frmAntwoord;
//---------------------------------------------------------------------------
#endif
