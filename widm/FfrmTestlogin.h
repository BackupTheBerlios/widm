//---------------------------------------------------------------------------

class TfrmTestLogin;

#ifndef FfrmTestloginH
#define FfrmTestloginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "FfrmTestwin.h"
//---------------------------------------------------------------------------
class TfrmTestLogin : public TForm
{
__published:	// IDE-managed Components
  TButton *Button1;
  TLabel *Label1;
  TEdit *txtName;
  void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
  TfrmTestwin *parent;
public:		// User declarations
  __fastcall TfrmTestLogin(TComponent* Owner, TfrmTestwin *par);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTestLogin *frmTestLogin;
//---------------------------------------------------------------------------
#endif
