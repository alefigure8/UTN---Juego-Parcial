#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "graficas.h"
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

  for (int i = 0; i < 3; i++){
    jugador.dados_jugadores[i] = 0;
  }

  return jugador;
}


// Funcion que pide los nombres de los jugadores
 Jugadores pedir_nombre(int x){
   // Inicia la estructura de jugadores
   Jugadores jugadores;

    // segun el turno cambia el dialogo
    string dialog = "";
    if(x == 0){
      dialog = "�CUAL ES TU NOMBRE, CERDO UNO?";
    } else {
      dialog =  "TU TURNO,  CERDO DOS. �CUAL ES TU NOMBRE?";
    }

    // Imprime pantalla
    pantalla_generica(x, 1, dialog, "");

    rlutil::locate(1, 28); cout << ">> ";
    rlutil::locate(5, 28); cin >> jugadores.jugador;

    // Pasa los nombres a mayusculas
    transform(jugadores.jugador.begin(), jugadores.jugador.end(), jugadores.jugador.begin(), ::toupper);

    // Inicializamos los valores del jugador
    jugadores.puntaje = 0;
    jugadores.oink = 0;
    jugadores.total_lanzamientos = 0;
    jugadores.maximo_lanzamientos_en_ronda = 0;
    jugadores.suma_dados = 0;
    jugadores.juego_ganado = 0;
    jugadores.iniicializado = true;
    for (int i = 0; i < 3; i++)
    {
      jugadores.dados_jugadores[i] = 0;
    }

    return jugadores;
 }

// Si se quiere seguir jugando, reinicia valores menos nombre y partidas ganadas
 Jugadores continuar_jugando(){

    Jugadores jugadores;

    jugadores.puntaje = 0;
    jugadores.oink = 0;
    jugadores.total_lanzamientos = 0;
    jugadores.maximo_lanzamientos_en_ronda = 0;
    jugadores.suma_dados = 0;

    for (int i = 0; i < 3; i++)
    {
      jugadores.dados_jugadores[i] = 0;
    }

    return jugadores;
 }