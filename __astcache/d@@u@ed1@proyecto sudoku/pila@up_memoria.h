﻿//---------------------------------------------------------------------------

#ifndef UP_memoriaH
#define UP_memoriaH
#include "U_Memoria.h"
//---------------------------------------------------------------------------


typedef int direccion;
	const string datoNL = "elemento,sig";
	const string elementNL = "->elemento";
	const string sigNL = "->sig";
	//static const int MAX= 20;
   //	static const int NULO = -1;
class pilaM{
	private:



	direccion pe;

	CSmemoria* Cm;
	public: 	int longitud;
pilaM();
	pilaM(CSmemoria* m);
	 bool Vacia();
	 void Meter(int e);


  void Sacar(int &e);
  int cima();
 void imprimir(TColor FormColor, TCanvas *Canvas);
};
#endif