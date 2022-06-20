// #include <string>
// #include <iostream>
// #include <Windows.h>
// #include <algorithm>
// #include "headers/graficas.h"
// #include "headers/jugadores.h"
// using namespace std;


// // Funcion que pide los nombres de los jugadores
//  void pedir_nombre(Jugadores & jugadores, int x){

//     // segun el turno cambia el dialogo
//     string dialog = "";
//     if(x == 0){
//       dialog = "¿CUAL ES TU NOMBRE, CERDO UNO?";
//     } else {
//       dialog =  "TU TURNO, CERDO DOS. ¿CUAL ES TU NOMBRE?";
//     }

//     // Imprime pantalla
//     pantalla_generica(x, 1, dialog, "");
//     rlutil::locate(1, 28); cout << ">> ";
//     rlutil::locate(5, 28); cin >> jugadores.jugador;

//     // Pasa los nombres a mayusculas
//     transform(jugadores.jugador.begin(), jugadores.jugador.end(), jugadores.jugador.begin(), ::toupper);

//     // Inicializa la estructura
//     jugadores.iniicializado = true;
//  }


// // Si se quiere seguir jugando, reinicia valores menos nombre y partidas ganadas
//  void continuar_jugando(Jugadores & jugadores){

//     jugadores.puntaje = 0;
//     jugadores.oink = 0;
//     jugadores.total_lanzamientos = 0;
//     jugadores.maximo_lanzamientos_en_ronda = 0;
//     jugadores.suma_dados = 0;

//     for (int i = 0; i < 3; i++)
//     {
//       jugadores.dados_jugadores[i] = 0;
//     }
//  }