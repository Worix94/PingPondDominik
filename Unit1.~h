//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TTlo : public TForm
{
__published:	// IDE-managed Components
        TImage *PaletkaPrawa;
        TImage *PaletkaLewa;
        TTimer *LewoGora;
        TTimer *PrawoGora;
        TTimer *LewoDol;
        TTimer *PrawoDol;
        TImage *Pilka;
        TTimer *PilkaTimer;
        TButton *Button1;
        TEdit *Text1;
        TEdit *Text2;
        TEdit *Text3;
        TButton *Button2;
        void __fastcall LewoGoraTimer(TObject *Sender);
        void __fastcall LewoDolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall PrawoGoraTimer(TObject *Sender);
        void __fastcall PrawoDolTimer(TObject *Sender);
        void __fastcall PilkaTimerTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TTlo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTlo *Tlo;
//---------------------------------------------------------------------------
#endif
