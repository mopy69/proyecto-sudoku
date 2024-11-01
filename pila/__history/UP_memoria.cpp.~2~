//---------------------------------------------------------------------------

#pragma hdrstop

#include "UP_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
pilaM::pilaM() {
	 pe=-1;

// Cm = new CSmemoria();
}
pilaM::pilaM(CSmemoria* m) {
 pe=-1;
 longitud=0;
 Cm= m;
}

bool pilaM::Vacia(){
return (longitud==0) ;
}

void pilaM ::Meter(int e){
int dir=Cm->new_espacio("elemento,sig");
if (dir!=NULO) {
	 Cm->poner_dato(dir,elementNL ,e);
		 Cm->poner_dato(dir, sigNL ,pe) ;
	 pe=dir;

	longitud++;
}
}


void pilaM::Sacar(int& e){
	   if (Vacia()==false) {
	   int z=pe;
			e = Cm->obtenerDato(pe,elementNL) ;
	pe=Cm->obtenerDato(pe, sigNL);
		Cm->Delete_espacio(z);
	longitud--;
	   }

}
int pilaM::cima() {
	if (Vacia()) {
		return -1;
	} else {
		return Cm->obtenerDato(pe,elementNL);
	}
}
 void pilaM::imprimir(TColor FormColor, TCanvas *Canvas){
	 Cm->ImprimirPantalla2(FormColor, Canvas,1150,600);
 }
