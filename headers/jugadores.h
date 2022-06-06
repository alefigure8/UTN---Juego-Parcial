#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "graficas.h"
using namespace std;

/* Estructura de jugadores */
struct Jugadores{
  string jugador;
  int puntaje;
  int oink;
  int total_lanzamientos;
  int maximo_lanzamientos_en_ronda;
  int dados_jugadores[3];
  int suma_dados;
};

/* Funcion que pide los nombres de los jugadores*/
 Jugadores pedir_nombre(int x){

   Jugadores jugadores;

    string dialog = "";

    // segun el turno cambia el dialogo
    if(x == 0){
      dialog = "¿Cuál es tu nombre, cerdo uno?";
    } else {
      dialog =  "Tu turno, cerdo dos, ¿cuál es tu nombre?";
    }

    pantalla_generica(x, 1, dialog, "");

    cin >> jugadores.jugador;

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