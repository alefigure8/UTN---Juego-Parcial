#include <Windows.h>
#include <iostream>
#include <string>
#include "headers/rlutil.h"
#include "headers/helpers.h"
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