#include <Windows.h>
#include <iostream> 
#include <string>
#include "headers/rlutil.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
using namespace std;

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

/* Funcion para enmarcar los textos */
 void enmarcar_texto(int jugador, string nombre, string dialogo){

   string texto = nombre + " " + dialogo;

    int largo = texto.size();

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
          colorTexto(12 + (jugador*(-3))); cout  << dialogo << " "; colorTexto(12 + (jugador*(-1))); cout << nombre;
          colorTexto(9); cout << "   |" << endl;
          j = largo + 8;
        }

      }
    }
 }

 /* Funcon que dibuja al cerdo*/
 void cerdo(int x, string dialogo, string nombre){
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
  enmarcar_texto(x, dialogo, nombre);
 }

  void cerdo2(int x, string dialogo, string nombre){
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
  enmarcar_texto(x, dialogo, nombre);
 }

 /* Funcion que a�ade el decorado de lineas a cada pantalla*/
 void lines(int x){
   cout << endl;
      for (int i = 0; i < 98; i++)
    {
      colorTexto(2); cout << "#";
    }
    cout << endl;
   if(x == 1){
      colorTexto(15); cout << "THE KING OF PIGS" << endl;
   }
 }
 
 void puntaje(string nombre_jugador_1, string nombre_jugador_2, int puntos_jugador_1, int puntos_jugador_2){
    cout << nombre_jugador_1 << ": " << puntos_jugador_1 << " puntos" << endl;
    cout << "\t\t\t\t\t\t\t"<< nombre_jugador_2 << ": " << puntos_jugador_2 << " puntos" << endl;
 }

 /* Funcion que imprime la pantalla de cerdo 1 o 2*/
 void pantalla_generica(int i, int pantalla_cerdo, string dialogo, string nombre){
    system("cls"); // Limpiar pantalla
    lines(1);
    endLines(2);

    if(pantalla_cerdo == 1){
      cerdo(i, dialogo, nombre);
    } else if(pantalla_cerdo == 2){
      cerdo2(i, dialogo, nombre);
    }
    endLines(2);

    if(pantalla_cerdo == 2){
      cout << "Presiona cualquier tecla para continuar...";
    }

    endLines(1);
    lines(2);

    if(pantalla_cerdo == 2){
      rlutil::anykey();
    }
 }

  /* Funcion que imprime una pantalla generica*/
  void pantalla_generica_2(int i, string texto, string dialogo, string nombre_jugador_1, string nombre_jugador_2, int puntos_jugador_1, int puntos_jugador_2){
    system("cls"); // Limpiar pantalla
    lines(1);
    endLines(2);
    puntaje(nombre_jugador_1, nombre_jugador_2, puntos_jugador_1, puntos_jugador_2);
    endLines(2);
    cout << texto << endl; // Texto principal
    endLines(4);
    cout << dialogo << endl; // Instruccion
    endLines(4);
    lines(2);
    rlutil::anykey();
 }

char pantalla_juego (string jugadorActual, int contadorRondas, int totalRonda, int lanzamientos, string dados){

  char eleccion;

  system("cls"); // Limpiar pantalla
  lines(1);
  cout << endl << "TURNO DE "<< jugadorActual << endl;
  cout << "+=========================+" << endl;
  cout << "| RONDA #" << contadorRondas << "                |"<< endl ;
  cout << "| TRUFAS DE LA RONDA : " << totalRonda << "  |" << endl;
  cout << "| LANZAMIENTO #" << lanzamientos - 1 <<  "          |" << endl;
  cout << "+=========================+" << endl;
  cout << endl << "LANZAMIENTO #" << lanzamientos << endl << endl;

  lines(2);

  return eleccion;
}