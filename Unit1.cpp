//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTlo *Tlo;
int x=8,y=-5;
//---------------------------------------------------------------------------
__fastcall TTlo::TTlo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TTlo::LewoGoraTimer(TObject *Sender)
{
        if(PaletkaLewa->Top>0)PaletkaLewa->Top-= 10;
}
//---------------------------------------------------------------------------

void __fastcall TTlo::LewoDolTimer(TObject *Sender)
{
        if(PaletkaLewa->Top+PaletkaLewa->Height < Tlo->Height-30) PaletkaLewa->Top += 10;
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
       if(PaletkaPrawa->Top>0)PaletkaPrawa->Top-= 10;
}
//---------------------------------------------------------------------------
void __fastcall TTlo::PrawoDolTimer(TObject *Sender)
{
      if(PaletkaPrawa->Top+PaletkaPrawa->Height < Tlo->Height-30) PaletkaPrawa->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TTlo::PilkaTimerTimer(TObject *Sender)
{
        Pilka->Left+= -x;
        Pilka->Top+= y;

        if(Pilka->Top-5<0) y=-y;
        if(Pilka->Top+Pilka->Height+25>Tlo->Height) y=-y;

        if(Pilka->Left<=PaletkaLewa->Left+PaletkaLewa->Width    &&
        Pilka->Top+Pilka->Height/2>=PaletkaLewa->Top            &&
        Pilka->Top-Pilka->Height/2<=PaletkaLewa->Top+PaletkaLewa->Height)
        {
        x=-x;
        }
        if(Pilka->Left+Pilka->Width>=PaletkaPrawa->Left                    &&
        Pilka->Top+Pilka->Height/2>=PaletkaPrawa->Top                       &&
        Pilka->Top-Pilka->Height/2<=PaletkaPrawa->Top+PaletkaPrawa->Height)
        {
        x=-x;
        }
}
//---------------------------------------------------------------------------
