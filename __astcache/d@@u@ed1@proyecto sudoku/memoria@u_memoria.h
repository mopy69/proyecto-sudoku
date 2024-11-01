﻿//---------------------------------------------------------------------------

#ifndef U_MemoriaH
#define U_MemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <tchar.h>
#include <string>
#include <iomanip>
#include <Graphics.hpp>
using namespace std;
const int TamanoCelda = 20;
const int TamanoCeldaX = 70;
const int TamanoCeldaY = 20;

const int MAX= 999;
const int NULO = -1;
struct NodoMem {
  int dato;
  string id;
  int link;
};

class CSmemoria{
	private:

	   NodoMem* getMEM() { return mem; }

	NodoMem* mem;
	int libre;


	public:
	CSmemoria();
     int getLibre() {
		return libre;
	}

	int new_espacio(string cadena);
	void Delete_espacio(int dir);
	void poner_dato(int dir ,string cadena_id,int valor);
	int obtenerDato(int dir, string id);
	int Espacio_Disponible();
	int Espacio_ocupado();
	bool dir_libre(int dir);
	void ImprimirPantalla(TColor FormColor, TCanvas *Canvas);
	void ImprimirPantalla2(TColor FormColor, TCanvas *Canvas,int posX,int posY);
	void ImprimirP_DE_A_A_B(TColor FormColor, TCanvas *Canvas,int posX,int posY,int a , int b);
    void ImprimirDireccion(int d,TColor FormColor, TCanvas *Canvas,int posX,int posY);
};
#endif
