//---------------------------------------------------------------------------

#ifndef C_L_memoriaH
#define C_L_memoriaH
#include "U_Memoria.h"
#include "UCSListas.h"
//---------------------------------------------------------------------------
   class conjuntolista{
	   private:
	   Lista* ls;
	   //listaptr * ls
	   public:
	   conjuntolista(CSmemoria* l);
		 conjuntolista();
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
