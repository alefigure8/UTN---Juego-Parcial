#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include "headers/rlutil.h"
#include "headers/helpers.h"
#include "headers/graficas.h"
using namespace std;


// Colores que se utilizan en todo el juego
enum COLOR {
  JUGADOR_1 = 159,
  JUGADOR_2 = 207,
  TURNO_JUGADOR_1 = 9,
  TURNO_JUGADOR_2 = 12,
  CERDO = 13,
  TITULO = 15,
  LINEAS = 192,
  TEXTO = 15,
  RECUADRO = 252,
  MENSAJE = 12,
  CONTINUAR = 10,
  EXITO = 10,
};

// Funcion que imprime el titulo del jeugo
void imprimir_titulo(){
 colorTexto(COLOR::TITULO); rlutil::locate(20, 3); cout << R"(


                       ____                    ____             _
                      / ___|_ __ __ _ _ __    / ___|___ _ __ __| | ___
                     | |  _| '__/ _` | '_ \  | |   / _ \ '__/ _` |/ _ \
                     | |_| | | | (_| | | | | | |__|  __/ | | (_| | (_) |
                      \____|_|  \__,_|_| |_|  \____\___|_|  \__,_|\___/
    )" << endl;
}


// Funcion para enmarcar los textos dependiendo el color de cada jugador
 void enmarcar_texto(int jugador, string nombre, string dialogo){

   int color;
   string texto = nombre + " " + dialogo;
   int largo = texto.length();
   int columna = 45 - (largo / 2);

   if(jugador == 0){
     color = COLOR::JUGADOR_1;
   } else {
     color = COLOR::JUGADOR_2;
   }

    for (int i = 0; i < 5 ; i++){
      for (int j = 0; j < largo + 8; j++){
        if(i == 0 || i == 4){

          if(j == 0 && i == 0){
            colorTexto(color); rlutil::locate(columna, 21); cout << " ";
          } else if (j == 0 && i == 4) {
            colorTexto(color); rlutil::locate(columna, 25); cout << " ";
          } else {
             colorTexto(color); cout << " ";
          }

          if(j == largo + 7){
            cout << endl;
          }
        } else if(i == 1 || i == 3){
          if(j == 0 || j == largo + 7){
            if(j == 0 && i == 1){
              colorTexto(color); rlutil::locate(columna, 22); cout << " ";
            } else if (j == 0 && i == 3) {
              colorTexto(color); rlutil::locate(columna, 24); cout << " ";
            } else {
              colorTexto(color); cout << " ";
            }

            if(j == largo + 7){
              cout << endl;
            }
          } else {
            cout << " ";
          }
        } else if( i == 2){
          rlutil::locate(columna, 23); cout << "    ";
          cout  << dialogo << " "<< nombre;
          colorTexto(color); cout << "    " << endl;
          j = largo + 8;
        }

      }
    }
    colorTexto(COLOR::TEXTO);
 }


 // Funcion que dibuja al cerdo numero 1
 void cerdo(int x, string dialogo, string nombre){
 colorTexto(COLOR::CERDO); rlutil::locate(30, 3); cout << R"(
                                 _                           _
                                 ;`.                       ,'/
                                 |`.`-.      _____      ,-;,'|
                                 |  `-.\__,-'     `-.__//'   |
                                 |     `|               \ ,  |
                                 `.  ```                 ,  .'
                                   \_`      .         ,  `_/
                                     \    -  `   ,   - ` /
                                      | '  |  ____  | , |
                                      |     ,'    `.    |
                                      |    (  O' O  )   |
                                      `.    \__,.__/   ,'
                                        `-._        _,'
                                            `------')";

  endLines(3);
  enmarcar_texto(x, dialogo, nombre);
 }

  // Funcion que dibuja al cerdp numero 2
  void cerdo2(int x, string dialogo, string nombre){
  colorTexto(COLOR::CERDO); rlutil::locate(30, 3); cout << R"(
                                  _                           _
                                  ;`.                       ,'/
                                  |`.`-.      _____      ,-;,'|
                                  |  `-.\__,-'     `-.__//'   |
                                  |     `|               \ ,  |
                                  `.  ```  _              ,  .'
                                    \_`     `.     ,   ,  `_/
                                      \    0  `   ,   0 ` /
                                       | '  |  ____  | , |
                                       |     ,'    `.    |
                                       |    (  O' O  )   |
                                       `.    \__,.__/   ,'
                                         `-._  \__/   _,'
                                             `------')";

  endLines(3);
  enmarcar_texto(x, dialogo, nombre);
 }


// Funcion que separa el texto con un linea de puntos
void separador(int COLUMNA, int FILA, int CANTIDAD){
  for (int i = 0; i < CANTIDAD; i++){
   colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA + i, FILA); cout << "-";
  }
}


 // Funcion que imprime las lineas superiores e inferiores de la pantalla del juego
 void lines(){

    rlutil::locate(1, 1);
    for (int i = 0; i < 98; i++){
      colorTexto(COLOR::LINEAS); cout << " ";
    }

    rlutil::locate(1, 2); colorTexto(COLOR::TITULO); cout << "GRAN CERDO" << endl;

    rlutil::locate(1, 29);
    for (int i = 0; i < 98; i++){
      colorTexto(COLOR::LINEAS); cout << " ";
    }
    colorTexto(COLOR::TEXTO);
 }


 // Funcion que imprime puntaje de jugadores en la ronda que detemina quien empieza
 void puntaje(string nombre_jugador_1, string nombre_jugador_2, int *dados_1, int *dados_2,  string texto){
    int dado_1_total = sumar_dados(dados_1, 2);
    int dado_2_total = sumar_dados(dados_2, 2);
    rlutil::locate(10, 6); cout << nombre_jugador_1 << ": " << dado_1_total <<  " " << texto << " ( " << dados_1[0] << ", " << dados_1[1] << " )";
    cout << "\t\t\t\t" << nombre_jugador_2 << ": " << dado_2_total << " " << texto << " ( " << dados_2[0] << ", " << dados_2[1] << " )" << endl;
    separador(9, 7, 75);
 }


  // Funcion que imprime puntaje de jugadores en las rondas del juego
 void puntaje_rondas(string nombre_jugador_1, string nombre_jugador_2, int puntos_jugador_1, int puntos_jugador_2,  string texto){
   int COLUMNA = 7;
   int FILA = 4;
    rlutil::locate(COLUMNA, FILA); cout << "\t" << nombre_jugador_1 << ": " << puntos_jugador_1 <<  " " << texto;
    cout << "\t\t\t" << nombre_jugador_2 << ": " << puntos_jugador_2 << " " << texto  << endl;
    separador(COLUMNA, FILA + 1, 72);
 }


 // Funcion de pantalla generica para el juego
 void pantalla_generica(int i, int pantalla_cerdo, string dialogo, string nombre){
    system("cls"); // Limpiar pantalla
    lines();
    endLines(2);

    if(pantalla_cerdo == 1){
      cerdo(i, dialogo, nombre);
    } else if(pantalla_cerdo == 2){
      cerdo2(i, dialogo, nombre);
    }
    endLines(2);

    if(pantalla_cerdo == 2){
      colorTexto(COLOR::CONTINUAR); cout << "PRESIONA CUALQUIER TECLA PARA CONTINUAR..." << endl;
    }

    endLines(1);

    if(pantalla_cerdo == 2){
      rlutil::anykey();
    }
 }


// Pantalla que marca rondas, lanzamientos, y puntos de los jugadores
void imprimir_datos_ronda (int contadorRondas, int totalRonda, int lanzamientos){
  int COLUMNA = 3;
  string ronda_texto = "  RONDA #" + to_string (contadorRondas);
  string trufas_texto = "  TRUFAS DE LA RONDA: " + to_string (totalRonda);
  string lanzamientos_texto = "  LANZAMIENTOS: " + to_string (lanzamientos);

  colorTexto(COLOR::RECUADRO);

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      if(i == 0 || i == 4){
        if(i == 0){
          rlutil::locate(COLUMNA + j, 9);
        } else {
          rlutil::locate(COLUMNA  + j, 13);
        }
        cout << " ";
      } else if( i == 1){
        int cantidad = ronda_texto.length();
        if(j < cantidad){
          rlutil::locate(COLUMNA + j, 10); cout << ronda_texto[j];
        } else {
         rlutil::locate(COLUMNA + j, 10); cout << " ";
        }
      } else if( i == 2){
        int cantidad = trufas_texto.length();
        if(j < cantidad){
         rlutil::locate(COLUMNA + j, 11); cout << trufas_texto[j];
        } else {
          rlutil::locate(COLUMNA + j, 11);cout << " ";
        }
      } else if( i == 3){
        int cantidad = lanzamientos_texto.length();
        if(j < cantidad){
          rlutil::locate(COLUMNA + j, 12); cout << lanzamientos_texto[j];
        } else {
          rlutil::locate(COLUMNA + j, 12); cout << " ";
        }
      }

      if(j == 29){
        cout << endl;
      }
    }
  }

  colorTexto(COLOR::TEXTO);
}

// Funcion que muestra la flecha en la pantalla inicial para seleccionar opciones
int flecha_del_menu(){
    int key ;
    int eleccion;
    int posicion_actual = 17;
    int posicion_inicial = 17;
    int posicion_final = 20;
     do
    {
      key = rlutil::getkey();
      switch(key){
        case 15: // Flecha arriba
          if(posicion_actual < posicion_final){
            posicion_actual = posicion_actual + 1;
            colorTexto(COLOR::TEXTO); rlutil::locate(38, posicion_actual); cout << (char)187 << endl;
            rlutil::locate(38, posicion_actual - 1); cout << " " << endl;
          }
          break;
        case 14: // Flecha abajo
          if(posicion_actual > posicion_inicial){
            posicion_actual = posicion_actual - 1;
            colorTexto(COLOR::TEXTO); rlutil::locate(38, posicion_actual); cout << (char)187 << endl;
            rlutil::locate(38, posicion_actual + 1); cout << " " << endl;
          }
          break;
        case 1: // Enter
          eleccion = posicion_actual - 16;
          if(eleccion == 4){
            eleccion = 0;
          }
          break;
      }
    } while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 0);

    return eleccion;
}


// Funcion que muestra una pantalla generica para las reglas del juego
void mostrar_reglas_pantalla_generica(int regla, string texto, string texto_2, int *dado, int cant_dados){

  int largo_1 = texto.length();
  int largo_2 = texto_2.length();
  int COLUMNA_1 = 45 - (largo_1 / 2);
  int COLUMNA_2 = 45 - (largo_2 / 2);

  system("cls");
  lines();

  colorTexto(COLOR::MENSAJE);
  rlutil::locate(36, 7); cout << "REGLAS DEL JUEGO" << endl;

  rlutil::locate(COLUMNA_1, 11);
  colorTexto(COLOR::CONTINUAR);
  cout << regla;
  cout <<  texto;

  dibujar_dados(dado, cant_dados, 1);

  colorTexto(COLOR::TEXTO);
  rlutil::locate(COLUMNA_2, 23);
  cout << texto_2 << endl;

  rlutil::locate(1, 28);
  colorTexto(COLOR::CONTINUAR);
  cout << "PRESIONA CUALQUIER TECLA PARA PASAR A LA SIGUIENTE PANTALLA >>" << endl;
  rlutil::anykey();
}


// Funcion que muestra la tabla de los puntos en las reglas
void tabla_de_puntos(){

  int COLUMNA_JUGADOR_1 = 30;
  int COLUMNA_JUGADOR_2 = 55;
  int FILA_JUGADORES = 11;
  int FILA_PUNTOS = 14;
  string JUGADOR_1 =  "HITO" ;
  string JUGADOR_2 ="PUNTOS DE VIDA";
  string TITULO = "ESTADISTICAS";

  rlutil::cls();
  lines();
  colorTexto(COLOR::MENSAJE);rlutil::locate(36, 4); cout << "REGLAS DEL JUEGO" << endl;
  colorTexto(COLOR::TEXTO);rlutil::locate(32, 7); cout << "TABLA DE PUNTOS DE VIDA" << endl;
  separador(10, 10, 80);
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, FILA_JUGADORES); cout << JUGADOR_1;
  colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, FILA_JUGADORES); cout << JUGADOR_2;
  separador(10, 12, 80);
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, FILA_PUNTOS + 1); cout << "Mas trufas en total";
  colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, FILA_PUNTOS + 1); cout << "5 PDV";
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, FILA_PUNTOS + 3); cout << "Cada 50 trufas";
  colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, FILA_PUNTOS + 3); cout << "1 PDV";
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, FILA_PUNTOS + 5); cout << "Oink";
  colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, FILA_PUNTOS + 5); cout << "2 PDV * Cantidad de Oinks";
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_JUGADOR_1, FILA_PUNTOS + 7); cout << "Cerdo codicioso";
  colorTexto(COLOR::TURNO_JUGADOR_2); rlutil::locate(COLUMNA_JUGADOR_2, FILA_PUNTOS + 7); cout << "3 PDV";

  rlutil::locate(1, 28);
  colorTexto(COLOR::CONTINUAR);
  cout << "PRESIONAR CUALQUIER TECLA PARA EMPEZAR A JUGAR" << endl;
  rlutil::anykey();
}


// Funcion que muestra las reglas del juego
void mostrar_reglas(){
  system("cls");
  lines();

  rlutil::locate(1, 28);
  colorTexto(COLOR::CONTINUAR);
  cout << "PRESIONA CUALQUIER TECLA PARA PASAR A LA SIGUIENTE REGLA" << endl;

  rlutil::locate(36, 6);
  colorTexto(COLOR::MENSAJE);
  cout << "REGLAS DEL JUEGO" << endl;

  colorTexto(COLOR::TEXTO);
  endLines(2);
  cout << "1. Gran Cerdo es un juego de dados de dos jugadores en el que intervienen el azar y la codicia." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "2. El objetivo del juego es sumar la mayor cantidad de puntos de victoria en un total de 5 rondas." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "3. Se juega con dos o tres dados de seis caras por cada jugador." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "4. Se juegan cinco rondas por jugador y en cada una se dispone de ilimitados lanzamientos." << endl;
  rlutil::anykey();

  endLines(1);
  cout << "5. El juego utiliza dos dados hasta que ambos cerdos superen las 50 trufas o saque dos ases." << endl;
  rlutil::anykey();

  endLines(1);
  colorTexto(COLOR::CONTINUAR);
  cout << "SEGUIR A LA SIGUIENTE PANTALLA >>" << endl;
  rlutil::anykey();

  // Regla 5
  string texto_1 = ".  Si las caras son distintas y ninguna de ellas es un as. ";
  string texto_2 = "El cerdo acumula trufas según la suma de las caras. Por ejemplo: 9 trufas." ;
  int dado_ejemplo[2] = {4, 5};

  mostrar_reglas_pantalla_generica(6, texto_1, texto_2, dado_ejemplo, 2);

  // Regla 6
  texto_1 = ". Si las caras son iguales entre sí y no son ases.";
  texto_2 = "El cerdo hizo un OINK y duplicas las suma de las caras. Por ejemplo: 12 trufas." ;
  int dado_ejemplo_2[2] = {3, 3};

  mostrar_reglas_pantalla_generica(7, texto_1, texto_2, dado_ejemplo_2, 2);

  // Regla 7
  texto_1 = ". Si las caras son distintas entre sí y hay un as.";
  texto_2 = "Pierde todas las trufas acumuladas de la ronda actual." ;
  int dado_ejemplo_3[2] = {4, 1};

  mostrar_reglas_pantalla_generica(8, texto_1, texto_2, dado_ejemplo_3, 2);

  // Regla 8
  texto_1 = ". Si dos de las caras son iguales entre sí y son ases.";
  texto_2 = "El cerdo se HUNDE EN EL BARRO y pierde todas las trufas acumuladas en el juego." ;
  int dado_ejemplo_4[2] = {1, 1};

  mostrar_reglas_pantalla_generica(9, texto_1, texto_2, dado_ejemplo_4, 2);

  // Regla 9
  texto_1 = ". Si se está lanzando con tres dados y son ases.";
  texto_2 = "El cerdo pierde todo las trufas del juego y se les pasa al otro jugador." ;
  int dado_ejemplo_5[3] = {1, 1, 1};

  mostrar_reglas_pantalla_generica(10, texto_1, texto_2, dado_ejemplo_5, 3);

  // pantalla de puntos
  tabla_de_puntos();
}


// Pantalla de Bienvenida
void mostar_bienvenida(){
  int COLUMNA = 5;
  char eleccion;
  string dialogo = "BIENVENIDOS A GRAN CERDO";
  pantalla_generica(1, 2, dialogo, "");

  dialogo = "ANTES DE COMENZAR. ¿QUIERES CONOCER LAS REGLAS DEL JUEGO? (S/N)";

   do{
    system("cls"); // Limpiar pantalla
    lines();
    endLines(2);

    cerdo(1, dialogo, "");

    rlutil::locate(COLUMNA, 27); cout << ">> ";
    colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA + 4, 27); cin >> eleccion;
   } while (eleccion != 's' && eleccion != 'S' && eleccion != 'n' && eleccion != 'N');

   if( eleccion == 's' || eleccion == 'S'){
    mostrar_reglas();
   }
}


// Funcion que pregunta al usuario si quiere salir del juego
int preguntar_salida(){
  char eleccion;

 do{
  system("cls");
  lines();

  rlutil::locate(35, 15);
  colorTexto(COLOR::TEXTO);
  cout << "¿SEGURO DESEAS SALIR DEL JUEGO? (S/N)";
  colorTexto(COLOR::CONTINUAR);
  rlutil::locate(35, 17);
  cout << ">>";
  rlutil::locate(39, 17);
  cin >> eleccion;
 } while (eleccion != 's' && eleccion != 'S' && eleccion != 'n' && eleccion != 'N');

  if( eleccion == 's' || eleccion == 'S'){
    return 0;
  }

  return 5;
}


// Funcion que muestra la pantalla de salida del juego
void pantalla_salida(){
  system("cls");
  lines();
  rlutil::locate(35, 15);
  colorTexto(COLOR::TEXTO);
  cout << "GRACIAS POR JUGAR";
  rlutil::locate(34, 18);
  colorTexto(COLOR::CONTINUAR);
  cout << "SALIENDO DEL JUEGO...";
  Sleep(1500);
  system("cls");

}

// Funcion que muestra la pantalla con los créditos del juego
void pantalla_creditos(){
  int COLUMNA_1 = 20;
  int COLUMNA_2 = 42;
  int COLUMNA_3 = 62;
  int FILA_DESCRIPCION = 8;
  int FILA_INTEGRANTE = 10;
  string TITULO = "CREDITOS";

  rlutil::cls();
  lines();
  colorTexto(COLOR::MENSAJE); rlutil::locate(41, 5); cout << TITULO << endl;
  separador(10, 7, 80);
  colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA_1, FILA_DESCRIPCION); cout << "LEGAJO";
  colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA_2, FILA_DESCRIPCION); cout << "NOMBRE";
  colorTexto(COLOR::TEXTO); rlutil::locate(COLUMNA_3, FILA_DESCRIPCION); cout << "APELLIDO";
  separador(10, 9, 80);
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_1, FILA_INTEGRANTE); cout << "27017";
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_2, FILA_INTEGRANTE); cout << "ALEJANDRO";
  colorTexto(COLOR::TURNO_JUGADOR_1); rlutil::locate(COLUMNA_3, FILA_INTEGRANTE); cout << "GOMEZ NIETO";
  colorTexto(COLOR::CONTINUAR); rlutil::locate(1, 28); cout << "PRESIONA CUALQUIER TECLA PARA REGRESAL AL MENÚ" << endl;
  rlutil::anykey();
}
