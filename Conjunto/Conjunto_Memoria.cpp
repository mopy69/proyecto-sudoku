//---------------------------------------------------------------------------

#pragma hdrstop

#include "Conjunto_Memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
  ConjuntoM:: ConjuntoM(CSmemoria *L){
  Cm=L;
  ptrConjunto=NULO;
  longitud=0;
   }
	  bool ConjuntoM::  vacio(){

      return (longitud==0);
	  }
  bool ConjuntoM:: pertenece (int e){
   bool r=false;;
 int pc =ptrConjunto;
	  while (pc!=-1){
		 if (Cm->obtenerDato(pc,"->dato")==e) {
				r=true;
				pc=-1;
		 } else
		 {
			 pc=Cm->obtenerDato(pc,"->sig");
		 }
	  }
	  return r;
}

void ConjuntoM::  inserta(int e){
  if (!pertenece(e)) {
	  int di=Cm->new_espacio("dato,sig") ;
	  if (di!=-1) {
		 Cm->poner_dato(di,"->dato",e);
		 Cm->poner_dato(di,"->sig",ptrConjunto)  ;
		 ptrConjunto=di;
		 longitud=longitud+1;

	  }
  }

}
	int ConjuntoM:: ordinal (int e){

 int pc =ptrConjunto;
	  while (pc!=-1){
		 if (Cm->obtenerDato(pc,"->dato")==e) {
			return Cm->obtenerDato(pc,"->dato");
				pc=-1;
		 } else
		 {
			 pc=Cm->obtenerDato(pc,"->sig");
		 }
	  }
      return NULO;
	}
	 int  ConjuntoM::cardinal(){
	 return longitud;

	 }

		void  ConjuntoM::suprime(int e){
		int di=-1;
		  int pc=ptrConjunto;

              while (pc!=-1){
		 if (Cm->obtenerDato(pc,"->dato")==e) {
				 di=pc;
				pc=-1;
		 } else
		 {
			 pc=Cm->obtenerDato(pc,"->sig");
		 }
	  }
		 longitud--;
		 Cm->Delete_espacio(di);
		}

			int ConjuntoM:: generarNumeroAleatorio(){
			srand(time(0));
			int min=1;
			int max =longitud;
			int num =rand() % (max - min + 1) + min;
			return num;
			}
				int ConjuntoM::muestrea(){
				  if (longitud>0) {
				  int lug= generarNumeroAleatorio();
				  int e;
				   int l=0;
					int pc =ptrConjunto;
					while (pc!=-1){
				   l++;
					if (lug=l) {
						e=Cm->obtenerDato(pc,"->dato") ;
						pc=-1;
					} else {
						pc=Cm->obtenerDato(pc,"->sig") ;
                    }


					}
					return e;
				  }


				}

 void ConjuntoM::imprimir(TColor FormColor,TCanvas* Canvas){
 Cm->ImprimirPantalla(FormColor,Canvas);
 }
