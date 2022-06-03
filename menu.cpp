#include <Windows.h>
#include <iostream>
#include <fstream>
#include<locale>
#include <iomanip>
using namespace std;

char menuInicial();
void nombres(int x);
void lines();
void endLines(int x);
void cerdo(int x, string dialog);
void ResizeConsole(int width, int height);
void colorTexto (int x);
string nombreJugador;

int main (void){
  setlocale(LC_ALL, "spanish");
  ResizeConsole(850,550);
  int eleccion;
  eleccion = menuInicial();

  switch (eleccion)
  {
  case 'J':
  case 'j': {
    for (int i = 0; i < 2; i++)
    {
      nombres(i);
    }
    quienEmpieza();
  }
    break;
  }


  return 0;
}


char menuInicial(){

  char eleccion;

  lines();

  colorTexto(15);cout <<endl << endl << R"(

                  _              _     _                        ___          _            
              _  | |            | |   (_)                      / __)        (_)           
            _| |_| |__  _____   | |  _ _ ____   ____     ___ _| |__    ____  _  ____  ___ 
           (_   _)  _ \| ___ |  | |_/ ) |  _ \ / _  |   / _ (_   __)  |  _ \| |/ _  |/___)
             | |_| | | | ____|  |  _ (| | | | ( (_| |  | |_| || |     | |_| | ( (_| |___ |
              \__)_| |_|_____)  |_| \_)_|_| |_|\___ |   \___/ |_|     |  __/|_|\___ (___/ 
                                              (_____|                 |_|     (_____| 
  )" << endl;


  endLines(3);
  colorTexto(10);cout << endl << setw(40 + 11) << "(J) - JUGAR";
  colorTexto(14); cout << endl << setw(40 + 17)<< "(E) - ESTADISTICA";
  colorTexto(14); cout << endl << setw(40 + 14)<< "(C) - CERDITOS";
  cout << endl;
  colorTexto(12); cout << endl << setw(40 + 11)<< "(S) - SALIR";
  endLines(3);
  colorTexto(9); cout << endl << setw(80)<< "V1.0.0";
  endLines(3);

  lines();

 cin >>  eleccion;

  return eleccion;
}

/* Funcion que pide los nombres de los jugadores*/ 
 void nombres(int x){
  string dialog = "";

  if(x == 0){
    dialog = "\t\t¿Cuál es tu nombre, cerdo uno?";
  } else {
    dialog =  "\t\tTu turno, cerdo dos, ¿cuál es tu nombre?";
  }

  lines();
  colorTexto(15); cout << setw(10)<< "THE KING OF PIGS" ;
  endLines(6);
  cerdo(x, dialog);
  endLines(8);
  lines();
  endLines(2);
  colorTexto(15); cin >> nombreJugador;
 }



/* Funcion que añade el decorado de lineas a cada pantalla*/
 void lines(){
   cout << endl;
     for (int i = 0; i < 98; i++)
  {
    colorTexto(2); cout << "#";
  }
   cout << endl;

 }

/* Funcion para agregar saltos de lineas*/
 void endLines(int x){
   for (int i = 0; i < x; i++)
   {
     cout << endl;
   }
 }

/* Funcon que dibuja al cerdo*/
 void cerdo(int x, string dialog){
  colorTexto(13); cout << R"(
          _                           _
          ;`.                       ,'/
          |`.`-.      _____      ,-;,'|
          |  `-.\__,-'     `-.__//'   |
          |     `|               \ ,  |
          `.  ```  _              ,  .'
            \_`     `.     ,   ,  `_/)";
  cout << R"(
              \    0  `   ,   0 ` /)"; colorTexto(12 + (x*(-3))); cout << dialog;
  colorTexto(13);  cout << R"(
               | '  |  ____  | , |
               |     ,'    `.    |
               |    (  O' O  )   |
               `.    \__,.__/   ,'
                 `-._        _,'
                     `------')";
 }

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
