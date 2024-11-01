//---------------------------------------------------------------------------
#include "U_Memoria.h"

#ifndef matriz_2NH
#define matriz_2NH
//---------------------------------------------------------------------------
struct NodoF {
    int Fila;
    int SigF; // Direcci�n del nodo que tiene la siguiente fila
    int AntF; // Direcci�n de nodo que tiene la anterior Fila
    int PtrCol; // Direcci�n que tiene los datos de la columna y elemento
};

struct NodoC {
    int Col; // Es el valor de la columna donde est� el elemento
    int Dato; // Es el valor de elemento en la matriz
    int SigCol; // Direcci�n del pr�ximo elemento para otra columna
};

class MatrizDispersa2 {
private:
	int PtrFil; // Direcci�n
	int rep;
	int dimf;
	int dimc;
	String conjunto = "123456789" ;
    CSmemoria* Cm; // Enlace a la memoria

public:
	MatrizDispersa2(CSmemoria* M) ;

	void dimensionar(int df, int dc);
	int dimension_Fila() ;

	int dimension_columna();
	void eliminarSiDiferente(int valor) ;

	void eliminar(int valor,int f, int c) ; //a�adido para retroceder

	void poner(int f, int c, int e) ;
	void poner2(int f, int c, int e) ;
  int buscarC2(int dirF, int c) ;
	int Elemento(int f, int c);
	  int buscarF(int f) ;
	int buscarC(int f, int c) ;
	int buscarColumna(int dirF, int c);
	int buscarFila(int f) ;
	   void Definir_valor_repetido(int valor);
	void imprimir(TColor FormColor, TCanvas *Canvas) ;
	// RELLENAR , VERIFICAR SI PETENECE Y ELIMINAR SI PERTENECE
	void rellenar ();
	bool verificar(int num);
	void EliminarConj(int num);

	// verificacion de si es SUDOKU

	bool EsSUDOKU ();

};
#endif
