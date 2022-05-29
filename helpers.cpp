//Nombre: NOMBRE
//TP Nº
//EJ Nº
//Comentarios:

#include <iostream>
using namespace std;

/* Funciones */
void iniciarMatriz(int matriz[2][3], int filas, int columnas);
void dados(int *a, int b);
void lanzarDados();
bool ladoUno(int * dados, int cantidad);
bool iguales (int * dados, int cantidad);
string jugadores[2] = {"ALE", "PEDRO"};
int jugadorActual = 0;

int main (void){

  lanzarDados();

  return 0;
}

void lanzarDados(){
  int CANT_DADOS = 2;
  const int CANT_JUGADORES = 2;
  int dados_jugadores[3];
  int total [2] = {};
  int JugadorActualLanzando;

  char eleccion;

  for(int j = 0; j < 10; j++){

    int totalRonda = 0;

    cout << endl << "LANZA LOS DADOS EL JUGADOR " << jugadores[jugadorActual]<< "\nLISTOS: (S/N): " <<  endl << endl;
    cin >> eleccion;

    JugadorActualLanzando = jugadorActual;

    while(jugadorActual == JugadorActualLanzando){

      int resultadoDados[CANT_JUGADORES][3];
      bool sonIguales = 0;
      bool buscarUno = 0;
      int sumaDados = 0;

      iniciarMatriz(resultadoDados, CANT_JUGADORES, CANT_DADOS);
      dados(dados_jugadores, CANT_DADOS);

      /* Suma el resultado de los dados */
      for (int j = 0; j < CANT_DADOS; j++){
        resultadoDados[jugadorActual][j] += dados_jugadores[j];
        sumaDados += resultadoDados[jugadorActual][j];
        cout << "Dado numero " << j + 1 << " - " << dados_jugadores[j] << endl;
      }

      sonIguales = iguales(dados_jugadores, CANT_DADOS);
      buscarUno = ladoUno(dados_jugadores, CANT_DADOS);

      if(sumaDados == CANT_DADOS * 1 && sonIguales == 1){ // TODOS LOS LADOS SON IGUALES

        total[jugadorActual] = 0;
        totalRonda = 0;
        sumaDados = 0;

        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

      cout << endl << "PIERDE LO ACUMULADO EN EL JUEGO Y CEDE TURNO" << endl;

      } else if (buscarUno == 1){ // HAY UN LADO CON UNO

        totalRonda = 0;
        sumaDados = 0;

        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

      cout << endl << "PIERDE LO ACUMULADO EN LA RONDA Y CEDE TURNO" << endl;

      } else if (sonIguales == 1){ // OINK

        totalRonda += sumaDados * 2;
        cout << endl << "OINK" << endl;

      } else { // SUMA NORAML
         totalRonda += sumaDados;
      }

      cout << endl << endl << "SUMASTA  " << sumaDados << " TRUFAS!" << endl;
      cout << endl <<"===========================" << endl;
      cout << "TOTAL DE TRUFAS ACUMULADAS PARA EL JUGADOR " << jugadores[JugadorActualLanzando] << ": " << total[JugadorActualLanzando] + totalRonda;
      cout << endl <<  "===========================" << endl;

      /* Cambiar jugador si desea ceder el turno */
      if(jugadorActual == JugadorActualLanzando){
        cout << endl << "CONITNUA LANZANDO LOS DADOS EL JUGADOR " << jugadores[jugadorActual]<< " (S/N): "<<  endl << endl;
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

    total[JugadorActualLanzando] += totalRonda;
  }
}

/* Funcion para inicializar con ceros una matriz*/
void iniciarMatriz(int matriz[2][3], int filas, int columnas){
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      matriz[i][j] = 0;
    }
  }
}

/* Funcion que simula los dados y devuelve numeros random */
void dados(int *a, int b){
  srand(time(0));
  for (int i = 0; i < b; i++){
    a[i] = rand() % 6 + 1;
  }
}

bool iguales (int * dados, int cantidad){
  for (int i = 0; i < cantidad - 1; i++){
    if (dados[i] != dados[i + 1]){
      return false;
    }
  }
  return true;
}

bool ladoUno(int * dados, int cantidad){
  int uno = 1;

  for (int i = 0; i < cantidad; i++){
    if(dados[i] == uno){
      return true;
    }
  }

  return false;
}