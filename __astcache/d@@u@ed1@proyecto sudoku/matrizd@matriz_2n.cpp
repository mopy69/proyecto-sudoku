﻿//---------------------------------------------------------------------------
 #include <iostream>
#include <string>
#pragma hdrstop
#include <vector>
#include "Uprincipal.h"
#include "matriz_2N.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	 MatrizDispersa2::MatrizDispersa2(CSmemoria* M) {
		Cm = M;
		PtrFil = NULO;
		dimf = 0;
		dimc = 0;
		rep = 0;
	}
		void MatrizDispersa2::dimensionar(int df, int dc) {
		dimf = df;
		dimc = dc;
	}

	int MatrizDispersa2:: dimension_Fila() {
		return dimf;
	}

	int MatrizDispersa2::dimension_columna() {
		return dimc;
	}

   int MatrizDispersa2::buscarF(int f) {
  int x = PtrFil;
    while (x != NULO) {
        if (Cm->obtenerDato(x, "->fila") == f) {
            return x;
        }
		x = Cm->obtenerDato(x, "->sigF");
	}
    return NULO; // Retorna NULO si no encuentra el nodo
}/*
 void MatrizDispersa2::Definir_valor_repetido(int valor){
	rep=valor;
}  */


void MatrizDispersa2::eliminarSiDiferente(int valor) {
    int dirF = PtrFil;
	int prevF = NULO;

	while (dirF != NULO) {
		int dirC = Cm->obtenerDato(dirF, "->ptrCol");
		int prevC = NULO;

		while (dirC != NULO) {
			if (Cm->obtenerDato(dirC, "->dato") == valor) {
                // Si el valor en la posición actual es diferente al valor de entrada
				int temp = Cm->obtenerDato(dirC, "->sigCol");

				if (prevC != NULO) {
                    // Actualizar el enlace del nodo anterior
					Cm->poner_dato(prevC, "->sigCol", temp);
				} else {
                    // Si el nodo eliminado era el primero de la fila, actualizar el enlace de la fila
					Cm->poner_dato(dirF, "->ptrCol", temp);
                }

				// Eliminar el nodo actual de la memoria
				Cm->Delete_espacio(dirC);

                // Continuar con el siguiente nodo
                dirC = temp;
            } else {
				prevC = dirC;
				dirC = Cm->obtenerDato(dirC, "->sigCol");
            }
        }

        // Si el último nodo de la fila ha sido eliminado, establecer el enlace de la fila en -1
		if (Cm->obtenerDato(dirF, "->ptrCol") == NULO) {
			if (prevF != NULO) {
                // Actualizar el enlace de la fila anterior
				Cm->poner_dato(prevF, "->sigF", Cm->obtenerDato(dirF, "->sigF"));
            } else {
                // Si la fila eliminada era la primera fila, actualizar el enlace de la matriz
				PtrFil = Cm->obtenerDato(dirF, "->sigF");
            }

            // Eliminar la fila actual de la memoria
            Cm->Delete_espacio(dirF);
            dirF = PtrFil; // Reiniciar la búsqueda desde el principio
        } else {
			prevF = dirF;
			dirF = Cm->obtenerDato(dirF, "->antF");
        }
    }
}

void MatrizDispersa2::eliminar(int valor,int f,int c) {
	int dirF = PtrFil;
	int prevF = NULO;
	  bool x=true;
  int fila=  buscarFila(f);
   int columna=buscarColumna( fila,  c);
	while (dirF != NULO and x) {
		int dirC = Cm->obtenerDato(dirF, "->ptrCol");
		int prevC = NULO;
		while (dirC != NULO and x) {
			if (Cm->obtenerDato(dirC, "->dato") == valor and (fila ==dirF ) and ( columna==dirC)) {
				// Si el valor en la posición actual es diferente al valor de entrada
				x=false;
				int temp = Cm->obtenerDato(dirC, "->sigCol");
				if (prevC != NULO) {
					// Actualizar el enlace del nodo anterior
					Cm->poner_dato(prevC, "->sigCol", temp);
				} else {
					// Si el nodo eliminado era el primero de la fila, actualizar el enlace de la fila
					Cm->poner_dato(dirF, "->ptrCol", temp);
                }
				// Eliminar el nodo actual de la memoria
				Cm->Delete_espacio(dirC);
                // Continuar con el siguiente nodo
				dirC = temp;

			} else {
				prevC = dirC;
				dirC = Cm->obtenerDato(dirC, "->sigCol");
			}

        }
        // Si el último nodo de la fila ha sido eliminado, establecer el enlace de la fila en -1
		if (Cm->obtenerDato(dirF, "->ptrCol") == NULO) {
			if (prevF != NULO) {
                // Actualizar el enlace de la fila anterior
				Cm->poner_dato(prevF, "->sigF", Cm->obtenerDato(dirF, "->sigF"));
			} else {
				// Si la fila eliminada era la primera fila, actualizar el enlace de la matriz
				PtrFil = Cm->obtenerDato(dirF, "->antF");
            }
            // Eliminar la fila actual de la memoria
			Cm->Delete_espacio(dirF);
			dirF = PtrFil; // Reiniciar la búsqueda desde el principio

        } else {
			prevF = dirF;
			dirF = Cm->obtenerDato(dirF, "->antF");
		}
	}
}

void MatrizDispersa2::Definir_valor_repetido(int valor){
 if (Cm->Espacio_ocupado()==0) {
	  rep=valor   ;
 }  else{


	// Recorrer todas las filas y columnas
	for (int i = 1; i <= dimf; i++) {
		for (int j = 1; j <= dimc; j++) {
			// Si el valor en la posición actual es diferente al nuevo valor repetido
			if (Elemento(i, j) ==rep) {
				// Guardar el valor en la memoria
				poner2(i, j, Elemento(i, j));
			}
		}
	}
		  eliminarSiDiferente(valor);
	rep = valor;}
}



 int MatrizDispersa2::buscarFila(int f) {
	int x = PtrFil;
	while (x != NULO) {
		if (Cm->obtenerDato(x, "->fila") == f) {
			return x;
		}
		x = Cm->obtenerDato(x, "->antF");
	}
	return NULO; // Retorna NULO si no encuentra el nodo
}
int MatrizDispersa2::buscarC(int f, int c) {

	// Primero obtenemos la dirección de la fila
	int dirF = buscarF(f);
	if (dirF != NULO) {
		// Si la fila existe, buscamos la columna
        int x = Cm->obtenerDato(dirF, "->ptrCol");
        while (x != NULO) {
            if (Cm->obtenerDato(x, "->col") == c) {
                return x;
            }
			x = Cm->obtenerDato(x, "->sigCol");
        }
    }
	return NULO; // Retorna NULO si no encuentra el nodo

// Retorna NULO si no encuentra el nodo
}
//void MatrizDispersa2::poner(int f, int c, int valor) {
// static int lastF = NULO;
//    // Buscar la fila
//	int dirF = buscarFila(f);
//    if (dirF == NULO) {
//        // Si la fila no existe, crear un nuevo nodo para la fila
//        dirF = Cm->new_espacio("fila,sigF,antF,ptrCol");
//        Cm->poner_dato(dirF, "->fila", f);
//		Cm->poner_dato(dirF, "->sigF", PtrFil);
//		  Cm->poner_dato(dirF, "->ptrCol", NULO);
//		   Cm->poner_dato(dirF, "->antF", lastF);
//		PtrFil = dirF;
//		   lastF = dirF; // Actualizar el puntero a la primera fila
//	}
//
//    // Buscar la columna en la fila
//	int dirC = buscarColumna(dirF, c);
//	if (dirC == NULO) {
//        // Si la columna no existe, crear un nuevo nodo para la columna
//        dirC = Cm->new_espacio("col,dato,sigCol");
//		Cm->poner_dato(dirC, "->col", c);
//          Cm->poner_dato(dirC, "->sigCol", NULO);
//        // Enlazar el nuevo nodo de columna en la lista de nodos de columna para esta fila
//		int x = Cm->obtenerDato(dirF, "->ptrCol");
//        if (x != NULO) {
//            Cm->poner_dato(dirC, "->sigCol", x);
//        }
//        Cm->poner_dato(dirF, "->ptrCol", dirC);
//    }
//
//    // Almacenar el valor en el nodo de la columna
//	Cm->poner_dato(dirC, "->dato", valor);
//}
void MatrizDispersa2::poner2(int f, int c, int valor) {
	// Buscar la fila


	int dirF = buscarFila(f);
	if (dirF == NULO) {
		// Si la fila no existe, crear un nuevo nodo para la fila
		dirF = Cm->new_espacio("fila,sigF,antF,ptrCol");
		Cm->poner_dato(dirF, "->fila", f);
		Cm->poner_dato(dirF, "->sigF", NULO);
		Cm->poner_dato(dirF, "->ptrCol", NULO);
		if (PtrFil != NULO) {
			Cm->poner_dato(PtrFil, "->sigF", dirF);
		}
		Cm->poner_dato(dirF, "->antF", PtrFil);
		PtrFil = dirF;
	}
	// Buscar la columna en la fila
	int dirC = buscarColumna(dirF, c);
    if (dirC == NULO) {
        // Si la columna no existe, crear un nuevo nodo para la columna
        dirC = Cm->new_espacio("col,dato,sigCol");
        Cm->poner_dato(dirC, "->col", c);
		Cm->poner_dato(dirC, "->sigCol", NULO);
        // Enlazar el nuevo nodo de columna en la lista de nodos de columna para esta fila
        int x = Cm->obtenerDato(dirF, "->ptrCol");
        if (x != NULO) {
            Cm->poner_dato(dirC, "->sigCol", x);
		}
        Cm->poner_dato(dirF, "->ptrCol", dirC);
    }
    // Almacenar el valor en el nodo de la columna
	Cm->poner_dato(dirC, "->dato", valor);
}


void MatrizDispersa2::poner(int f, int c, int valor) {
	// Buscar la fila
	if (valor!=rep) {


	int dirF = buscarFila(f);
	if (dirF == NULO) {
		// Si la fila no existe, crear un nuevo nodo para la fila
		dirF = Cm->new_espacio("fila,sigF,antF,ptrCol");
		Cm->poner_dato(dirF, "->fila", f);
		Cm->poner_dato(dirF, "->sigF", NULO);
		Cm->poner_dato(dirF, "->ptrCol", NULO);
		if (PtrFil != NULO) {
			Cm->poner_dato(PtrFil, "->sigF", dirF);
		}
		Cm->poner_dato(dirF, "->antF", PtrFil);
		PtrFil = dirF;
	}
	// Buscar la columna en la fila
	int dirC = buscarColumna(dirF, c);
    if (dirC == NULO) {
        // Si la columna no existe, crear un nuevo nodo para la columna
        dirC = Cm->new_espacio("col,dato,sigCol");
        Cm->poner_dato(dirC, "->col", c);
		Cm->poner_dato(dirC, "->sigCol", NULO);
        // Enlazar el nuevo nodo de columna en la lista de nodos de columna para esta fila
        int x = Cm->obtenerDato(dirF, "->ptrCol");
        if (x != NULO) {
            Cm->poner_dato(dirC, "->sigCol", x);
		}
        Cm->poner_dato(dirF, "->ptrCol", dirC);
    }
    // Almacenar el valor en el nodo de la columna
	Cm->poner_dato(dirC, "->dato", valor);
}
	}






 int MatrizDispersa2::buscarC2(int dirF, int c) {
	if (dirF != NULO) {
		int x = Cm->obtenerDato(dirF, "->PtrCol");
		while (x != NULO) {
			if (Cm->obtenerDato(x, "->Col") == c) {
				return x;
			}
			x = Cm->obtenerDato(x, "->SigCol");
		}
	}
	return NULO; // Retorna NULO si no encuentra el nodo
}
int MatrizDispersa2::buscarColumna(int dirF, int c) {
    if (dirF != NULO) {
		int x = Cm->obtenerDato(dirF, "->ptrCol");
        while (x != NULO) {
            if (Cm->obtenerDato(x, "->col") == c) {
                return x;
            }
            int next = Cm->obtenerDato(x, "->sigCol");
            if (next == x) {  // Evitar bucles infinitos
                break;
            }
            x = next;
		}
    }
    return NULO;  // Retorna NULO si no encuentra el nodo
}


int MatrizDispersa2::Elemento(int f, int c) {
    // Buscar el nodo correspondiente a la fila y columna
int dirF = buscarFila(f);
	if (dirF == NULO) {
		// Si la fila no existe, devolver el valor de rep
		return rep;
    }

	int dirC = buscarColumna(dirF, c);
    if (dirC == NULO) {
        // Si la columna no existe, devolver el valor de rep
        return rep;
    }

	// Si el nodo existe, devolver su valor
	return Cm->obtenerDato(dirC, "->dato");
}





void MatrizDispersa2::imprimir(TColor FormColor, TCanvas *Canvas) {
	// Obtén las dimensiones del Canvas
	int canvasWidth = Canvas->ClipRect.Width();
    int canvasHeight = Canvas->ClipRect.Height();

	// Calcula el tamaño de cada celda de la matriz en el Canvas
	int cellWidth = 55;
	int cellHeight = 55;

    // Calcula el desplazamiento para centrar la matriz en el Canvas
	int offsetX = (canvasWidth - dimc * cellWidth) / 2;
	int offsetY = (canvasHeight - dimf * cellHeight) / 2;

    // Asegúrate de que el Canvas esté limpio
   // Canvas->Brush->Color = FormColor;
   // Canvas->FillRect(TRect(0, 0, canvasWidth, canvasHeight));

	// Cambia el color del pincel para dibujar la matriz
	Canvas->Pen->Color = clBlack; // Solo cambia el color del lápiz, no el del pincel

	// Recorre la matriz y dibuja cada celda
	for (int i = 1; i <= dimf; i++) {
		for (int j = 1; j <= dimc; j++) {
			// Calcula la posición de la celda
			int x = offsetX + (j - 1) * cellWidth;
			int y = offsetY + (i - 1) * cellHeight;

			// Dibuja el recuadro de la celda y rellena del color que elijas
			if ((j>3) && (j<=6) || (i>3) &&(i<=6)  ){
			  Canvas->Brush->Color =clSilver;
			} else {
			   Canvas->Brush->Color =clYellow;
			}
            if ((j>3) && (j<=6) && (i>3) &&(i<=6)  ){
			  Canvas->Brush->Color =clYellow;
			}

			Canvas->Pen->Color = clBlack;
			Canvas->Rectangle(x, y, x + cellWidth, y + cellHeight);

			// Dibuja el valor de la celda
			int valor = Elemento(i, j);
			Canvas->Font->Color = clBlack; // Cambia el color del texto a negro
			Canvas->TextOutW(x + cellWidth / 2, y -10+ cellHeight / 2, IntToStr(valor));
		}
	}
}
	void MatrizDispersa2::rellenar (){
			conjunto="123456789";
	}
	bool MatrizDispersa2::verificar(int num){
	 return conjunto.Pos(IntToStr(num))> 0;
	}

   void MatrizDispersa2::EliminarConj(int num){
	int pos =1;
	String aux = "";
	aux=conjunto;
	int x = StrToInt(aux);

	aux="";
			  while ( pos <= conjunto.Length()){
				  if (num == StrToInt(conjunto[pos])) {

				  }  else   {
					aux= aux + conjunto[pos];

				  }
				  pos++;
			  }
	  conjunto=aux;


   }

	bool MatrizDispersa2::EsSUDOKU() {
	  int num = Elemento(1,1);
	  int fila=1;
	  int columna=1;
	  int n = 0;
	  int m = 0;
	  int distribucion = 1;
	  int cuadro =1;
	  bool verificado = false;
	  if((dimf==9)&&(dimc==9)) {
		verificado = !verificado;
	  }
	  while ((distribucion<=3) && (verificado)) {
		  while ((cuadro<=3) && (verificado)){
			while ((fila + n <= n + 3) && (verificado) && (n+3 <= dimf ))   {
			   while ((columna + m <= m + 3) && (verificado) && (m+3 <= dimc)){
				  if (verificar(Elemento(fila+n,columna+m))) {
					   EliminarConj(Elemento(fila+n,columna+m)) ;
				  }else{
					  verificado=false;
				  }
				  columna ++;
			   }
			  fila++; columna=1;
			}
			rellenar();  fila=1;    n=n+3;    cuadro++;
		  }

		  m=m+3;   columna=1;    cuadro=1;  distribucion++;
	  }

	  // verificando todas las filas
	  rellenar();
	  fila =1;
	  columna = 1;

	  while ((fila <= dimf ) && verificado ) {
		  while ((columna<= dimc) && (verificado)){
			 if (verificar(Elemento(fila,columna))) {
			   EliminarConj(Elemento(fila,columna)) ;
			 }else{
			  verificado=false;
			 }
			  columna ++;
		  }
		  fila++; columna=1;  rellenar();
	  }
		// verificando columnas
        rellenar();
         fila =1;
	  columna = 1;

		 while ((columna <= dimc ) && verificado ) {
		  while ((fila <= dimf) && (verificado)){
			 if (verificar(Elemento(fila,columna))) {
			   EliminarConj(Elemento(fila,columna)) ;
			 }else{
			  verificado=false;
			 }
			  fila ++;
		  }
		  columna++; fila=1;    rellenar();
	  }

	   //retornando verificado

	   return verificado;
	}
