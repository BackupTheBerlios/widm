//---------------------------------------------------------------------------

class TfrmGeneral;

#ifndef FfrmGeneralH
#define FfrmGeneralH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "FfrmTest.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmGeneral : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *tsAlgemeen;
        TPanel *Panel1;
        TLabel *Label1;
        TGroupBox *GroupBox1;
        TRadioButton *optAW;
        TRadioButton *optNAW;
        TGroupBox *GroupBox2;
        TListView *lstKandi;
        TCheckBox *chkMol;
        TCheckBox *chkActief;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TTabSheet *tsTests;
        TPanel *Panel2;
        TSplitter *Splitter1;
        TLabel *Label2;
        TButton *Button4;
        TButton *Button5;
        TListView *lstTests;
        TButton *Button6;
        TButton *Button7;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Newproject1;
        TMenuItem *Saveproject1;
        TMenuItem *Saveprojectas1;
        TMenuItem *N1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Openproject1;
        TOpenDialog *dlgOpen;
        TSaveDialog *dlgSave;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall lstKandiSelectItem(TObject *Sender, TListItem *Item, bool Selected);
        void __fastcall chkMolClick(TObject *Sender);
        void __fastcall optAWClick(TObject *Sender);
        void __fastcall optNAWClick(TObject *Sender);
        void __fastcall chkActiefClick(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall lstTestsSelectItem(TObject *Sender,
          TListItem *Item, bool Selected);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall lstTestsChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
        void __fastcall tsTestsEnter(TObject *Sender);
        void __fastcall tsAlgemeenEnter(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Openproject1Click(TObject *Sender);
        void __fastcall Saveproject1Click(TObject *Sender);
        void __fastcall Saveprojectas1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall lstKandiEdited(TObject *Sender, TListItem *Item,
          AnsiString &S);
private:	// User declarations
        void __fastcall setmol(TListItem *item, bool ismol);
public:		// User declarations
        __fastcall TfrmGeneral(TComponent* Owner);
        virtual __fastcall ~TfrmGeneral();
        TStringList *surveys;
        TObjectList *vragen;
        TfrmTest *curTest;
        String getMol();
        void updateQuestionsList();
        void updateSurveyList();
        void checkSurveyValid(String question, TStringList *list);
        String filename;
        void openen();
        void opslaan();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGeneral *frmGeneral;
//---------------------------------------------------------------------------
#define FLAG_MOLE 1
#define FLAG_ACTIVE 2

class Vraag : public TObject {
 public:
  __fastcall Vraag();
  virtual __fastcall ~Vraag();
  String vraag;
  TStringList *antwoorden;
  bool is_survey;
  TStringList *answers;
};

Vraag *hasQuestion(TObjectList *l, String quest);

class KandiData {
 public:
  KandiData();
  ~KandiData();
  int flags;
  TStringList *list; // survey question->answer
};


#endif


