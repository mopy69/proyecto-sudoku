//---------------------------------------------------------------------------

#pragma hdrstop

#include "C_L_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
		conjuntolista::conjuntolista(CSmemoria* l){
	  ls=new Lista(l);
	   //ls=new listaptr();

	}

		 conjuntolista::conjuntolista(){
		   CSmemoria* m=new CSmemoria;
		   ls=new Lista(m);
		 }
  bool  conjuntolista::vacio(){
  return ls->vacia();
  }

bool conjuntolista:: pertenece (int e){
 if (!ls->vacia()) {
 int r;
	  int p=ls->primero();
	  while (p!=-1) {
	  r=ls->recupera(p);
		  if (e==r) {
				 return true;
		  } else
		  {
              p=ls->siguiente(p);
          }
      }

 } else {return false;

 }
}
	void conjuntolista:: inserta(int e){
	 if (pertenece(e)==false) {
 				ls->inserta_primero(e);
	 }
}

int conjuntolista:: ordinal (int e){
if (!ls->vacia()) {
 int cont=0;  int ele;
 int p=ls->primero();
 while (p!=NULO)  {
	 cont=cont+1;
	  ele=ls->recupera(e) ;
	  if (e==ele) {
			   return cont;
	  } else {
          p=ls->siguiente(p);
      }
 }




 }

}
int conjuntolista:: cardinal(){
return ls->longitud;
}
	void  conjuntolista:: suprime(int e){
	if (pertenece(e)) {
	  int p=ls->primero();  int ele;
	  int di=-1;
	  while (p!=NULO){
		  ele=ls->recupera(p);
		  if (ele==e) {
			   di=p;
			   break;
		  }
		  p=ls->siguiente(p);
	  }
	  if (di!=-1) {
		  ls->suprime(di);
	  }
	}
	}
	int conjuntolista:: generarNumeroAleatorio(){
		srand(time(0));
			int min=1;
			int max =ls->longitud;
			int num =rand() % (max - min + 1) + min;
			return num;

	}
	int conjuntolista:: muestrea(){
	 int lug= generarNumeroAleatorio();
	 int di=ls->primero();
	 int dirl=-1; int  cont=0;
	 for (int i = 0; i <= ls->longitud; i++) {
		 cont++;
		 if (cont==lug) {
			 dirl=di;
		 }
	 }
     return ls->recupera(dirl);

	}
	void conjuntolista:: imprimir(TColor FormColor,TCanvas* Canvas){

	 ls->imprimir2(FormColor,Canvas,400,380) ;
	}


