#include <Windows.h>
#include <iostream>
#include<locale>
#include <iomanip>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
using namespace std;

/* Funciones */
void menuInicial();
Jugadores pedir_nombre(int x);
void lines();
void endLines(int x);
void cerdo(int x, string dialog);
void cerdo2(int x, string dialog);
void ResizeConsole(int width, int height);
void colorTexto (int x);
void quienEmpieza(Jugadores *jugador, string &jugadorActual);
void dados(int a[], int b);
void iniciarMatriz(int matriz[2][3], int filas, int columnas);
void imprimirDados(int num);

enum OPCIONES {
  SALIR = 0,
  INICIAR_JUEGO = 1,
  ESTADISTICAS = 2,
  CREDITOS = 3
};

/* Main */
int main (void){
  setlocale(LC_ALL, "spanish"); // Para que se vea correctamente el texto en la consola
  ResizeConsole(850,550); // Cambiar tamaùo de consola
  menuInicial(); // Menu inicial

  return 0;
}

/* Funcion con el titulo del juego */
void imprimir_titulo(){
  cout <<endl << endl << R"(
                   _              _     _                        ___          _
               _  | |            | |   (_)                      / __)        (_)
             _| |_| |__  _____   | |  _ _ ____   ____     ___ _| |__    ____  _  ____  ___
            (_   _)  _ \| ___ |  | |_/ ) |  _ \ / _  |   / _ (_   __)  |  _ \| |/ _  |/___)
              | |_| | | | ____|  |  _ (| | | | ( (_| |  | |_| || |     | |_| | ( (_| |___ |
               \__)_| |_|_____)  |_| \_)_|_| |_|\___ |   \___/ |_|     |  __/|_|\___ (___/
                                               (_____|                 |_|     (_____|
    )" << endl;
}

/* Funcion para el munnu de inicio */
void menuInicial(){
  Jugadores jugadores[2];
  string jugadorActual;
  int eleccion;

  do{
    lines();
    colorTexto(15);
    imprimir_titulo();
    endLines(3);
    colorTexto(10); cout << endl << setw(40 + 11) << "(1) - JUGAR";
    colorTexto(14); cout << endl << setw(40 + 17)<< "(2) - ESTADISTICA";
    colorTexto(14); cout << endl << setw(40 + 14)<< "(3) - CERDITOS";
    endLines(1);
    colorTexto(12); cout << endl << setw(40 + 11)<< "(0) - SALIR";
    endLines(3);
    colorTexto(9); cout << endl << setw(80)<< "V1.0.0";
    endLines(3);
    lines();

    cin >>  eleccion;

    switch (eleccion){
    case OPCIONES::INICIAR_JUEGO: {
      for (int i = 0; i < 2; i++)
      {
        jugadores[i] = pedir_nombre(i);
      }
      lines();
      cout << jugadores[0].jugador<< endl;
      cout << jugadores[1].jugador << endl;
      lines();

      quienEmpieza(jugadores, jugadorActual);
    }
      break;
    }
  }while(eleccion != OPCIONES::SALIR);

}

/* Funcion que pide los nombres de los jugadores*/
 Jugadores pedir_nombre(int x){

   Jugadores jugadores;

    string dialog = "";

    // segun el turno cambia el dialogo
    if(x == 0){
      dialog = "øCu·l es tu nombre, cerdo uno?";
    } else {
      dialog =  "Tu turno, cerdo dos, øcu·l es tu nombre?";
    }

    lines();
    colorTexto(15); cout << "THE KING OF PIGS" ;
    endLines(6);
    cerdo(x, dialog); // Imprime cerdo
    endLines(8);
    lines();

    colorTexto(15);
    cin >> jugadores.jugador;
    jugadores.puntaje = 0;

    return jugadores;
 }



/* Funcion que aùade el decorado de lineas a cada pantalla*/
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

/* Funcion para enmarcar los textos */
 void enmarcar_texto(string dialogo, int jugador){

    int largo = dialogo.size();

    for (int i = 0; i < 5 ; i++){
      for (int j = 0; j < largo + 8; j++){
        if(i == 0 || i == 4){
          colorTexto(9);  cout << "=";
          if(j == largo + 7){
            cout << endl;
          }
        } else if(i == 1 || i == 3){
          if(j == 0 || j == largo + 7){
            cout << "|";
            if(j == largo + 7){
              cout << endl;
            }
          } else {
            cout << " ";
          }
        } else if( i == 2){
          cout << "|   ";
          colorTexto(12 + (jugador*(-3))); cout  << dialogo;
          colorTexto(9); cout << "   |" << endl;
          j = largo + 8;
        }

      }
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
          `.  ```                 ,  .'
            \_`      .         ,  `_/
              \    -  `   ,   - ` /
               | '  |  ____  | , |
               |     ,'    `.    |
               |    (  O' O  )   |
               `.    \__,.__/   ,'
                 `-._        _,'
                     `------')";

  endLines(2);
  enmarcar_texto(dialog, x);
  endLines(3);
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
            \_`     `.     ,   ,  `_/
              \    0  `   ,   0 ` /
               | '  |  ____  | , |
               |     ,'    `.    |
               |    (  O' O  )   |
               `.    \__,.__/   ,'
                 `-._  \__/   _,'
                     `------')";
  endLines(2);
  enmarcar_texto(dialog, x);
  endLines(3);
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
void quienEmpieza(Jugadores *jugador, string &jugadorActual){
  int CANT_DADOS = 2;
  int CANT_JUGADORES = 2;
  int dados_jugadores[3];
  int totalJugadores[2][3];
  int sumaMaxima = 0;
  int jugadorSumaMaxima;
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
      dialog = "Lanza los dados, " + jugador[i].jugador +  " øEst·s listos? (S/N)";
    } else {
      dialog = "Ahora es tu turno " + jugador[i].jugador  +  " øEst·s listos? (S/N)";
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
       jugadorActual = jugador[1].jugador ;
       i = 2;
      } else {
        jugadorActual = jugador[0].jugador;
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

    /* Guarda el maximo puntaje */
    if(total > sumaMaxima){
      sumaMaxima = total;
      jugadorSumaMaxima = i + 1;
    }

    /* Asigna turno dependiendo el puntaje*/
    if(totalJugador1 != totalJugador2){
        if (jugadorSumaMaxima == 1){ // si no hay empate
        jugadorActual = jugador[0].jugador;
      } else {
        jugadorActual = jugador[1].jugador;
      }
    } else {
      if (jugadorDadoMaximo == 1){ // si hay empate
        jugadorActual = jugador[0].jugador;
      } else {
        jugadorActual = jugador[1].jugador;
      }
    }
  }

  lines();
  endLines(8);

  dialog = "°COMIENZA EL JUGADOR " + jugadorActual + "!";
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