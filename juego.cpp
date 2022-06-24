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

// Funciones parcial
void es_primo(Jugadores &jugador,int *vector, int CANT_DADOS);

// Funcion principal del programa
void comenzar_juego(Jugadores *jugador, int jugadorActual){

  int CANT_DADOS = 2;
  const int CANT_JUGADORES = 2;
  int COLUMNA = 45;
  int JugadorActualLanzando;
  int primero_en_lanzar = jugadorActual;
  int RONDAS = 5;
  int contadorRondas = 1;
  char eleccion;
  bool salieron_primos = false;

  // Si las rondas son menores o iguales a 5, se puede seguir jugando
  while(contadorRondas <= RONDAS){
    int totalRonda = 0;
    int lanzamientos = 1;

    // guarda los dialogos del juego
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

      rlutil::locate(3, 7); colorTexto(TURNO); cout << "TUTRNO DE " << jugador[jugadorActual].jugador << endl;

      // imprimimos los datos de la ronda
      imprimir_datos_ronda(contadorRondas, totalRonda, lanzamientos - 1);

      rlutil::locate(3, 15);cout << "LANZAMIENTO #" << lanzamientos << endl;

      //Suma el resultado de los dados
      jugador[jugadorActual].suma_dados = 0;
      jugador[jugadorActual].suma_dados += sumar_dados( jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // Imprime los dados en pantalla
      dibujar_dados(jugador[jugadorActual].dados_jugadores, CANT_DADOS, 2);

      // buscamos si los dados son iguales
      sonIguales = dados_iguales(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // buscamos si hay ases
      buscarUno = dado_lado_uno(jugador[jugadorActual].dados_jugadores, CANT_DADOS);

      // Buscamos sin son primos
      if(salieron_primos == false){
        es_primo(jugador[jugadorActual], jugador[jugadorActual].dados_jugadores, CANT_DADOS);
      }

      /* ANALISIS DEL LANZAMIENTO */
      // si los dados son iguales y son ases
      if(buscarUno == 3){

        // Sumamos los puntos del juego al otro jugador
        if(jugadorActual == 0){
          jugador[1].puntaje += jugador[jugadorActual].puntaje;
        } else {
          jugador[0].puntaje += jugador[jugadorActual].puntaje;
        }

        // Reiniciamos el contador de puntajes general del jugador
        jugador[jugadorActual].puntaje = 0;
        totalRonda = 0;

        // Reiniciamos el contador de puntaje de la ronda del juagador
        jugador[jugadorActual].suma_dados = 0;

        // Cede el turno al otro jugador
        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        // Mensaje
        string dialogo_1 = "TE HUNDISTE EN EL BARRO";
        rlutil::locate(COLUMNA - (dialogo_1.length() / 2), 23); colorTexto(COLOR::MENSAJE); cout << dialogo_1 << endl;
        string dialogo_2 = "TODOS TUS PUNTOS AHORA SON DEL OTRO CERDO";
        rlutil::locate(COLUMNA - (dialogo_2.length() / 2), 25); colorTexto(COLOR::TEXTO); cout << dialogo_2 << endl;

        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else if(buscarUno == 2){ // si los dados son iguales y son ases

        // Sumamos un dado mas en el caso de que jueguen solo con dos dados
        if( CANT_DADOS == 2 ){
          CANT_DADOS++;
          string dialogo_3 = "AHORA JUGAMOS CON TRES DADOS";
          rlutil::locate(COLUMNA - (dialogo_3.length() / 2), 26); colorTexto(COLOR::TEXTO); cout << dialogo_3;
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
        string dialogo_1 = "TE HUNDISTE EN EL BARRO";
        rlutil::locate(COLUMNA - (dialogo_1.length() / 2), 23); colorTexto(COLOR::MENSAJE); cout << dialogo_1;
        string dialogo_2 = "PIERDE LO ACUMULADO EN TODO EL JUEGO Y CEDES TU TURNO";
        rlutil::locate(COLUMNA - (dialogo_2.length() / 2), 24); colorTexto(COLOR::TEXTO); cout << dialogo_2 << endl;

        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR" << endl;
        rlutil::anykey();

      } else if (buscarUno == 1){ // si sale un as

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
        string dialogo_1 = "SALIO UN AS";
        rlutil::locate(COLUMNA - (dialogo_1.length() / 2), 23); colorTexto(COLOR::TEXTO); cout << dialogo_1 << endl;
        string dialogo_2 = "PIERDES TODO LO ACUMULADO EN LA RONDA Y CEDES TU TURNO";
        rlutil::locate(COLUMNA - (dialogo_2.length() / 2), 25); colorTexto(COLOR::MENSAJE); cout << dialogo_2 << endl;

        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..." << endl;
        rlutil::anykey();

      } else if (sonIguales == 1){ // si hacemos OINK

        // Suma x 2
        totalRonda += jugador[jugadorActual].suma_dados * 2;
        jugador[jugadorActual].oink++;
        lanzamientos++;


        // Mensaje
        string dialogo_1 = "OINK";
        rlutil::locate(COLUMNA - (dialogo_1.length() / 2), 23); colorTexto(COLOR::MENSAJE); cout << dialogo_1 << endl;
        string dialogo_2 = "DUPLICAS LOS PUNTOS Y ESTÁS OBLIGADO A TIRAR LOS DADOS DE NUEVO";
        rlutil::locate(COLUMNA - (dialogo_2.length() / 2), 24); colorTexto(COLOR::TEXTO); cout << dialogo_2 << endl;

        // Mensaje del lanzamiento
        string dialogo_3 = "SUMASTE " + to_string(jugador[jugadorActual].suma_dados * 2) + " TRUFAS!";
        rlutil::locate(COLUMNA - (dialogo_3.length() / 2), 26); colorTexto(COLOR::EXITO); cout << dialogo_3 << endl;

        rlutil::locate(1, 28); colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..."  << endl;
        rlutil::anykey();

      } else { // suma normal de trufas

        // sumamos al total de la ronda la suma de los dados
        totalRonda += jugador[jugadorActual].suma_dados;

        // Mensaje del lanzamiento
        string dialogo_1 = "SUMASTE " + to_string(jugador[jugadorActual].suma_dados) + " TRUFAS!";
        rlutil::locate(COLUMNA - (dialogo_1.length() / 2), 23); colorTexto(COLOR::EXITO); cout << dialogo_1 << endl;

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
    if(lanzamientos > jugador[JugadorActualLanzando].total_lanzamientos){
      jugador[JugadorActualLanzando].total_lanzamientos = lanzamientos;
    }

    // Sumar los puntos de la ronda al jugador al terminar
    jugador[JugadorActualLanzando].puntaje += totalRonda;

    // Si ambos superar los 50 puntos, se juega con tres dados
    if(jugador[0].puntaje > 50 && jugador[1].puntaje > 50 && CANT_DADOS == 2){
      CANT_DADOS++;
    }

    // Contador de rondas
    if(JugadorActualLanzando != primero_en_lanzar){
      contadorRondas++;
    }

  } // fin del while de la ronda
} // fin del juego


//Funcion para imprimir si los dados son primos
void es_primo(Jugadores &jugador, int *vector , int CANT_DADOS){

  int cont_dados_primos = 0;

  for (int i = 0; i < CANT_DADOS; i++){
    int numero = vector[i];
    int cont = 0;

    for (int j = 1; j <= numero; j++){
      if(numero % j == 0){
        cont ++;
      }
    }

    if(cont == 2){
      cont_dados_primos++;
    }
  }

  if(cont_dados_primos == CANT_DADOS){
    jugador.primo = true;
    jugador.dados_primos = CANT_DADOS;
  }

}