//---------------------------------------------------------------------------

#ifndef FfrmSurveyH
#define FfrmSurveyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FfrmTestwin.h"
#include "FfrmGeneral.h"
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfrmSurvey : public TfrmTestwin
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
  __fastcall TfrmSurvey(TComponent* Owner);
  virtual void __fastcall onButtonClick(TObject *Sender);
  virtual void __fastcall onTimered();
  virtual void LoginCallback(String name);
  String mol;
  int curkandi;
  int cur;
  void next();
  KandiData *kandi;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSurvey *frmSurvey;
//---------------------------------------------------------------------------
#endif
