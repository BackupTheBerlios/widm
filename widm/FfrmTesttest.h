//---------------------------------------------------------------------------

#ifndef FfrmTesttestH
#define FfrmTesttestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FfrmTestwin.h"
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "FfrmTest.h"
//---------------------------------------------------------------------------
class TfrmTesttest : public TfrmTestwin
{
__published:	// IDE-managed Components
        void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmTesttest(TComponent* Owner);
  virtual void __fastcall onButtonClick(TObject *Sender);
  virtual void LoginCallback(String name);
  
  TfrmTest *test;
  String mol;
  String aws;
  int curkandi;
  int cur;
  void next();
  KandiData *kandi, *moldat;
  TDateTime begin;
  int ngoed;
  int pasvragen;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTesttest *frmTesttest;
//---------------------------------------------------------------------------
#endif
