//----------------------------------------------------------------------------
#ifndef FfrmTestsH
#define FfrmTestsH
//----------------------------------------------------------------------------
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <StdCtrls.hpp>
//----------------------------------------------------------------------------
class TfrmTests : public TForm
{
__published:
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
public:
	virtual __fastcall TfrmTests(TComponent *Owner);
};
//----------------------------------------------------------------------------
#endif	
