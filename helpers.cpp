#include <Windows.h>
#include <iostream>
#include <string>
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
void iniciarMatriz(int matriz[2][3], int filas, int columnas){
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      matriz[i][j] = 0;
    }
  }
}