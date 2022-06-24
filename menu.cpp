#include <Windows.h>
#include <iostream>
#include<locale>
#include <iomanip>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/jugadores_estadistica.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
#include "headers/juego.h"
#include "headers/menu.h"
#include "headers/estadisticas.h"
#include "headers/quien_empieza.h"
using namespace std;

enum OPCIONES {
  SALIR = 0,
  INICIAR_JUEGO = 1,
  ESTADISTICAS = 2,
  CREDITOS = 3,
};


/* Funcion para el munnu de inicio */
void menuInicial(){
  int jugadorActual, eleccion, eleccion_salida = 1;

  // Ocultar cursor
  rlutil::hidecursor();

  // Inicializar Struct de Jugadores
  Jugadores jugadores[2];

  // Inicializar Struct de Jugadores Estadistica
  Jugadores_estadistica jugadores_estadistica[15];

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
    colorTexto(10); rlutil::locate(40, 19); cout << "CRÉDITOS" << endl;
    colorTexto(10); rlutil::locate(40, 20); cout << "SALIR" << endl;
    colorTexto(9);  rlutil::locate(80, 23); cout << "V1.1.0" << endl;
    colorTexto(15); rlutil::locate(38, 17); cout << (char)187 << endl;
    colorTexto(7); rlutil::locate(30, 26); cout << "PRESIONE 'ENTER' PARA SELECCIONAR" << endl;
    endLines(4);

    // Obtener la eleccion del usuario
    eleccion = flecha_del_menu();

    // Eleccion de opcion
    switch (eleccion){
    case OPCIONES::INICIAR_JUEGO: {

      // Primera vez que se juega
      if(jugadores[0].iniicializado != true){
        mostar_bienvenida();
        pedir_nombre( jugadores );
      }

      // determina quien empieza a jugar
      quien_empieza( jugadores, jugadorActual );

      // juego
      comenzar_juego( jugadores, jugadorActual );

      // Mostrar puntaje final
      pantalla_puntaje( jugadores, jugadores_estadistica );
    }
      break;
    case OPCIONES::ESTADISTICAS: {
      // pantalla de stadisticas del juego
     pantalla_estadistica( jugadores_estadistica );
    }
      break;
    case OPCIONES::CREDITOS: {
      // pantalla de creditos
      pantalla_creditos();
    }
      break;
    case OPCIONES::SALIR: {
      eleccion_salida = preguntar_salida();
    }
      break;
    default:
      rlutil::locate(1, 28); colorTexto(COLOR::MENSAJE); cout << "OPCION NO VALIDA";
      break;
    }
  }while(eleccion_salida != OPCIONES::SALIR);

  // pantalla de salida
  pantalla_salida();
}