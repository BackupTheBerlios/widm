//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FfrmTests.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
//--------------------------------------------------------------------- 
__fastcall TfrmTests::TfrmTests(TComponent *Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TfrmTests::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//--------------------------------------------------------------------- 
