//---------------------------------------------------------------------------


#ifndef FfrmVraagH
#define FfrmVraagH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <inifiles.hpp>
//---------------------------------------------------------------------------
class TfrmVraag : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button1;
        TCheckBox *chkSurvey;
        TComboBox *cboVraag;
        TLabel *lblAw;
        void __fastcall cboVraagChange(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmVraag(TComponent* Owner);
        virtual __fastcall ~TfrmVraag();
        void reload();
        void addNewAnswer();
        TComponentList *answers;
        void answerChangedNotification(TComponent* Owner);
        void answerDeletedNotification(TComponent* Owner);
        void opslaan(TIniFile *file, String section);
        void openen(TIniFile *file, String section, String vraag);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmVraag *frmVraag;
//---------------------------------------------------------------------------
#endif
