//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unit_klient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tklient *klient;
//---------------------------------------------------------------------------
__fastcall Tklient::Tklient(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tklient::Button1Click(TObject *Sender)
{
  if(ADOTable1->State == dsBrowse)
     ADOTable1->Insert();   
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button2Click(TObject *Sender)
{
  if(ADOTable1->State == dsBrowse)
     ADOTable1->Edit();   
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button3Click(TObject *Sender)
{
  if(ADOTable1->State == dsBrowse)
     if(MessageDlg("������� ������?", mtConfirmation, TMsgDlgButtons() << mbYes , 0))
        ADOTable1->Delete();
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button4Click(TObject *Sender)
{
  if(ADOTable1->State == dsInsert || ADOTable1->State == dsEdit)
     ADOTable1->Post();   
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button5Click(TObject *Sender)
{
  if(ADOTable1->State == dsInsert || ADOTable1->State == dsEdit)
     ADOTable1->Cancel();
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button7Click(TObject *Sender)
{
  ADOTable1->Filtered = false;
  DBGrid1->Visible = true;
  DBGrid1->ReadOnly = true;
  Label1->Visible = false;
  Label2->Visible = false;
  Label3->Visible = false;
  Label4->Visible = false;
  Label5->Visible = false;
  Label6->Visible = false;
  Label7->Visible = false;
  Label8->Visible = false;
  Label9->Visible = false;
  Label10->Visible = false;
  ComboBox1->Visible = false;
  Edit1->Visible = false;
  DBEdit1->Visible = false;
  DBEdit2->Visible = false;
  DBEdit3->Visible = false;
  DBEdit4->Visible = false;
  DBEdit5->Visible = false;
  DBEdit6->Visible = false;
  DBEdit7->Visible = false;
  DBEdit8->Visible = false;
  DBEdit9->Visible = false;
  Button1->Visible = false;
  Button2->Visible = false;
  Button3->Visible = false;
  Button4->Visible = false;
  Button5->Visible = false;
  Button6->Enabled = true;
  Button7->Enabled = false;
  Button8->Enabled = true;
  Button9->Visible = false;
  DBNavigator1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button6Click(TObject *Sender)
{
  ADOTable1->Filtered = false;
  DBGrid1->Visible = false;
  DBGrid1->ReadOnly = false;
  Label1->Visible = true;
  Label2->Visible = true;
  Label3->Visible = true;
  Label4->Visible = true;
  Label5->Visible = true;
  Label6->Visible = true;
  Label7->Visible = true;
  Label8->Visible = true;
  Label9->Visible = true;
  Label10->Visible = false;
  ComboBox1->Visible = false;
  Edit1->Visible = false;
  DBEdit1->Visible = true;
  DBEdit2->Visible = true;
  DBEdit3->Visible = true;
  DBEdit4->Visible = true;
  DBEdit5->Visible = true;
  DBEdit6->Visible = true;
  DBEdit7->Visible = true;
  DBEdit8->Visible = true;
  DBEdit9->Visible = true;
  Button1->Visible = true;
  Button2->Visible = true;
  Button3->Visible = true;
  Button4->Visible = true;
  Button5->Visible = true;
  Button6->Enabled = false;
  Button7->Enabled = true;
  Button8->Enabled = true;
  Button9->Visible = false;
  DBNavigator1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button8Click(TObject *Sender)
{
  DBGrid1->Visible = true;
  DBGrid1->ReadOnly = true;
  Label1->Visible = false;
  Label2->Visible = false;
  Label3->Visible = false;
  Label4->Visible = false;
  Label5->Visible = false;
  Label6->Visible = false;
  Label7->Visible = false;
  Label8->Visible = false;
  Label9->Visible = false;
  Label10->Visible = true;
  ComboBox1->Visible = true;
  Edit1->Visible = true;
  DBEdit1->Visible = false;
  DBEdit2->Visible = false;
  DBEdit3->Visible = false;
  DBEdit4->Visible = false;
  DBEdit5->Visible = false;
  DBEdit6->Visible = false;
  DBEdit7->Visible = false;
  DBEdit8->Visible = false;
  DBEdit9->Visible = false;
  Button1->Visible = false;
  Button2->Visible = false;
  Button3->Visible = false;
  Button4->Visible = false;
  Button5->Visible = false;
  Button6->Enabled = true;
  Button7->Enabled = true;
  Button8->Enabled = false;
  Button9->Visible = true;
  DBNavigator1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tklient::Button9Click(TObject *Sender)
{
  String st;
  String a = Edit1->Text;
  if(a.Length() == 0 || ComboBox1->ItemIndex == -1)
    ShowMessage("�� ������ �������� ������/��� �� ������� ��������");
  else
  {
    switch(ComboBox1->ItemIndex)
    {
      case 0:{st = "Familiya=";
              st += char(39);
              st += a;
              st += char(39);
              break;}
      case 1:{st = "Imya=";
              st += char(39);
              st += a;
              st += char(39);
              break;}
      case 2:{st = "Otchestvo=";
              st += char(39);
              st += a;
              st += char(39);
              break;}
    }
    ADOTable1->Filter = st;
    ADOTable1->Filtered = true;
  }
}
//---------------------------------------------------------------------------

void __fastcall Tklient::FormCreate(TObject *Sender)
{
  String st, st1;
  st = ExtractFilePath(Application->ExeName);
  //ShowMessage(st);
  st1 = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
  st1 += st;
  st1 += "\hotel.mdb;Persist Security Info=False";
  //ShowMessage(st1);
  ADOTable1->ConnectionString = st1;
  ADOTable1->Active = true;
}
//---------------------------------------------------------------------------
