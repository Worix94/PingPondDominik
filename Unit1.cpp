//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTlo *Tlo;
int x=8,y=-5;
int ilosc_odbic=0;
int punkty_lewy=0;
int punkty_prawy=0;
//---------------------------------------------------------------------------
__fastcall TTlo::TTlo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TTlo::LewoGoraTimer(TObject *Sender)
{
        if(PaletkaLewa->Top>5)PaletkaLewa->Top-= 10;
}
//---------------------------------------------------------------------------

void __fastcall TTlo::LewoDolTimer(TObject *Sender)
{
        if(PaletkaLewa->Top+PaletkaLewa->Height < Tlo->Height-40) PaletkaLewa->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TTlo::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key == 0x41) LewoGora->Enabled = true;
      if (Key == 0x5A) LewoDol->Enabled = true;
      if (Key == VK_UP) PrawoGora->Enabled = true;
      if (Key == VK_DOWN) PrawoDol->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TTlo::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key == 0x41) LewoGora->Enabled = false;
      if (Key == 0x5A) LewoDol->Enabled = false;
      if (Key == VK_UP) PrawoGora->Enabled = false;
      if (Key == VK_DOWN) PrawoDol->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TTlo::PrawoGoraTimer(TObject *Sender)
{
       if(PaletkaPrawa->Top>5)PaletkaPrawa->Top-= 10;
}
//---------------------------------------------------------------------------
void __fastcall TTlo::PrawoDolTimer(TObject *Sender)
{
      if(PaletkaPrawa->Top+PaletkaPrawa->Height < Tlo->Height-40) PaletkaPrawa->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TTlo::PilkaTimerTimer(TObject *Sender)
{
        Pilka->Left+= -x;
        Pilka->Top+= y;

        if(Pilka->Top-5<0) y=-y;
        if(Pilka->Top+Pilka->Height+25>Tlo->Height) y=-y;

        if(Pilka->Left<=PaletkaLewa->Left+PaletkaLewa->Width    &&
        Pilka->Top+Pilka->Height/2>=PaletkaLewa->Top*0.75            &&
        Pilka->Top-Pilka->Height/2<=(PaletkaLewa->Top+PaletkaLewa->Height)*0.75)
        {
        ilosc_odbic++;
        x=-1.2*x;
        y=1.2*y;
        }
        else if(Pilka->Left+Pilka->Width>=PaletkaPrawa->Left                    &&
        Pilka->Top+Pilka->Height/2>=PaletkaPrawa->Top*0.75                     &&
        Pilka->Top-Pilka->Height/2<=(PaletkaPrawa->Top+PaletkaPrawa->Height)*0.75 )
        {
        ilosc_odbic++;
        x=-1.2*x;
        y=1.2*y;
        }
        else if(Pilka->Left<=PaletkaLewa->Left+PaletkaLewa->Width    &&
        Pilka->Top+Pilka->Height/2>=PaletkaLewa->Top                 &&
        Pilka->Top-Pilka->Height/2<=PaletkaLewa->Top+PaletkaLewa->Height)
        {
        ilosc_odbic++;
        x=-x;
        }
        else if(Pilka->Left+Pilka->Width>=PaletkaPrawa->Left                    &&
        Pilka->Top+Pilka->Height/2>=PaletkaPrawa->Top                       &&
        Pilka->Top-Pilka->Height/2<=PaletkaPrawa->Top+PaletkaPrawa->Height)
        {
        ilosc_odbic++;
        x=-x;
        }
        if(Pilka->Left < PaletkaLewa->Left)
        {
                punkty_prawy++;
                PilkaTimer->Enabled = false;
                Pilka->Visible = false;
                PaletkaLewa->Enabled = false;
                PaletkaPrawa->Enabled = false;
                Text1->Text = "Punkt dla gracza prawego >";
                Text1->Visible = true;
                Text2->Text = IntToStr(punkty_lewy) + ":" + IntToStr(punkty_prawy);
                Text2->Visible = true;
                Text3->Text = "Ilosc odbic: "+IntToStr(ilosc_odbic);
                Text3->Visible = true;
                Button1->Visible = true;
                Button2->Visible = true;
                Tlo->BorderStyle =bsSizeable;

        }
        if(Pilka->Left+Pilka->Width > PaletkaPrawa->Left+ PaletkaPrawa->Width)
        {
                 punkty_lewy++;
                PilkaTimer->Enabled = false;
                Pilka->Visible = false;
                PaletkaLewa->Enabled = false;
                PaletkaPrawa->Enabled = false;
                Text1->Text = "Punkt dla gracza lewego <";
                Text1->Visible = true;
                Text2->Text = IntToStr(punkty_lewy) + ":" + IntToStr(punkty_prawy);
                Text2->Visible = true;
                Text3->Text = "Ilosc odbic: "+IntToStr(ilosc_odbic);
                Text3->Visible = true;
                Button1->Visible = true;
                Button2->Visible = true;
                Tlo->BorderStyle =bsSizeable;
        }

}
//---------------------------------------------------------------------------
void __fastcall TTlo::Button1Click(TObject *Sender)
{
        Pilka->Left=440;
        Pilka->Top=150;
        x=8;
        y=5;
        Pilka->Visible = true;
        PilkaTimer->Enabled = true;
        PaletkaLewa->Enabled = true;
        PaletkaPrawa->Enabled = true;
        Button1->Visible = false;
        Button2->Visible = false;
        Text1->Visible = false;
        Text2->Visible = false;
        Text3->Visible = false;
        ilosc_odbic=0;
        punkty_prawy=0;
        punkty_lewy=0;

        PaletkaPrawa->Left = Tlo->Width-70;
        Tlo->BorderStyle =bsDialog;

}
//---------------------------------------------------------------------------

void __fastcall TTlo::Button2Click(TObject *Sender)
{
 Pilka->Left=440;
        Pilka->Top=150;
        x=8;
        y=5;
        Pilka->Visible = true;
        PilkaTimer->Enabled = true;
        PaletkaLewa->Enabled = true;
        PaletkaPrawa->Enabled = true;
        Button1->Visible = false;
        Button2->Visible = false;
        Text1->Visible = false;
        Text2->Visible = false;
        Text3->Visible = false;
        ilosc_odbic=0;

        PaletkaPrawa->Left = Tlo->Width-70;
        Tlo->BorderStyle =bsDialog;

}
//---------------------------------------------------------------------------



void __fastcall TTlo::FormCreate(TObject *Sender)
{
    Application->MessageBox("Witaj w grze ping pong.\n\n"
    "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.\n"
    "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³. \n\n"
    "Dla urozmaicenia zabawy:\n"
    "Kiedy odbijesz pi³kê na srodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyspieszy.\n"
    "Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza siê.\n"
    "Mo¿esz dowolnie zmienia pole gry.\n\n"
    "Mi³ej zabawy!", MB_OK);
}
//---------------------------------------------------------------------------

