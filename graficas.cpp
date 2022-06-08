#include <Windows.h>
#include <iostream> 
#include <string>
#include "headers/rlutil.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
using namespace std;

enum COLOR {
  JUGADOR_1 = 159,
  JUGADOR_2 = 207,
  CERDO = 13,
  TITULO = 15,
  LINEAS = 192,
  TEXTO = 15,
  RECUADRO = 252,
  MENSAJE = 12,
  CONTINUAR = 10,
};

void imprimir_titulo(){
 colorTexto(COLOR::TITULO); rlutil::locate(20, 3); cout << R"(
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

   int color;

   if(jugador == 0){
     color = COLOR::JUGADOR_1;
   } else {
     color = COLOR::JUGADOR_2;
   }

    int largo = texto.length();

    for (int i = 0; i < 5 ; i++){
      for (int j = 0; j < largo + 8; j++){
        if(i == 0 || i == 4){

          if(j == 0 && i == 0){
            colorTexto(color); rlutil::locate(20, 21); cout << " ";
          } else if (j == 0 && i == 4) {
            colorTexto(color); rlutil::locate(20, 25); cout << " ";
          } else {
             colorTexto(color); cout << " ";
          }

          if(j == largo + 7){
            cout << endl;
          }
        } else if(i == 1 || i == 3){
          if(j == 0 || j == largo + 7){
            if(j == 0 && i == 1){
              colorTexto(color); rlutil::locate(20, 22); cout << " ";
            } else if (j == 0 && i == 3) {
              colorTexto(color); rlutil::locate(20, 24); cout << " ";
            } else {
              colorTexto(color); cout << " ";
            }

            if(j == largo + 7){
              cout << endl;
            }
          } else {
            cout << " ";
          }
        } else if( i == 2){
          rlutil::locate(20, 23); cout << "    ";
          cout  << dialogo << " "<< nombre;
          colorTexto(color); cout << "    " << endl;
          j = largo + 8;
        }

      }
    }
    colorTexto(COLOR::TEXTO);
 }

 /* Funcon que dibuja al cerdo*/
 void cerdo(int x, string dialogo, string nombre){
 colorTexto(COLOR::CERDO); rlutil::locate(30, 4) ;cout << R"(
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

  endLines(3);
  enmarcar_texto(x, dialogo, nombre);
 }

  void cerdo2(int x, string dialogo, string nombre){
  colorTexto(COLOR::CERDO); rlutil::locate(30, 4); cout << R"(
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
  
  endLines(3);
  enmarcar_texto(x, dialogo, nombre);
 }

 /* Funcion que a�ade el decorado de lineas a cada pantalla*/
 void lines(){

    rlutil::locate(1, 1);
    for (int i = 0; i < 98; i++){
      colorTexto(COLOR::LINEAS); cout << " ";
    }

    rlutil::locate(1, 2); colorTexto(COLOR::TITULO); cout << "THE KING OF PIGS" << endl;

    rlutil::locate(1, 29);
    for (int i = 0; i < 98; i++){
      colorTexto(COLOR::LINEAS); cout << " ";
    }
    colorTexto(COLOR::TEXTO);
 }
 
 /* Funcion que imprime puntaje de jugadores */
 void puntaje(string nombre_jugador_1, string nombre_jugador_2, int *dados_1, int *dados_2,  string texto){
    int dado_1_total = sumar_dados(dados_1, 2);
    int dado_2_total = sumar_dados(dados_2, 2);
    rlutil::locate(10, 6); cout << nombre_jugador_1 << ": " << dado_1_total <<  " " << texto << " ( " << dados_1[0] << ", " << dados_1[1] << " )";
    cout << "\t\t\t\t" << nombre_jugador_2 << ": " << dado_2_total << " " << texto << " ( " << dados_2[0] << ", " << dados_2[1] << " )" << endl;
    rlutil::locate(9, 7); cout << "-------------------------------------------------------------------------------" << endl;
 }

  /* Funcion que imprime puntaje de jugadores */
 void puntaje_rondas(string nombre_jugador_1, string nombre_jugador_2, int puntos_jugador_1, int puntos_jugador_2,  string texto){
    rlutil::locate(5, 5); cout << "\t" << nombre_jugador_1 << ": " << puntos_jugador_1 <<  " " << texto;
    cout << "\t\t\t" << nombre_jugador_2 << ": " << puntos_jugador_2 << " " << texto  << endl;
    rlutil::locate(5, 6);cout << "     ------------------------------------------------------------------------" << endl;
 }

 /* Funcion que imprime la pantalla de cerdo 1 o 2*/
 void pantalla_generica(int i, int pantalla_cerdo, string dialogo, string nombre){
    system("cls"); // Limpiar pantalla
    lines();
    endLines(2);

    if(pantalla_cerdo == 1){
      cerdo(i, dialogo, nombre);
    } else if(pantalla_cerdo == 2){
      cerdo2(i, dialogo, nombre);
    }
    endLines(2);

    if(pantalla_cerdo == 2){
      colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..." << endl;
    }

    endLines(1);

    if(pantalla_cerdo == 2){
      rlutil::anykey();
    }
 }

  /* Funcion que imprime una pantalla generica*/
  void pantalla_generica_2(int i, string texto, string dialogo, string nombre_jugador_1, string nombre_jugador_2, int puntos_jugador_1, int puntos_jugador_2){
    system("cls"); // Limpiar pantalla
    lines();
    endLines(2);
    //puntaje(nombre_jugador_1, nombre_jugador_2, puntos_jugador_1, puntos_jugador_2, "PUNTOS");
    endLines(2);
    cout << texto << endl; // Texto principal
    endLines(4);
    cout << dialogo << endl; // Instruccion
    endLines(4);
    rlutil::anykey();
 }

void pantalla_juego (int contadorRondas, int totalRonda, int lanzamientos){
  string ronda_texto = "  RONDA # " + to_string (contadorRondas);
  string trufas_texto = "  TRUFAS DE LA RONDA: " + to_string (totalRonda);
  string lanzamientos_texto = "  LANZAMIENTO # " + to_string (lanzamientos);

  colorTexto(COLOR::RECUADRO);

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      if(i == 0 || i == 4){
        if(i == 0){
          rlutil::locate(3 + j, 9);
        } else {
          rlutil::locate(3  + j, 13);
        }
        cout << " ";
      } else if( i == 1){
        int cantidad = ronda_texto.length();
        if(j < cantidad){
          rlutil::locate(3 + j, 10); cout << ronda_texto[j];
        } else {
         rlutil::locate(3 + j, 10); cout << " ";
        }
      } else if( i == 2){
        int cantidad = trufas_texto.length();
        if(j < cantidad){
         rlutil::locate(3 + j, 11); cout << trufas_texto[j];
        } else {
          rlutil::locate(3 + j, 11);cout << " ";
        }
      } else if( i == 3){
        int cantidad = lanzamientos_texto.length();
        if(j < cantidad){
          rlutil::locate(3 + j, 12); cout << lanzamientos_texto[j];
        } else {
          rlutil::locate(3 + j, 12); cout << " ";
        }
      }

      if(j == 29){
        cout << endl;
      }
    }
  }

  colorTexto(COLOR::TEXTO);
}

/* Funcion que muestra la flecha en la pantalla inicial*/
int flecha_del_menu(){
    int key ;
    int eleccion;
    int posicion_actual = 17;
    int posicion_inicial = 17;
    int posicion_final = 20;
     do
    {
      key = rlutil::getkey();
      switch(key){
        case 15: // Flecha arriba
          if(posicion_actual < posicion_final){
            posicion_actual = posicion_actual + 1;
            colorTexto(COLOR::TEXTO); rlutil::locate(38, posicion_actual); cout << (char)187 << endl;
            rlutil::locate(38, posicion_actual - 1); cout << " " << endl;
          }
          break;
        case 14: // Flecha abajo
          if(posicion_actual > posicion_inicial){
            posicion_actual = posicion_actual - 1;
            colorTexto(COLOR::TEXTO); rlutil::locate(38, posicion_actual); cout << (char)187 << endl;
            rlutil::locate(38, posicion_actual + 1); cout << " " << endl;
          }
          break;
        case 1: // Enter
          eleccion = posicion_actual - 16;
          if(eleccion == 4){
            eleccion = 0;
          }
          break;
      }
    } while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 0);

    return eleccion;
}