/* Funcion para determinar cual jugador comienza*/
#include <Windows.h>
#include <iostream>
#include<locale>
#include <iomanip>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
#include "headers/juego.h"
#include "headers/menu.h"
#include "headers/estadisticas.h"
using namespace std;

// Funcion que determina cual jugador empieza
void obtener_quien_empieza(Jugadores *jugador, int &jugadorActual, int jugadorDadoMaximo, int jugadorSumaMaxima){
   if(jugador[0].suma_dados != jugador[1].suma_dados){ // si no hay empate
        if (jugadorSumaMaxima == 1){
        jugadorActual = 0;
      } else {
        jugadorActual = 1;
      }
    } else {
      if (jugadorDadoMaximo == 1){ // si hay empate, gana el dado maximo
        jugadorActual = 0;
      } else {
        jugadorActual = 1;
      }
    }
}

// Determinar quien empieza a jugar
void quien_empieza(Jugadores *jugador, int &jugadorActual){
  int CANT_DADOS = 2;
  int CANT_JUGADORES = 2;

  // inicializar dado
  for (int i = 0; i < 2; i++){
    iniciar_vector(jugador[i].dados_jugadores, CANT_DADOS);
  }

  int sumaMaxima = 0;
  int jugadorSumaMaxima;
  int dadoMaximo = 0;
  int jugadorDadoMaximo;

  string dialogo;

  for (int i = 0; i < CANT_JUGADORES; i++){

    // Pantalla 1
    if(i == 0){
      dialogo = ", ES TU TURNO PARA LANAZAR LOS DADOS.";
    } else {
      dialogo = ", AHORA ES TU TURNO PARA LANZAR LOS DADOS.";
    }
    pantalla_generica(i, 2, dialogo, jugador[i].jugador);
    // fin pantalla 1

    // generamos numeros random
    dados(jugador[i].dados_jugadores, CANT_DADOS);
    jugador[i].suma_dados = sumar_dados(jugador[i].dados_jugadores, CANT_DADOS);

    // buscamos el dado con mayor valor
    for (int j = 0; j < CANT_DADOS; j++){ 
      obtener_maximo(jugador[i].dados_jugadores[j], dadoMaximo, i, jugadorDadoMaximo);
    }

    // Pantalla 2
    dialogo = "HAS SUMADO " + to_string(jugador[i].suma_dados) + ", " + jugador[i].jugador + "!";
    rlutil::cls();; // Limpiar pantalla
    lines();
    puntaje(jugador[0].jugador, jugador[1].jugador, jugador[0].dados_jugadores, jugador[1].dados_jugadores, "PUNTOS"); // mostrar puntaje
    dibujar_dados(jugador[i].dados_jugadores, CANT_DADOS, 1); // Dibujar dados
    rlutil::locate(35, 24); cout << dialogo << endl; // Instruccion
    rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..." << endl;
    rlutil::anykey();
    // fin pantalla 2

    // buscamos el jugador con mayor suma
    obtener_maximo(jugador[i].suma_dados, sumaMaxima, i, jugadorSumaMaxima);
  }

  // Pantalla 3
  if(dados_coinciden(jugador[0].dados_jugadores, jugador[1].dados_jugadores)){
    dialogo = "HAN EMPATADO EN LOS DADOS";
    pantalla_generica(jugadorActual, 2, dialogo, jugador[jugadorActual].jugador);
    quien_empieza(jugador, jugadorActual);
  } else {
    // buscamos el jugador con mayor suma o el lado del dado mas alto
    obtener_quien_empieza(jugador, jugadorActual, jugadorDadoMaximo, jugadorSumaMaxima);
    dialogo = "HAS GANADO. ¡COMIENZA A JUGAR!" ;
    pantalla_generica(jugadorActual, 2, dialogo, jugador[jugadorActual].jugador);
  }
}

