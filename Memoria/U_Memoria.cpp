//---------------------------------------------------------------------------

#pragma hdrstop

#include "U_Memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	int Numero_Ids(string cadena){
	int cantidad=0;
	for (int i =0; i < cadena.length(); i++) {
		if (cadena[i]==',') {
		  cantidad++;
		}
	}
	if(!cadena.empty()){cantidad+=1;}
	else{ cantidad+=0;}
	return cantidad;
	}

	string Obtener_Id(string cadena, int n){
	 string palabra="";
	 int contador=0;
	 int i=0;
	 while ((contador<n-1) && (i<cadena.length()))
	 { if (cadena.at(i)==',') {
		   contador++;
		   cadena=cadena.substr(i+1,cadena.length()-cadena.substr(0,i).length());
		   i=-1;
	   }
	   i++;
	 }
	 i=0;
	 while (cadena[i]!=',' && i<cadena.length())
	 {
	 i++;
	 }
	 palabra=cadena.substr(0,i);
	 return palabra;

	}

	void eliminarflecha(string &cadena){
	int pos=0;
		if (cadena!="") {
		  while (cadena[pos]!='-' && cadena[pos+1]!='>')
			  {
				pos++;
			  }
		  cadena=cadena.substr(pos+2,cadena.length()-cadena.substr(0,pos+1).length());
		}

	}

	char Memoria(int i){
	string M="MEMORIA";
	char aux;
	if ((i>=0) && (i<M.length())) {
		aux=M.at(i);
	}else{
	  aux=' ';
	}
	return aux;
	}



	CSmemoria::CSmemoria(){
	  mem = new NodoMem[MAX];
	  for (int i = 0; i < MAX; i++) {
		mem[i].link= i+1;
		mem[i].dato=0;
	  }
	  mem[MAX - 1].link=-1;
	  libre = 0;
	}

	int CSmemoria::new_espacio(string cadena){
	int cant = Numero_Ids(cadena);
	int dir=libre;
	int d=libre;
	for (int i = 1; i <= cant-1; i++) {
		mem[d].id=Obtener_Id(cadena,i);
		d=mem[d].link;
	}
	libre=mem[d].link;
	mem[d].link=-1;
	mem[d].id=Obtener_Id(cadena,cant);
	return dir;
	}

	void CSmemoria::Delete_espacio(int dir){  // si pide dejar en la memoria al eliminar
	int x = dir;                              //comemtar las lineas que dice que hace
	while (mem[x].link != -1)
		{  // mem[x].id="";    //borra el id de la memoria
			//mem[x].dato=0;   // pone en 0 el dato
		x=mem[x].link;
		}
	   // mem[x].id="";   // borra el id
	   //	mem[x].dato=0; //pone en 0
	mem[x].link=libre;

	libre=dir;
	}

	int CSmemoria::Espacio_Disponible(){
	// Cantidad de memoria disponible
	int x = libre;
	int c = 0; // CONTADOR
	while (x != -1)
	{
	c++;
	x=mem[x].link;
	}
	// RETORNAR C
	return c;
	}
	int CSmemoria::Espacio_ocupado(){
	return MAX - Espacio_Disponible();
	}

	bool CSmemoria::dir_libre(int dir){
	int x =libre;
	bool c=false;
		while ((x!= NULO) && (c==false)){
		if (x==dir) {
			c=true;
		}
		x=mem[x].link;
		}
	 return c;
	}

	void CSmemoria::poner_dato(int dir, string id, int valor){
	int z=dir;
	eliminarflecha(id);
		while (z!=NULO){
		if (mem[z].id==id) {
			mem[z].dato=valor;
		}
		z=mem[z].link;
		}

	}

	int CSmemoria::obtenerDato(int dir, string id){
	int z=dir;
	bool ex=false;
	eliminarflecha(id);
	while (z!=NULO){
	if (mem[z].id==id) {
	 return mem[z].dato;
	}
	z=mem[z].link;
	}

	}


     void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	   TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
		TColor oldPenColor = Canvas->Pen->Color; // Guarda el color original del l�piz
		Canvas->Brush->Color = color;
		Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro
	   //	Canvas->Rectangle(rect.Left, rect.Top, rect.Right, rect.Bottom); // Dibuja un rect�ngulo
		Canvas->Pen->Color = oldPenColor; // Restablece el color del l�piz al color original
		Canvas->TextOutW(posX+3,posY+3,cad);
	}

void CSmemoria::ImprimirPantalla(TColor FormColor, TCanvas *Canvas){

int posX = 1200;
	int posY =30;
	int auxX = posX;
	int auxY = posY;
	bool b = true;
	   int y = 30;int rowHeight = 20;  Canvas->Font->Size =8;
	//DIBUJAMOS CABECERA
	Pintado(posX,posY,"dir",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY,"dato",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY,"id",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY,"link",FormColor,Canvas);
	posX= auxX;
	posY+= TamanoCeldaY;
	Canvas->Font->Size =7;
	int ux;
	//CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	for(int i = 0; i <=5+Espacio_ocupado(); i++){

	 //	if ( (mem[i].dato ==0 && mem[i].id == "")) {

					if (mem[i].link!=libre) {


			  //	Canvas->Brush->Color =clLime;
				  Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro
				  //	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
					Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
							posX+=TamanoCeldaX;
					Canvas->Brush->Color =clYellow; // poner demas celdas en amarillo
					Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro



						Canvas->Brush->Color =  clAqua ;
					Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
					Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));

						 if (mem[i].dato != 0 || mem[i].id != "") {  Canvas->Pen->Width = 2;
							  Canvas->Pen->Color = clRed;
						 Canvas->MoveTo(posX,posY+3);
						 Canvas->LineTo(posX,posY + TamanoCeldaY-3);
						Canvas->Pen->Color = clBlack;    Canvas->Pen->Width = 1;
						 }



							posX+=TamanoCeldaX;

                              	Canvas->Brush->Color =clYellow;
					   Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
					Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());

							 if (mem[i].dato != 0 || mem[i].id != "") {
							 Canvas->Pen->Width = 2;
							  Canvas->Pen->Color =  clRed;
						 Canvas->MoveTo(posX,posY);
						 Canvas->LineTo(posX,posY + TamanoCeldaY);
						Canvas->Pen->Color = clBlack;
						Canvas->Pen->Width = 1;
						 }

							posX+=TamanoCeldaX;

						  Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
					Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].link));

							posX=auxX;


							posY+=TamanoCeldaY;
						   Canvas->Brush->Color = FormColor;



					}


	   //	}



	}	String as = "Libre: " + IntToStr(libre);
		Pintado(posX,posY+10,as,FormColor,Canvas);

}

void CSmemoria::ImprimirDireccion(int d,TColor FormColor, TCanvas *Canvas,int posX,int posY){

      int auxX = posX;
    int auxY = posY;
    bool b = true;
    int y = posY;int rowHeight = 20;  Canvas->Font->Size =8;
    //DIBUJAMOS CABECERA
    Pintado(posX,posY,"dir",FormColor,Canvas);
    posY+=TamanoCeldaY;
    Pintado(posX,posY,"dato",FormColor,Canvas);
    posY+=TamanoCeldaY;
    Pintado(posX,posY,"id",FormColor,Canvas);
    posY= auxY;
    posX+= TamanoCeldaX;
    Canvas->Font->Size =7;
    //CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	b=true;
	int prevLink = -1; // Inicializamos el link del elemento anterior
    for(int i = 0; i < 11; i++){
		if (i == prevLink || (i == d && b)) {
			b=true;
			if (b){
                if (mem[i].link!=libre) {
					Canvas->Brush->Color =clLime;
                    Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro
                    Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
                    Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
                    posY+=TamanoCeldaY;
                    Canvas->Brush->Color =  FormColor;
                    Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro
                    Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
                    Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));
                    posY+=TamanoCeldaY;
                    Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
                    Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());
                    posY=auxY;
                    posX+=TamanoCeldaX;
                    prevLink = mem[i].link;
                    if (mem[i].link==-1 ) {
                        b=false;
                    }
                }
			}
        }
    }
    String as = "Libre: " + IntToStr(libre);
    Pintado(posX,posY+10,as,FormColor,Canvas);
	y=y+30;
}

void CSmemoria::ImprimirP_DE_A_A_B(TColor FormColor, TCanvas *Canvas,int posX,int posY,int A , int B){
if (A<=B) {

int auxX = posX;
int auxY = posY;

Canvas->Font->Size =7;
bool b = true;
int p=0;
int y = 30;int rowHeight = 20;  Canvas->Font->Size =8;
	//DIBUJAMOS CABECERA
	Canvas->Brush->Color = clSilver;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,"dir");
	posX+=TamanoCeldaX;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,"dato");
	posX+=TamanoCeldaX;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,"id");
	posX+=TamanoCeldaX;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,"link");
	posX= auxX;
	posY+= TamanoCeldaY;
	Canvas->Font->Size =7;
    Canvas->Brush->Color= FormColor;
	//CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	for(int i = A; i <= B; i++){
	//if ( (mem[i].dato ==0 && mem[i].id == "")) {

	if (mem[i].link!=libre) {

	//Canvas->Brush->Color =clLime;
	Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color = FormColor;	//clLime
	//Canvas->Pen->Color = clBlack; // Cambia el color del l�piz a negro
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));

	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;

	Canvas->Brush->Color = FormColor;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());



	posX+=TamanoCeldaX;


	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].link));

			posX=auxX;
			posY+=TamanoCeldaY;
			Canvas->Brush->Color= FormColor;

	}
   //   clSilver
	}


		Canvas->Brush->Color= FormColor;
		String as = "Libre: " + IntToStr(libre);
		Pintado(posX,posY+10,as,FormColor,Canvas);




}else {
	ShowMessage("A tiene que ser mayor que B");
}
}
