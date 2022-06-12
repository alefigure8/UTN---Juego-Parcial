#include <iostream>
#include <string>
#include "headers/rlutil.h"
#include "headers/jugadores.h"
#include "headers/dado.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
#include "headers/menu.h"
#include "headers/estadisticas.h"
using namespace std;

// Funcion principal
void comenzar_juego(Jugadores *jugador, int jugadorActual){

  int CANT_DADOS = 2;
  const int CANT_JUGADORES = 2;
  int JugadorActualLanzando;
  int primero_en_lanzar = jugadorActual;
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
      int buscarUno, TURNO;

      // color del jugador actual
      if(jugadorActual == 0){ 
        TURNO = COLOR::TURNO_JUGADOR_1;
      } else {
        TURNO = COLOR::TURNO_JUGADOR_2;
        }

      // Iniciamos matriz de dados
      iniciar_vector(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // lanzamiento de dados
      dados(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // pantalla de juego
      system("cls");
      lines();

      // imprimimos el puntaje de los jugadores
      puntaje_rondas(jugador[0].jugador, jugador[1].jugador, jugador[0].puntaje, jugador[1].puntaje, "TRUFAS ACUMULADAS");

      rlutil::locate(3, 7); colorTexto(TURNO); cout << "TUTRNO DE: " << jugador[jugadorActual].jugador << endl;

      // imprimimos los datos de la ronda
      imprimir_datos_ronda(contadorRondas, totalRonda, lanzamientos);

      rlutil::locate(3, 15);cout << "LANZAMIENTO #" << lanzamientos << endl;

      //Suma el resultado de los dados 
      jugador[jugadorActual].suma_dados = 0;
      jugador[jugadorActual].suma_dados += sumar_dados( jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // Imprime los dados en pantalla
      dibujar_dados(jugador[jugadorActual].dados_jugadores, CANT_DADOS);;

      // buscamos si los dados son iguales 
      sonIguales = dados_iguales(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // buscamos si hay ases 
      buscarUno = dado_lado_uno(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // Analisis lanzamiento de dados 
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
        rlutil::locate(30, 23); colorTexto(COLOR::MENSAJE); cout << "TE HUNDISTE EN EL BARRO" << endl;
        rlutil::locate(20, 25); colorTexto(COLOR::TEXTO); cout << "TODOS TUS PUNTOS AHORA SON DEL OTRO CERDO" << endl;
        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;

        rlutil::anykey();

      } else if(buscarUno == 2){

        // Sumamos un dado mas
        if( CANT_DADOS == 2 ){
          CANT_DADOS++;
          rlutil::locate(30, 26); colorTexto(COLOR::TEXTO); cout << "AHORA JUGAMOS CON TRES DADOS";
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
        rlutil::locate(30, 23); colorTexto(COLOR::MENSAJE); cout << "TE HUNDISTE EN EL BARRO";
        rlutil::locate(20, 24); colorTexto(COLOR::TEXTO); cout << "PIERDE LO ACUMULADO EN TODO EL JUEGO Y CEDES TU TURNO" << endl;
        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
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
        rlutil::locate(40, 23); colorTexto(COLOR::TEXTO); cout << "SALIO " << buscarUno << " AS" << endl;
        rlutil::locate(20, 25); colorTexto(COLOR::MENSAJE); cout << "PIERDES TODO LO ACUMULADO EN LA RONDA Y CEDES TU TURNO" << endl;
        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..." << endl;
        rlutil::anykey();

      } else if (sonIguales == 1){ // OINK

        // Suma x 2
        totalRonda += jugador[jugadorActual].suma_dados * 2;
        jugador[jugadorActual].oink++;
        lanzamientos++;


        // Mensaje
        rlutil::locate(40, 23); colorTexto(COLOR::MENSAJE); cout << "OINK" << endl;
        rlutil::locate(20, 24); colorTexto(COLOR::TEXTO); cout << "ESTAS OBLIGADO A TIRAR LOS DADOS DE NUEVO" << endl;
        // Mensaje del lanzamiento
        rlutil::locate(30, 26); colorTexto(COLOR::EXITO); cout << "SUMASTE  " << jugador[jugadorActual].suma_dados * 2 << " TRUFAS!" << endl;
        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else { // SUMA NORMAL
        totalRonda += jugador[jugadorActual].suma_dados;
        // Mensaje del lanzamiento
        rlutil::locate(30, 22); colorTexto(COLOR::EXITO); cout << "SUMASTE  " << jugador[jugadorActual].suma_dados << " TRUFAS!" << endl;

        // Si superamos los 50 puntos, sumamos un dado más
        if(jugador[jugadorActual].puntaje + totalRonda > 50 && CANT_DADOS == 2){
        CANT_DADOS++;
        rlutil::locate(30, 24); colorTexto(COLOR::TEXTO); cout << "SUMASTE MAS DE 50 TRUFAS. AHORA JUGAMOS CON TRES DADOS";
        }

         // Preguntar si se desea continuar 
         do
         {
          if(jugadorActual == JugadorActualLanzando){
          rlutil::locate(1, 27); colorTexto(COLOR::TEXTO); cout << jugador[jugadorActual].jugador << ", CONTINUA LANZANDO LOS DADOS. " <<  " (S/N): "<<  endl;
          rlutil::locate(1, 28); cout << ">> ";
         rlutil::locate(5, 28); cin >> eleccion;

          if(eleccion == 'N' || eleccion == 'n'){
            if(jugadorActual == 0){
              jugadorActual = 1;
            } else {
              jugadorActual = 0;
            }
          } else if (eleccion == 'S' || 's'){
            jugadorActual = JugadorActualLanzando;

            // si se desea seguir acumulamos lanzamiento
            lanzamientos++;
          } else {
             rlutil::locate(1, 26); colorTexto(COLOR::TEXTO); cout << jugador[jugadorActual].jugador << " RESPUESTA INCORRECTA.";
             Sleep(1000);
          }
        }
         } while (eleccion != 'S' && eleccion != 's' && eleccion != 'N' && eleccion != 'n');

      }
    } // fin del while de la tirada

    // Agregamos el maximo numero de lanzamientos
    if(lanzamientos > jugador[jugadorActual].total_lanzamientos){
      jugador[jugadorActual].total_lanzamientos = lanzamientos;
      cout << "El jugador " << jugador[jugadorActual].jugador << " ha alcanzado el maximo de lanzamientos: " << jugador[jugadorActual].total_lanzamientos << endl;
    }

    // Sumar los puntos de la ronda al jugador al terminar
    jugador[JugadorActualLanzando].puntaje += totalRonda;

    // Contador de rondas
    if(JugadorActualLanzando != primero_en_lanzar){
      contadorRondas++;
    }

  } // fin del while de la ronda
} // fin del juego
