//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Uprincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool zz = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
int f = StrToInt(InputBox("La fila", "Por favor introduce la fila", ""));
int c = StrToInt(InputBox("La columna", "Por favor introduce la columna", ""));
int valor= StrToInt(InputBox("el valor", "Por favor introduce el valor", ""));

int e = ma->Elemento(f,c);

ma->poner(f, c,  valor);

pilaD->Meter(e);
pilaF->Meter(f);
pilaC->Meter(c);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
M= new CSmemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
String d = Edit1->Text;
M -> new_espacio(AnsiString(d).c_str());
Edit1->Text=" ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
String p = Edit2->Text;
M->Delete_espacio(StrToInt(AnsiString(p).c_str()));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
ma=new  MatrizDispersa2( M);
pilaF = new pilaM(M);
pilaD = new pilaM(M);
pilaC = new pilaM(M);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
int  v = StrToInt(InputBox("el valor", "nuevo valor por defecto", ""));
ma->Definir_valor_repetido(v);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
int p= StrToInt(InputBox("el id", "Por favor, fila", ""));
int  v= StrToInt(InputBox("el valor", "Por favor, columna", ""));
 ma->dimensionar(p, v);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	ma-> imprimir(Form1->Color,Canvas) ;
	if (zz==false) {
		zz=true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	zz=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	String d=Edit3->Text;
	String p= Edit4->Text;
	Canvas->Brush->Color = clBtnFace;      // eliminar los 2 si no queres que se elimine
	Canvas->FillRect(Canvas->ClipRect);    // la matriz al dibujar la memoria,
	M->ImprimirP_DE_A_A_B(Form1->Color,Canvas,1500,20,StrToInt(d),StrToInt(p));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
if (ma->EsSUDOKU()) {
	 ShowMessage("FELICIDADES HAS RESUELTO EL SUDOKU");
} else{
   ShowMessage("No Esta resuelto ");
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
int v,f,c;
pilaF ->Sacar(f);
pilaD ->Sacar(v);pilaC ->Sacar(c);
int e=ma->Elemento(f,c);
if (v==0) {
	ma->eliminar(e,f,c);
} else {
	ma->poner2(f,c,v);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
int i,j;
  i=1;
  j=1;
int pos = 1;
String Sdk ="123456789456789123789123456214365897365897214897214365531642978642978531978531642" ;

   while (i<= ma->dimension_Fila()) {
   j=1;
	   while (j <= ma->dimension_columna()) {
		  if (pos<=Sdk.Length()) {
			ma->poner(i,j,StrToInt(Sdk[pos]));
		  }

		  pos++; j++;
	   }
	   i++;
   }
}
//---------------------------------------------------------------------------
