//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *FillTable;
	TButton *ClearForm;
	TButton *DeleteNote;
	TButton *ClearDB;
	TLabel *Label1;
	TLabel *MiddleNameLabel;
	void __fastcall FillTableClick(TObject *Sender);
	void __fastcall ClearFormClick(TObject *Sender);
	void __fastcall DeleteNoteClick(TObject *Sender);
	void __fastcall ClearDBClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

typedef struct
{
	int ID;
	UnicodeString name;
	UnicodeString surname;
	UnicodeString middleName;
} TreeNodeStruct;

#endif
