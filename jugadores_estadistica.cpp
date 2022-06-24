#include <string>
#include "headers/jugadores.h"
#include "headers/jugadores_estadistica.h"
using namespace std;

struct Jugadores_estadistica{
  string jugador = "";
  int pdv = 0;
  bool inicializado = false;
};

void cargar_jugadores_estadisticas(string jugador, int pdv, Jugadores_estadistica *jugador_estadistica){
  for (int i = 0; i < 15; i++){
    if(jugador_estadistica[i].inicializado == false){
      jugador_estadistica[i].jugador = jugador;
      jugador_estadistica[i].pdv = pdv;
      jugador_estadistica[i].inicializado = true;
      return;
    }
  }
}

// Funcion para ordenar por PDV al vector de jugadores que ganaron
void ordenar_vector(Jugadores_estadistica *jugador_estadistica, int cantidad){
  int aux_pdv;
  string aux_nombre;
  bool aux_inicializado;
  for (int i = 0; i < cantidad; i++){
    for (int j = 0; j < cantidad - 1; j++){
      if(jugador_estadistica[j].pdv < jugador_estadistica[j + 1].pdv && jugador_estadistica[i].inicializado == true){
        aux_pdv = jugador_estadistica[j].pdv;
        aux_nombre = jugador_estadistica[j].jugador;
        aux_inicializado = jugador_estadistica[j].inicializado;
        jugador_estadistica[j].pdv = jugador_estadistica[j + 1].pdv;
        jugador_estadistica[j].jugador = jugador_estadistica[j + 1].jugador;
        jugador_estadistica[j].inicializado = jugador_estadistica[j + 1].inicializado;
        jugador_estadistica[j + 1].pdv = aux_pdv;
        jugador_estadistica[j + 1].jugador = aux_nombre;
        jugador_estadistica[j + 1].inicializado = aux_inicializado;
      }
    }
  }
}