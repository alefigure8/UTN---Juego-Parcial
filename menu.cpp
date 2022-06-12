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

void quien_empieza(Jugadores *jugador, int &jugadorActual);
void obtener_quien_empieza(Jugadores *jugador, int &jugadorActual, int &jugadorDadoMaximo, int &jugadorSumaMaxima);

enum OPCIONES {
  SALIR = 0,
  INICIAR_JUEGO = 1,
  ESTADISTICAS = 2,
  CREDITOS = 3
};


/* Funcion para el munnu de inicio */
void menuInicial(){
  int jugadorActual, eleccion;

  // Ocultar cursor
  rlutil::hidecursor();

  // Inicializar Struct de Jugadores
  Jugadores jugadores[2];

  // Pantalla de inicio
  do{

  if(jugadores[0].iniicializado != true){
    for (int i = 0; i < 2; i++){
      jugadores[i] = inicializar_estructura(); // Empezamos una partida nueva
    }
  } else {
    for (int i = 0; i < 2; i++){
      continuar_jugando(jugadores[i]); // continuamos una partida con los mismos jugadores
    }
  }

    system("cls");
    lines(); // Lineas de separacion con titulo
    endLines(1); // salto de linea
    colorTexto(15); imprimir_titulo();
    colorTexto(12); rlutil::locate(40, 17); cout << "JUGAR" << endl;
    colorTexto(10); rlutil::locate(40, 18); cout << "ESTADISTICA" << endl;
    colorTexto(10); rlutil::locate(40, 19); cout << "CERDITOS" << endl;
    colorTexto(10); rlutil::locate(40, 20); cout << "SALIR" << endl;
    colorTexto(9);  rlutil::locate(80, 22); cout << "V1.0.0" << endl;
    colorTexto(15); rlutil::locate(38, 17); cout << (char)187 << endl;
    colorTexto(7); rlutil::locate(30, 26); cout << "PRESIONE 'ENTER' PARA SELECCIONAR" << endl;
    endLines(4);

    // Obtener la eleccion del usuario
    eleccion = flecha_del_menu();

    // Eleccion de opcion
    switch (eleccion){
    case OPCIONES::INICIAR_JUEGO: {

      // pide nombre la primera vez que se juega
      if(jugadores[0].iniicializado != true){
        for (int i = 0; i < 2; i++)
        {
          pedir_nombre( jugadores[i], i );
        }
      }

      // determina quien empieza a jugar
      quien_empieza( jugadores, jugadorActual );

      // juego
      comenzar_juego( jugadores, jugadorActual );

      // Mostrar puntaje final
      pantalla_puntaje( jugadores );
    }
      break;
    case OPCIONES::ESTADISTICAS: {
      // pantalla de stadisticas del juego
     pantalla_estadistica( jugadores );
    }
      break;
    case OPCIONES::CREDITOS: {
      // pantalla de creditos
      pantalla_creditos();
    }
      break;
    default:
      rlutil::locate(1, 28); colorTexto(COLOR::MENSAJE); cout << "OPCION NO VALIDA";
      break;
    }
  }while(eleccion != OPCIONES::SALIR);

  // pantalla de salida
  pantalla_salida();
}


/* Funcion para determinar cual jugador comienza*/
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


/* Funcion que determina cual jugador empieza */
void obtener_quien_empieza(Jugadores *jugador, int &jugadorActual, int &jugadorDadoMaximo, int &jugadorSumaMaxima){
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