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

  // Si las rondas son menores o iguales a 5, se puede seguir jugando
  while(contadorRondas <= RONDAS){
    int totalRonda = 0;
    int lanzamientos = 1;
    string dialogo;

    // pantalla de inicio de ronda
    dialogo = "LANZA TUS DADOS";
    pantalla_generica(jugadorActual, 2, dialogo, jugador[jugadorActual].jugador );

    // corte de control de rondas
    JugadorActualLanzando = jugadorActual;

    // si el jugador actual  decide continuar lanzando los dados
    while(jugadorActual == JugadorActualLanzando){
      int resultadoDados[CANT_JUGADORES][3];
      bool sonIguales = 0;
      int buscarUno;

      iniciarMatriz(jugador[jugadorActual].dados_jugadores, CANT_JUGADORES, CANT_DADOS);
      dados(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      system("cls");
      lines();
      puntaje_rondas(jugador[0].jugador, jugador[1].jugador, jugador[0].puntaje, jugador[1].puntaje, "TRUFAS ACUMULADAS");
      cout << "TUTRNO DE: " << jugador[jugadorActual].jugador << endl;
      pantalla_juego(contadorRondas, totalRonda, lanzamientos);
      cout << endl << "LANZAMIENTO #" << lanzamientos << endl << endl;

      /* Suma el resultado de los dados */
      jugador[jugadorActual].suma_dados = 0;
      jugador[jugadorActual].suma_dados += sumar_dados( jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      /* Imprime los dados en pantalla*/
      dibujar_dados(jugador[jugadorActual].dados_jugadores, CANT_DADOS);;

      /* buscamos si los dados son iguales */
      sonIguales = dados_iguales(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      /* buscamos si hay ases */
      buscarUno = dado_lado_uno(jugador[jugadorActual].dados_jugadores, CANT_DADOS);
      
      /* Analisis lanzamiento de dados */
      if(buscarUno == 3){

        // Sumamos los puntos del juego al otro jugador
        if(jugadorActual == 0){
          jugador[1].puntaje += jugador[jugadorActual].puntaje;
        } else {
          jugador[0].puntaje += jugador[jugadorActual].puntaje;
        }

        // Reiniciamos el contador de puntajes general
        jugador[jugadorActual].puntaje = 0;
        totalRonda = 0;

        // Reiniciamos el contador de puntaje de la ronda
        jugador[jugadorActual].suma_dados = 0;

        // Cede el turno al otro jugador
        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        // Mensaje
        colorTexto(COLOR::MENSAJE); cout <<endl << "TE HUNDISTE EN EL BARRO" << endl;
        colorTexto(COLOR::TEXTO); cout << "TODOS TUS PUNTOS AHORA SON DEL OTRO CERDO" << endl;
        colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;

        rlutil::anykey();
      } else if(buscarUno == 2){
        // Sumamos un dado mas
        if( CANT_DADOS == 2 ){
          CANT_DADOS++;
        }

       // Reiniciamos el contador de puntajes general
        jugador[jugadorActual].puntaje = 0;
        totalRonda = 0;

        // Reiniciamos el contador de puntaje de la ronda
        jugador[jugadorActual].suma_dados = 0;

        // Cedemos el turno
        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        // Mensaje
        colorTexto(COLOR::MENSAJE); cout << "TE HUNDISTE EN EL BARRO";
        colorTexto(COLOR::TEXTO); cout << endl << "PIERDE LO ACUMULADO EN TODO EL JUEGO Y CEDES TU TURNO" << endl;
        colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
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
        colorTexto(COLOR::MENSAJE); cout << endl << "PIERDES TODO LO ACUMULADO EN LA RONDA Y CEDES TU TURNO" << endl;
        colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..." << endl;
        rlutil::anykey();

      } else if (sonIguales == 1){ // OINK

        // Suma x 2
        totalRonda += jugador[jugadorActual].suma_dados * 2;
        jugador[jugadorActual].oink++;

        // Mensaje
        colorTexto(COLOR::MENSAJE); cout << endl << "OINK" << endl;
        colorTexto(COLOR::TEXTO); cout << "ESTAS OBLIGADO A TIRAR LOS DADOS DE NUEVO" << endl;
        // Mensaje del lanzamiento
        colorTexto(COLOR::TEXTO); cout << endl << endl << "SUMASTE  " << jugador[jugadorActual].suma_dados * 2 << " TRUFAS!" << endl;
        colorTexto(COLOR::CONTINUAR);rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else { // SUMA NORMAL
        totalRonda += jugador[jugadorActual].suma_dados;
        // Mensaje del lanzamiento
        colorTexto(COLOR::TEXTO); cout << endl << endl << "SUMASTE  " << totalRonda << " TRUFAS!" << endl;

         /* Preguntar si se desea continuar */
        if(jugadorActual == JugadorActualLanzando){
          colorTexto(COLOR::TEXTO); cout << endl << jugador[jugadorActual].jugador << " CONTINUAR LANZANDO LOS DADOS. " <<  " (S/N): "<<  endl << endl;
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

      // Contador de rondas
      if(JugadorActualLanzando == 1){
        contadorRondas++;
      }

    }


  // Mostrar el puntaje final
  cout << endl <<"===========================" << endl;
  cout << "HITO" << "\t" <<  jugador[0].jugador  << "\t" <<jugador[1].jugador<<endl;
  cout << endl <<"===========================" << endl;
  cout << endl << "Más trufas en total " << "\t" << jugador[0].puntaje << "\t " << jugador[1].puntaje;
  cout << endl << "Cada 50 Trufas " << "\t" << jugador[0].puntaje << "\t " << jugador[1].puntaje;
  cout << endl << "Oinks " << "\t" << jugador[0].oink << "\t " << jugador[1].oink;
  cout << endl << "Cerdo codicioso " << "\t" << jugador[0].total_lanzamientos << "\t " << jugador[1].total_lanzamientos;
  cout << endl <<"===========================" << endl;
  rlutil::anykey();
}