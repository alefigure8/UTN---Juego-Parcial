#include <string>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "headers/graficas.h"
#include "headers/jugadores.h"
using namespace std;

// Estructura de jugadores
struct Jugadores{
  string jugador;
  int puntaje;
  int oink;
  int total_lanzamientos;
  int maximo_lanzamientos_en_ronda;
  int dados_jugadores[3];
  int suma_dados;
  int juego_ganado;
  bool iniicializado;
};


// inicializar jugadores
Jugadores inicializar_estructura(){

  Jugadores jugador;
  jugador.jugador = "";
  jugador.puntaje = 0;
  jugador.oink = 0;
  jugador.total_lanzamientos = 0;
  jugador.maximo_lanzamientos_en_ronda = 0;
  jugador.suma_dados = 0;
  jugador.juego_ganado = 0;
  jugador.iniicializado = false;
  iniciar_vector(jugador.dados_jugadores, 3);

  return jugador;
};


// Funcion que pide los nombres de los jugadores
 void pedir_nombre(Jugadores *jugadores){
  for (int i = 0; i < 2; i++){
       // segun el turno cambia el dialogo
    string dialog = "";
    if(i == 0){
      dialog = "¿CUAL ES TU NOMBRE, CERDO UNO?";
    } else {
      dialog =  "TU TURNO,  CERDO DOS. ¿CUAL ES TU NOMBRE?";
    }

    // Imprime pantalla
    pantalla_generica(i, 1, dialog, "");
    rlutil::locate(1, 28); cout << ">> ";
    rlutil::locate(5, 28); cin >> jugadores[i].jugador;

    // Pasa los nombres a mayusculas
    transform(jugadores[i].jugador.begin(), jugadores[i].jugador.end(), jugadores[i].jugador.begin(), ::toupper);

    // Inicializa la estructura
    jugadores[i].iniicializado = true;
  }

 }


// Si se quiere seguir jugando, reinicia valores menos nombre y partidas ganadas
 void continuar_jugando(Jugadores &jugadores){

    jugadores.puntaje = 0;
    jugadores.oink = 0;
    jugadores.total_lanzamientos = 0;
    jugadores.maximo_lanzamientos_en_ronda = 0;
    jugadores.suma_dados = 0;

    for (int i = 0; i < 3; i++)
    {
      jugadores.dados_jugadores[i] = 0;
    }
 }