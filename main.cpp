

#include <iostream>
#include <Windows.h>
using namespace std;

/* FUNCIONES */

int menuInicial();
int jugar();
void preguntarNombre();
void quienEmpieza();
void dados(int *a, int b);
void iniciarMatriz(int matriz[2][2], int filas, int columnas);

/* Jugadores */
string jugadores[2];
string jugadorActual;

int main (){
  int eleccion;
  eleccion = menuInicial(); // Obtener respuesta del jugador

  switch (eleccion)
  {
  case 1:
    preguntarNombre(); // Comenzar Juego
    break;
  case 2:
    cout << "Estadisticas"; // Funcion ver estadisticas
    break;
  case 3:
    cout << "Creditos"; // Funcion para ver créditos
    break;
  case 0:
    cout << "Salir"; // Funcion para salir del juego
    break;
  default:
    cout << "Eleccion incorrecta";
    break;
  }

  return 0;
}

/* Funcion principal del juego */
int jugar(){
  int resultadoDados[3] = {};
  dados(resultadoDados, 3);

  cout << "GRAN CERDO" << endl;
  cout << "------------------------------------------" << endl;
  cout << jugadores[0] << "            " << jugadores[1]<< endl;

  for (int i = 0; i < 3; i++){
    //if(resultadoDados[i] != 0){
      cout << "Dado numero " << i + 1  << " - " << resultadoDados[i] << endl;
    //}
  }

}

void preguntarNombre(){
  cout << "Nombre del jugador 1: ";
  cin >> jugadores[0];
  cout << "Nombre del jugador 2: ";
  cin >> jugadores[1];

  quienEmpieza();
}

/* Funcion para determinar quien empieza */
void quienEmpieza(){
  const int CANT_DADOS = 2;
  const int CANT_JUGADORES = 2;
  int dados_jugadores[CANT_DADOS];
  int totalJugadores[CANT_JUGADORES][CANT_DADOS];
  iniciarMatriz(totalJugadores, CANT_JUGADORES, CANT_DADOS);

  char eleccion;

  for (int i = 0; i < CANT_JUGADORES; i++){
    cout << endl << "LANZA LOS DADOS EL JUGADOR " << jugadores[i]<< " (S/N): "<<  endl << endl;
    cin >> eleccion;

    if(eleccion == 'S'){

      dados(dados_jugadores, 2);

      for (int j = 0; j < CANT_DADOS; j++){
        totalJugadores[i][j] += dados_jugadores[j];
        cout << "Dado numero " << j + 1 << " - " <<dados_jugadores[j] << endl; 
      }
    } else {
      if(i == 0){ // Si no quiere tirar, cede turno
       jugadorActual = jugadores[1];
       i = 2;
      } else {
        jugadorActual = jugadores[0];
        i = 2;
      }
    }

    int sumaMaxima = 0;
    int jugador;
    int dadoMaximo = 0;
    int jugadorDadoMaximo;
    int total = 0;

    for (int j = 0; j < CANT_DADOS; j++){
      total += totalJugadores[i][j];

      if(totalJugadores[i][j] > dadoMaximo){
        dadoMaximo = totalJugadores[i][j];
        jugadorDadoMaximo = i + 1;
      }
    }

    cout << endl << "Total: " << total << endl;
    cout << "===========================" << endl << endl;

    if(total > sumaMaxima){
      sumaMaxima = total;
      jugador = i + 1;
    }

    int totalJugador1= totalJugadores[0][0] + totalJugadores[0][1];
    int totalJugador2= totalJugadores[1][0] + totalJugadores[1][1];

    if(totalJugador1 != totalJugador2){
        if (jugador == 1){
        jugadorActual = jugadores[0];
      } else {
        jugadorActual = jugadores[1];
      }
    } else {
      if (jugadorDadoMaximo == 1){
        jugadorActual = jugadores[0];
      } else {
        jugadorActual = jugadores[1];
      }
    }
  }

  cout << jugadorActual << endl;

}

void iniciarMatriz(int matriz[2][2], int filas, int columnas){
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      matriz[i][j] = 0;
    }
  }
}

/* Funcion que devuelve numeros random */
void dados(int *a, int b){
  srand(time(0));
  for (int i = 0; i < b; i++){
    a[i] = rand() % 6 + 1;
  }
}

/* Funcion para el menu inicial */
int menuInicial(){

  int eleccion;

  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(h, 13);
  cout << endl << endl << endl << "\t\t\t     ,--.   ,--.\n\t\t\t     \\  /-~-\\  /\n\t\t\t      )' a a `(\n\t\t\t     (  ,---.  )\n\t\t\t      `(_o_o_)'\n\t\t\t        )`-'(";
  SetConsoleTextAttribute(h, 4);
  cout << endl << "\t\t\t   ===";
  SetConsoleTextAttribute(h, 13);
  cout << "W";
  SetConsoleTextAttribute(h, 4);
  cout <<"======";
  SetConsoleTextAttribute(h, 13);
  cout << "W";
  SetConsoleTextAttribute(h, 4);
  cout << "=====   " << endl;
  SetConsoleTextAttribute(h, 6);
  cout << "\t\t\t      GRAN CERDO";
  SetConsoleTextAttribute(h, 4);
  cout << endl << "\t\t\t   ================" << endl;

  SetConsoleTextAttribute(h, 3);
  cout << endl << endl << "\t\t      -----------------------";
  cout << endl << "\t\t      1 - JUGAR";
  cout << endl << "\t\t      2 - ESTADISTICA";
  cout << endl << "\t\t      3 - CERDITOS";
  cout << endl << "\t\t      -----------------------";
  cout << endl << "\t\t      0 - SALIR" << endl << endl << endl << endl;

  SetConsoleTextAttribute(h, 1);
  cin >>  eleccion;

  return eleccion;
}