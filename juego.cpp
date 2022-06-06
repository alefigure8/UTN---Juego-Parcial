#include <iostream>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
#include "headers/menu.h"
using namespace std;


void comenzar_juego(Jugadores *jugador, int jugadorActual){

  int CANT_DADOS = 2;
  const int CANT_JUGADORES = 2;
  int JugadorActualLanzando;
  int RONDAS = 5;
  int contadorRondas = 1;
  char eleccion;
  string dibujo_dados;

  while(contadorRondas <= RONDAS){
    int totalRonda = 0;
    int lanzamientos = 1;
    cout << endl << "LANZA LOS DADOS EL JUGADOR " << jugador[jugadorActual].jugador << "\nPRESIONA CUALQUIER TECLA PARA LANZAR" <<  endl << endl;
    rlutil::anykey();

    JugadorActualLanzando = jugadorActual;

    while(jugadorActual == JugadorActualLanzando){
      int resultadoDados[CANT_JUGADORES][3];
      bool sonIguales = 0;
      int buscarUno;

      iniciarMatriz(jugador[jugadorActual].dados_jugadores, CANT_JUGADORES, CANT_DADOS);
      dados(jugador[jugadorActual].dados_jugadores, CANT_DADOS);
      cout << endl << endl << "GRAN CERDO" << endl;
      cout << " ----------------------------------------------------------------------- " << endl;

      cout << endl << jugador[0].jugador << ": " << jugador[0].puntaje << " trufas acumuladas             ";
      cout << jugador[1].jugador << ": " << jugador[1].puntaje << " trufas acumuladas" << endl;
      cout << endl << "TURNO DE "<< jugador[jugadorActual].jugador << endl;
      cout << "+=========================+" << endl;
      cout << "| RONDA #" << contadorRondas << "                |"<< endl ;
      cout << "| TRUFAS DE LA RONDA : " << totalRonda << "  |" << endl;
      cout << "| LANZAMIENTO #" << lanzamientos - 1 <<  "          |" << endl;
      cout << "+=========================+" << endl;
      cout << endl << "LANZAMIENTO #" << lanzamientos << endl << endl;
      /* Suma el resultado de los dados */

      jugador[jugadorActual].suma_dados = 0;
      jugador[jugadorActual].suma_dados += sumar_dados( jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      for (int j = 0; j < CANT_DADOS; j++){
        dibujo_dados += imprimirDados(jugador[jugadorActual].dados_jugadores[j]);
      }

      cout << dibujo_dados << endl;
      dibujo_dados = ""; //limpia el string dibujo_dados

      sonIguales = dados_iguales(jugador[jugadorActual].dados_jugadores, CANT_DADOS);
      buscarUno = dado_lado_uno(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      if(buscarUno == 3){

        // Sumamos los puntos del juego al otro jugador
        if(jugadorActual == 0){
          jugador[1].puntaje += jugador[jugadorActual].puntaje;
        } else {
          jugador[0].puntaje += jugador[jugadorActual].puntaje;
        }

        // Cede el turno al otro jugador
        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        // Mensaje
        cout << "TE HUNDISTE EN EL BARRO" << endl;
        cout << "TODOS TUS PUNTOS AHORA SON DEL OTRO CERDO" << endl;
        cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();
      } else if(buscarUno == 2){
        // Sumamos un dado mas
        if( CANT_DADOS == 2 ){
          CANT_DADOS++;
        }

        // Cedemos el turno
        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        // Reiniciamos el contador de puntajes general
        jugador[jugadorActual].puntaje = 0;
        totalRonda = 0;

        // Reiniciamos el contador de puntaje de la ronda
        jugador[jugadorActual].suma_dados = 0;

        // Mensaje
        cout << "TE HUNDISTE EN EL BARRO";
        cout << endl << "PIERDE LO ACUMULADO EN TODO EL JUEGO Y CEDES TU TURNO" << endl;
        cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else if (buscarUno == 1){ // HAY UN LADO CON UNO

        // Reiniciamos el contador de puntajes de la ronda
        totalRonda = 0;
        jugador[jugadorActual].suma_dados = 0;

        // Cedemos el turno
        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        // Mensaje
        cout << endl << "PIERDES TODO LO ACUMULADO EN LA RONDA Y CEDES TU TURNO" << endl;
        cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else if (sonIguales == 1){ // OINK

        // Suma x 2
        totalRonda += jugador[jugadorActual].suma_dados * 2;
        jugador[jugadorActual].oink++;

        // Mensaje
        cout << endl << "OINK" << endl;
        cout << "ESTAS OBLIGADO A TIRAR LOS DADOS DE NUEVO" << endl;
        // Mensaje del lanzamiento
        cout << endl << endl << "SUMASTE  " << jugador[jugadorActual].suma_dados * 2 << " TRUFAS!" << endl;

        cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else { // SUMA NORMAL
        totalRonda += jugador[jugadorActual].suma_dados;
        // Mensaje del lanzamiento
        cout << endl << endl << "SUMASTE  " << totalRonda << " TRUFAS!" << endl;

         /* Preguntar si se desea continuar */
        if(jugadorActual == JugadorActualLanzando){
          cout << endl << jugador[jugadorActual].jugador << " CONTINUAR LANZANDO LOS DADOS. " <<  " (S/N): "<<  endl << endl;
          cin >> eleccion;

          if(eleccion == 'N' || eleccion == 'n'){
            if(jugadorActual == 0){
              jugadorActual = 1;
            } else {
              jugadorActual = 0;
            }
          }
        }
      }

        // Si superamos los 50 puntos, sumamos un dado más
        if(jugador[jugadorActual].puntaje + totalRonda > 50 && CANT_DADOS == 2){
        CANT_DADOS++;
        }

        lanzamientos++;

        // Agregamos el maximo numero de lanzamientos
        if(jugador[jugadorActual].total_lanzamientos > lanzamientos){
          jugador[jugadorActual].total_lanzamientos = lanzamientos;
        }
      }

      // Sumar los puntos de la ronda al jugador al terminar
      jugador[JugadorActualLanzando].puntaje += totalRonda;

    }

    // Contador de rondas
    if(JugadorActualLanzando == 1){
      contadorRondas++;
    }


  // Mostrar el puntaje final
  cout << endl <<"===========================" << endl;
  cout << endl << jugador[0].jugador << " HIZO UN TOTAL DE " << jugador[0].puntaje;
  cout << endl << jugador[1].jugador  << " HIZO UN TOTAL DE " << jugador[1].puntaje;
  cout << endl <<"===========================" << endl;
  rlutil::anykey();
}