//---------------------------------------------------------------------------

class TfrmTestwin;

#ifndef FfrmTestwinH
#define FfrmTestwinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>

#include "FfrmTestlogin.h"
//---------------------------------------------------------------------------
class TfrmTestwin : public TForm
{
__published:	// IDE-managed Components
  TImage *imgMol;
  TLabel *lblQ;
  TLabel *lblName;
  TImage *imgRed;
  TImage *imgGreen;
  TTimer *tmr;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall tmrTimer(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmTestwin(TComponent* Owner, bool doLogin = true);
  virtual __fastcall ~TfrmTestwin();

  void redScreen(bool leave = false);
  void greenScreen();
  
  void showLogin();
  void closeLogin();

  virtual void __fastcall onButtonClick(TObject *Sender);
  virtual void __fastcall onTimered();
  virtual void LoginCloseCallback();
  virtual void LoginCallback(String name);

  void setvraag(String vraag, TStringList *antwoorden);
  void hidebuttons();

  TButton **buttons;
  TLabel **labels;
  int nitems;
  TfrmTestLogin *login;
};

//---------------------------------------------------------------------------
extern PACKAGE TfrmTestwin *frmTestwin;
//---------------------------------------------------------------------------
#endif
