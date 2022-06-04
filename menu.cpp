#include <Windows.h>
#include <iostream>
#include<locale>
#include <iomanip>
#include <string>
#include "headers/rlutil.h"
using namespace std;

/* Funciones */
void menuInicial();
void nombres(int x);
void lines();
void endLines(int x);
void cerdo(int x, string dialog);
void cerdo2(int x, string dialog);
void ResizeConsole(int width, int height);
void colorTexto (int x);
void quienEmpieza();
void dados(int a[], int b);
void iniciarMatriz(int matriz[2][3], int filas, int columnas);
void imprimirDados(int num);

/* Variables globales */
string jugadores[2];
string jugadorActual;

/* Main */
int main (void){
  setlocale(LC_ALL, "spanish");
  ResizeConsole(850,550);
  menuInicial();




  return 0;
}

/* Funcion para el munnu de inicio */
void menuInicial(){

  char eleccion;

  do{
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

    switch (eleccion){
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
  }while(eleccion != 'S' && eleccion != 's');

}

/* Funcion que pide los nombres de los jugadores*/ 
 void nombres(int x){
  string dialog = "";

  // segun el turno cambia el dialogo
  if(x == 0){
    dialog = "\t\t�Cu�l es tu nombre, cerdo uno?";
  } else {
    dialog =  "\t\tTu turno, cerdo dos, �cu�l es tu nombre?";
  }

  lines();
  colorTexto(15); cout << setw(10)<< "THE KING OF PIGS" ;
  endLines(6);
  cerdo(x, dialog); // Imprime cerdo
  endLines(8);
  lines();
  colorTexto(15); cin >> jugadores[x]; // Guarda nombre de los jugadores
 }



/* Funcion que a�ade el decorado de lineas a cada pantalla*/
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

 /* Funcon que dibuja al cerdo*/
 void cerdo2(int x, string dialog){
  colorTexto(13); cout << R"(
          _                           _
          ;`.                       ,'/
          |`.`-.      _____      ,-;,'|
          |  `-.\__,-'     `-.__//'   |
          |     `|               \ ,  |
          `.  ```  _              ,  .'
            \_`     `.     ,   ,  `_/)
              \    0  `   ,   0 ` /
               | '  |  ____  | , |
               |     ,'    `.    |
               |    (  O' O  )   |
               `.    \__,.__/   ,'
                 `-._  \__/   _,'
                     `------')";

  endLines(3);
  colorTexto(12 + (x*(-3))); cout << setw(50)<< dialog;
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

/* Funcion para determinar cual jugador comienza*/ 
void quienEmpieza(){
  int CANT_DADOS = 2;
  int CANT_JUGADORES = 2;
  int dados_jugadores[3];
  int totalJugadores[2][3];
  int sumaMaxima = 0;
  int jugador;
  int dadoMaximo = 0;
  int jugadorDadoMaximo;
  int totalJugador1= totalJugadores[0][0] + totalJugadores[0][1];
  int totalJugador2= totalJugadores[1][0] + totalJugadores[1][1];
  string dialog;

  iniciarMatriz(totalJugadores, CANT_JUGADORES, CANT_DADOS);

  char eleccion;

  for (int i = 0; i < CANT_JUGADORES; i++){
    /* Pantalla 1*/
    lines();
    endLines(8);
    if(i == 0){
      dialog = "Lanza los dados, " + jugadores[i] +  " �Est�s listos? (S/N)";
    } else {
      dialog = "Ahora es tu turno " + jugadores[i] +  " �Est�s listos? (S/N)";
    }

    cerdo2(i, dialog);

    endLines(8);
    lines();

    cin >> eleccion;

    /* Pantalla 2*/
    lines();
    endLines(8);
  
    if(eleccion == 'S'){

      dados(dados_jugadores, 2);

      for (int j = 0; j < CANT_DADOS; j++){
        totalJugadores[i][j] += dados_jugadores[j];
        imprimirDados(dados_jugadores[j]);
      }
    } else {
      if(i == 0){ // Si no quiere tirar, cede turno
       jugadorActual = jugadores[1];
       i = 2;
      } else {
        jugadorActual = jugadores[0];
        i = 2;
      }
    }

    int total = 0;

    for (int j = 0; j < CANT_DADOS; j++){
      total += totalJugadores[i][j];

      if(totalJugadores[i][j] > dadoMaximo){
        dadoMaximo = totalJugadores[i][j];
        jugadorDadoMaximo = i + 1;
      }
    }

    string strTotal = to_string(total);
    colorTexto(15);cout << setw(50) <<"Has sumado " + strTotal + "!";

    endLines(8);
    lines();
    rlutil::anykey();

    if(total > sumaMaxima){
      sumaMaxima = total;
      jugador = i + 1;
    }

    if(totalJugador1 != totalJugador2){
        if (jugador == 1){
        jugadorActual = jugadores[0];
      } else {
        jugadorActual = jugadores[1];
      }
    } else {
      if (jugadorDadoMaximo == 1){
        jugadorActual = jugadores[0];
      } else {
        jugadorActual = jugadores[1];
      }
    }
  }

  lines();
  endLines(8);

  dialog = "�COMIENZA EL JUGADOR " + jugadorActual + "!";
  cerdo2(0, dialog);

  endLines(8);
  lines();

  rlutil::anykey();

}

/* Funcion para inicializar con ceros una matriz*/
void iniciarMatriz(int matriz[2][3], int filas, int columnas){
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      matriz[i][j] = 0;
    }
  }
}

/* Funcion que simula los dados y devuelve numeros random */
void dados(int a[], int b){
  srand(time(0));
  for (int i = 0; i < b; i++){
    a[i] = rand() % 6 + 1;
  }
}

void imprimirDados(int num){
  int dado[5][9];
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 9; j++){

      if(i == 0 || i == 4){
        if(j == 0 || j == 8){
         cout << "+";
          if(j == 8){
            cout << endl;
          }
        } else{
          cout <<"-";
        }
      } else {
        if(j == 0 || j == 8){
          cout << "|";
          if(j == 8){
            cout << endl;
          }
        } else{
         if(num % 2 != 0){
          if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && num > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 3)){
            cout << "x";
            } else {
              cout <<" ";
            }
         } else {
           if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && num > 4)){
            cout << "x";
          } else {
            cout <<" ";
          }
         }
        }
      }
    }
  }
}