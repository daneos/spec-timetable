//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmDialogText.h"
#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDialogText *FormDialogText;
//---------------------------------------------------------------------------
__fastcall TFormDialogText::TFormDialogText(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormDialogText::FormShow(TObject *Sender)
{
	FormGUI->Enabled = false;
        if (FormGUI->dialogResultHasText) {
                Edit1->Text = FormGUI->dialogResultText;
        } else {
                Edit1->Text = "";
        }
        FormGUI->dialogResultHasText = false;
        Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormDialogText::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        FormGUI->dialogResultText = Edit1->Text;
	FormGUI->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TFormDialogText::Button1Click(TObject *Sender)
{
        FormGUI->dialogResultHasText = true;
        FormDialogText->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormDialogText::Button2Click(TObject *Sender)
{
        FormDialogText->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormDialogText::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_RETURN) Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFormDialogText::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_ESCAPE) Button2->Click();
}
//---------------------------------------------------------------------------

