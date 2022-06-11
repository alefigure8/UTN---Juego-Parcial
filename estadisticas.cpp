#include <iostream>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
#include "headers/menu.h"
using namespace std;
// Mostrar el puntaje final

void pantalla_puntaje( Jugadores *jugador );
void pdv_lanzamientos(int a, int b, int & lanzamientos_jugador_1, int & lanzamientos_jugador_2);
void pdv_oink(int a, int b, int & oinks_jugador_1, int & oinks_jugador_2);
int pdv_cada_50_trufas(int a);
void pdv_trufas_total(int a, int b, int &a_1, int &b_2);
void sumar_punto_historico(int total_jugador_1, int total_jugador_2, int & historico_jugador_1, int & historico_jugador_2);
void separador(int COLUMNA, int FILA);

void pantalla_puntaje(Jugadores *jugador){
  string eleccion, opcion = "m";

  int pdv_trufas_jugador_1 = 0;
  int pdv_trufas_jugador_2 = 0;
  int pdv_oinks_jugador_1 = 0;
  int pdv_oinks_jugador_2 = 0;
  int pdv_lanzamientos_jugador_1 = 0;
  int pdv_lanzamientos_jugador_2 = 0;
  int pdv_50_trufas_jugador_1 = pdv_cada_50_trufas(jugador[0].puntaje);
  int pdv_50_trufas_jugador_2 = pdv_cada_50_trufas(jugador[1].puntaje);
  int COLUMNA = 5;
  int COLUMNA_JUGADOR_1 = 40;
  int COLUMNA_JUGADOR_2 = 75;

  // Calculamos los puntos de vida
  pdv_trufas_total(jugador[0].puntaje, jugador[1].puntaje, pdv_trufas_jugador_1, pdv_trufas_jugador_2);
  pdv_oink(jugador[0].oink, jugador[1].oink, pdv_oinks_jugador_1, pdv_oinks_jugador_2);
  pdv_lanzamientos(jugador[0].total_lanzamientos, jugador[1].total_lanzamientos, pdv_lanzamientos_jugador_1, pdv_lanzamientos_jugador_2);

  int total_jugador_1 = pdv_trufas_jugador_1 + pdv_oinks_jugador_1 + pdv_lanzamientos_jugador_1 + pdv_50_trufas_jugador_1;
  int total_jugador_2 = pdv_trufas_jugador_2 + pdv_oinks_jugador_2 + pdv_lanzamientos_jugador_2 + pdv_50_trufas_jugador_2;
  
  sumar_punto_historico(total_jugador_1, total_jugador_2, jugador[0].juego_ganado, jugador[1].juego_ganado);
  
  do{
    system("cls");
    lines();

    // mostrar nombres
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 7); cout << "HITO";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 7); cout << jugador[0].jugador;
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 7) ; cout << jugador[1].jugador;

    separador(COLUMNA, 8);

    // // mas trufas en total
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 10); cout << "Más trufas en total";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 10); cout << pdv_trufas_jugador_1 << " PDV (" << jugador[0].puntaje << ")";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 10); cout << pdv_trufas_jugador_2 << " PDV (" << jugador[1].puntaje << ")";

    // puntaje cada 50 trufas
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 12); cout << "Cada 50 Trufas";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 12); cout << pdv_50_trufas_jugador_1 << " PDV (" << jugador[0].puntaje << ")";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 12); cout << pdv_50_trufas_jugador_2 << " PDV (" << jugador[1].puntaje<< ")";

    // oinks realizados
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 14); cout << "Oinks";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 14); cout << pdv_oinks_jugador_1 << " PDV (" << jugador[0].oink  << " Oinks) ";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 14); cout << pdv_oinks_jugador_2 << " PDV (" << jugador[1].oink  << " Oinks) ";
 
    // lanzamientos realizados
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 16); cout << "Cerdo codicioso";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 16); cout << pdv_lanzamientos_jugador_1 << " PDV ("<< jugador[0].total_lanzamientos << " Lanzamientos) ";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 16); cout << pdv_lanzamientos_jugador_2 << " PDV ("<< jugador[1].total_lanzamientos << " Lanzamientos) ";

    separador(COLUMNA, 17);

    // Suma total de puntos de vida
    colorTexto(COLOR::TEXTO);  rlutil::locate(COLUMNA, 19); cout << "TOTAL";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 19); cout << total_jugador_1 << " PDV";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 19); cout << total_jugador_2 << " PDV";

    // Puntos historicos jugados
    colorTexto(COLOR::TEXTO);  rlutil::locate(COLUMNA, 22); cout << "HISTORICO";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 22); cout << jugador[0].juego_ganado;
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 22); cout << jugador[1].juego_ganado;

    // Preguta si quiere volver a jugar
    if(jugador[0].iniicializado == false && jugador[1].iniicializado == false){
      colorTexto(COLOR::CONTINUAR); rlutil::locate(COLUMNA, 26); cout << "Para regresar al menu ingrese 'M': " << endl;
    } else {
      colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 26); cout << "Ingrese ";
      colorTexto(COLOR::CONTINUAR);cout << "'OINK'";
      colorTexto(COLOR::TEXTO);cout << " jugar la revancha o ingrese ";
      colorTexto(COLOR::MENSAJE);cout << "'N'";
      colorTexto(COLOR::TEXTO);cout << " para terminar el juego: ";
    }

    rlutil::locate(COLUMNA, 27); cout << ">> ";
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA + 4, 27); cin >> eleccion;

    // Pasa la eleccion a minuscula
    transform(eleccion.begin(), eleccion.end(), eleccion.begin(), ::tolower);

    // si se acaba una partida se pregunta si se quiere revancha o no
    if(jugador[1].iniicializado == true){
      if(eleccion == "oink"){
        eleccion = opcion;
      } else if(eleccion == "n"){
        for (int i = 0; i < 2; i++){
          jugador[i].iniicializado = false;
        }
        eleccion = opcion;
      }
    }

  } while (eleccion != opcion);

}

// separador de texto

void separador(int COLUMNA, int FILA){
  for (int i = 0; i < 100; i++){
   colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA + i, FILA); cout << "-";
  }
}

// Funcion otorga puntos de vida a partir de la cantidad de lanzamientos que realiza el jugador
void pdv_lanzamientos(int a, int b, int & lanzamientos_jugador_1, int & lanzamientos_jugador_2){
  if(a > b){
    lanzamientos_jugador_1 = 2;
  } else if(b > a) {
    lanzamientos_jugador_2 = 2;
  } else if( a == 0 && b == 0){
    lanzamientos_jugador_1 = 0;
    lanzamientos_jugador_2 = 0;
  } else {
    lanzamientos_jugador_1 = 2;
    lanzamientos_jugador_2 = 2;
  }
}


// Funcion otorga puntos de vida a partir de la cantidad de Oinks que realiza el jugador
void pdv_oink(int a, int b, int & oinks_jugador_1, int & oinks_jugador_2){
  oinks_jugador_1 = a * 2;
  oinks_jugador_2 = b * 2;
}


// Funcion que otorga puntos de vida cada 50 trufas
int pdv_cada_50_trufas(int a){
  return a / 50;
}


// Funcion que otorga puntos de vida al que mas puntos consiguio
void pdv_trufas_total(int a, int b, int &a_1, int &b_2){

  if(a > b){
    a_1 = 5;
  } else if(a < b){
    b_2 = 5;
  } else if (a == 0 && b == 0){
    a_1 = 0;
    b_2 = 0;
  } else {
    a_1 = 5;
    b_2 = 5;
  }

}

void sumar_punto_historico(int total_jugador_1, int total_jugador_2, int & historico_jugador_1, int & historico_jugador_2){

  if(total_jugador_1 > total_jugador_2){
    historico_jugador_1++;
  } else if (total_jugador_2 > total_jugador_1){
    historico_jugador_2++;
  }

}