#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
using namespace std;

/* Funcion para darle ancho y largo a la consola*/
void ResizeConsole(int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

/* Funcoin para modificar colores de los textos */
void colorTexto (int x){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

/* Funcion para agregar saltos de lineas*/
 void endLines(int x){
   for (int i = 0; i < x; i++)
   {
     cout << endl;
   }
 }

 /* Funcion para inicializar con ceros una matriz*/
void iniciar_vector(int *vector, int filas){
  for (int i = 0; i < filas; i++){
      vector[i] = 0;
  }
}

/* Funcion para sumar los dados*/
int sumar_dados(int vec[3], int CANT_DADOS){
  int total = 0;
   for (int j = 0; j < CANT_DADOS; j++){
      total += vec[j];
    }
  return total;
}

void obtener_maximo(int total, int &maximo, int i, int &jugadorMaximo){
  if(total > maximo){
    maximo = total;
    jugadorMaximo = i + 1;
  }
}

