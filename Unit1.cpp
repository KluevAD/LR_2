//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FillTableClick(TObject *Sender)
{
    setlocale(LC_ALL, "Russian");

	// Объявляем переменную:
	sqlite3* Database;

	// Открываем базу данных:
	int openResult = sqlite3_open16(L"..\\..\\Database\\sqlite3_db.db", &Database);

	//Если база данных открыта, то выполнить заполнение VST, если нет - вывести код ошибки
	if (openResult == 0)
	{
		const char *errorMsg;
		sqlite3_stmt *pStatement;

		int result = sqlite3_prepare16_v2(Database,L"SELECT * FROM FIO", -1, &pStatement, NULL); // UTF-16

		if(result != SQLITE_OK)
		{
				errorMsg = sqlite3_errmsg(Database);
				printf("DB error %s \n", errorMsg);
		}

		else
		{
			Form1->VirtualStringTree1->Clear();
			Form1->VirtualStringTree1->BeginUpdate();

			while (true)
			{
			result = sqlite3_step(pStatement);
			if(result == SQLITE_DONE) break;

			// Создаем узел
			PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);

			//Заполняем данные узла
			TreeNodeStruct *nodeData = (TreeNodeStruct*)VirtualStringTree1->GetNodeData(entryNode);

			nodeData->ID = sqlite3_column_int(pStatement, 0);
			nodeData->name = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 1));
			nodeData->surname = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 2));
			nodeData->middleName = UnicodeString((wchar_t*)sqlite3_column_text16(pStatement, 3));
			}

		Form1->VirtualStringTree1->EndUpdate();
		}
		// Завершение обработки запроса
		sqlite3_finalize(pStatement);
		sqlite3_close(Database);
	}
	else
	{
		ShowMessage("WriteOpenResult =" +UnicodeString(openResult));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearFormClick(TObject *Sender)
{
    VirtualStringTree1->Clear();
}
//---------------------------------------------------------------------------
