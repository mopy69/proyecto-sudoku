//---------------------------------------------------------------------------

#ifndef Conjunto_MemoriaH
#define Conjunto_MemoriaH
#include "U_Memoria.h"
//---------------------------------------------------------------------------
class ConjuntoM{
private:
	int ptrConjunto;
  CSmemoria *Cm;
  public:
  int longitud;
   ConjuntoM(CSmemoria *L);

   bool vacio();
	bool pertenece (int e);
	void inserta(int e);
	int  ordinal (int e);
	int cardinal();
	void suprime(int e);
	int generarNumeroAleatorio();
	int muestrea();
    void imprimir(TColor FormColor,TCanvas* Canvas);
};
#endif
