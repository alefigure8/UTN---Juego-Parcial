#include <iostream>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/jugadores_estadistica.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
#include "headers/menu.h"
using namespace std;

// Funciones
void pantalla_puntaje( Jugadores *jugador );
void pdv_lanzamientos(int a, int b, int & lanzamientos_jugador_1, int & lanzamientos_jugador_2);
void pdv_oink(int a, int b, int & oinks_jugador_1, int & oinks_jugador_2);
int pdv_cada_50_trufas(int a);
void pdv_trufas_total(int a, int b, int &a_1, int &b_2);
void sumar_punto_historico(int total_jugador_1, int total_jugador_2, int & historico_jugador_1, int & historico_jugador_2);
void pdv_primos(int &a, int &b, bool primo_1, bool primo_2, int cant_dados_1, int cant_dados_2);


// Funcion que muestra la pantalla con el puntaje final de ambos jugadores
void pantalla_puntaje(Jugadores *jugador, Jugadores_estadistica *jugador_estadistica){
  string eleccion, opcion = "salir";

  int pdv_trufas_jugador_1 = 0;
  int pdv_trufas_jugador_2 = 0;
  int pdv_oinks_jugador_1 = 0;
  int pdv_oinks_jugador_2 = 0;
  int pdv_lanzamientos_jugador_1 = 0;
  int pdv_lanzamientos_jugador_2 = 0;
  int pdv_50_trufas_jugador_1 = pdv_cada_50_trufas(jugador[0].puntaje);
  int pdv_50_trufas_jugador_2 = pdv_cada_50_trufas(jugador[1].puntaje);
  int pdv_primos_jugador_1 = 0;
  int pdv_primos_jugador_2 = 0;
  int COLUMNA = 5;
  int COLUMNA_JUGADOR_1 = 40;
  int COLUMNA_JUGADOR_2 = 75;

  // Calculamos los puntos de vida
  pdv_trufas_total(jugador[0].puntaje, jugador[1].puntaje, pdv_trufas_jugador_1, pdv_trufas_jugador_2);
  pdv_oink(jugador[0].oink, jugador[1].oink, pdv_oinks_jugador_1, pdv_oinks_jugador_2);
  pdv_lanzamientos(jugador[0].total_lanzamientos, jugador[1].total_lanzamientos, pdv_lanzamientos_jugador_1, pdv_lanzamientos_jugador_2);
  pdv_primos(pdv_primos_jugador_1, pdv_primos_jugador_2, jugador[0].primo, jugador[1].primo, jugador[0].dados_primos, jugador[1].dados_primos);

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

    separador(COLUMNA, 8, 85);

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

    // lanzamientos realizados
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 16); cout << "Humcerdo Primo";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 16); cout << pdv_primos_jugador_1 << " PDV";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 16); cout << pdv_primos_jugador_2 << " PDV";

    separador(COLUMNA, 18, 85);

    // Suma total de puntos de vida
    colorTexto(COLOR::TEXTO);  rlutil::locate(COLUMNA, 19); cout << "TOTAL";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 19); cout << total_jugador_1 << " PDV";
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 19); cout << total_jugador_2 << " PDV";

    // Imprimimos el jugador que gana y lo cargamos en la estructura de jugadores que ganaron
    if(total_jugador_1 > total_jugador_2){
      colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA, 21); cout << "GANA " << jugador[0].jugador << " CON " << total_jugador_1 << " PDV";
      cargar_jugadores_estadisticas(jugador[0].jugador, total_jugador_1, jugador_estadistica);

    } else if(total_jugador_1 < total_jugador_2){
      colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA, 21); cout << "GANA " << jugador[1].jugador << " CON " << total_jugador_2 << " PDV";
      cargar_jugadores_estadisticas(jugador[1].jugador, total_jugador_2, jugador_estadistica);
    } else {
      colorTexto(COLOR::CONTINUAR); rlutil::locate(COLUMNA, 21); cout << "EMPATE";
    }

    // Puntos historicos jugados
    colorTexto(COLOR::TEXTO);  rlutil::locate(COLUMNA, 23); cout << "MODO REVANCHA";
    colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, 23); cout << jugador[0].juego_ganado;
    colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, 23); cout << jugador[1].juego_ganado;

    // Pregunta si desea volver a jugar
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA, 26); cout << "Ingrese ";
    colorTexto(COLOR::CONTINUAR);cout << "'OINK'";
    colorTexto(COLOR::TEXTO);cout << " para jugar la revancha o ingrese ";
    colorTexto(COLOR::MENSAJE);cout << "'SALIR'";
    colorTexto(COLOR::TEXTO);cout << " para terminar el juego: ";

    rlutil::locate(COLUMNA, 27); cout << ">> ";
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA + 4, 27); cin >> eleccion;

    // Pasa la eleccion a minuscula
    transform(eleccion.begin(), eleccion.end(), eleccion.begin(), ::tolower);

    // si se quiere revancha, no se inicializa jugadores; si no se quiere revancha, se reinicializa jugadores
    if(eleccion == "oink"){
      eleccion = opcion;
    } else if(eleccion == "salir"){
      for (int i = 0; i < 2; i++){
        jugador[i].iniicializado = false;
      }
    }

  } while (eleccion != opcion);

}


// Funcion que muestra la pantalla de estadisticas de los jugadores que ganaron
void pantalla_estadistica(Jugadores_estadistica *jugadores){
  int COLUMNA_JUGADOR = 30;
  int COLUMNA_PDV = 55;
  int FILA = 10;
  string TITULO = "ESTADISTICAS";

  // ordenar jugadores por puntaje
  ordenar_vector(jugadores, 15);

  rlutil::cls();
  lines();
  colorTexto(COLOR::MENSAJE); rlutil::locate(41, 5); cout << TITULO << endl;
  separador(10, 7, 80);
  colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA_JUGADOR, 8); cout << "JUGADORES";
  colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA_PDV, 8); cout << "PUNTAJE";
  separador(10, 9, 80);

  for (int i = 0; i < 15; i++){
    colorTexto(COLOR::CONTINUAR); rlutil::locate(COLUMNA_JUGADOR - 5, FILA + i); cout << "#" << i + 1;
    (jugadores[i].inicializado == true ? colorTexto(COLOR::TURNO_JUGADOR_1) : colorTexto(COLOR::TEXTO)); rlutil::locate(COLUMNA_JUGADOR, FILA + i); cout << (jugadores[i].inicializado == true ? jugadores[i].jugador : "VACIO");
    (jugadores[i].inicializado == true ? colorTexto(COLOR::TURNO_JUGADOR_2) : colorTexto(COLOR::TEXTO));; rlutil::locate(COLUMNA_PDV, FILA + i); cout << (jugadores[i].inicializado == true ? jugadores[i].pdv : 0) << " PDV";
  }

  colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA REGRESAL AL MENÚ" << endl;
  rlutil::anykey();

}


// Funciona que calcula el puntaje si salieron dados primos
void pdv_primos(int &a, int &b, bool primo_1, bool primo_2, int cant_dados_1, int cant_dados_2){
  if(primo_1 == true){
    a = 3;
    if(cant_dados_1 == 3){
      a = +2;
    }
  } else if(primo_2 == true){
    b = 3;
    if(cant_dados_2 == 3){
      b = +2;
    }
  }
}


// Funcion que otorga puntos de vida a partir de la cantidad de lanzamientos que realiza el jugador
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


// Funcion que otorga puntos de vida a partir de la cantidad de Oinks que realiza el jugador
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

// Funcion que suma los puntos totales de las distintas partidas y las guarda en la estructura de datos de cada jugador
void sumar_punto_historico(int total_jugador_1, int total_jugador_2, int & historico_jugador_1, int & historico_jugador_2){
  if(total_jugador_1 > total_jugador_2){
    historico_jugador_1++;
  } else if (total_jugador_2 > total_jugador_1){
    historico_jugador_2++;
  }
}