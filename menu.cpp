#include <Windows.h>
#include <iostream>
#include <fstream>
#include<locale>
using namespace std;

int menuInicial();
void nombres(int x);
 void lines();
  void endLines(int x);
 string nombreJugador;
void ResizeConsole(int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void colorTexto (int x){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

int main (void){
  setlocale(LC_ALL, "spanish");
  ResizeConsole(850,550);
  int eleccion;
  eleccion = menuInicial();

  if(eleccion == 1){
    for (int i = 0; i < 2; i++)
    {
      nombres(i);
    }
    
  }

  return 0;
}


int menuInicial(){

  int eleccion;

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


  cout << endl << endl << endl;
  colorTexto(10);cout << endl << "\t\t\t\t\t(1) - JUGAR";
  colorTexto(14); cout << endl << "\t\t\t\t\t(2) - ESTADISTICA";
  colorTexto(14); cout << endl << "\t\t\t\t\t(3) - CERDITOS";
  cout << endl;
  colorTexto(12); cout << endl << "\t\t\t\t\t(0) - SALIR" << endl << endl << endl << endl;
  colorTexto(9); cout << endl << "\t\t\t\t\t\t\t\t\t\t\tV1.0.0"<<endl << endl <<endl<<endl;

  lines();

 cin >>  eleccion;

  return eleccion;
}

 void nombres(int x){
   lines();

  endLines(12);
  cout << R"()" << endl;
  colorTexto(10); cout <<endl << endl <<  "\t\t\t¿Cuál es tu nombre, jugador  " << x + 1 << "?" << endl << endl;
  cout << "\t\t\t";

  colorTexto(12); cin >> nombreJugador;

  endLines(12);

   lines();
 }

 void lines(){
   cout << endl;
     for (int i = 0; i < 98; i++)
  {
    colorTexto(5); cout << "#";
  }
   cout << endl;

 }

 void endLines(int x){
   for (int i = 0; i < x; i++)
   {
     cout << endl;
   }
 }