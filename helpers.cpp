//Nombre: NOMBRE
//TP Nº
//EJ Nº
//Comentarios:

#include <iostream>
#include "headers/rlutil.h"
using namespace std;

/* Funciones */
void iniciarMatriz(int matriz[2][3], int filas, int columnas);
void dados(int *a, int b);
void lanzarDados();
bool ladoUno(int * dados, int cantidad);
bool iguales (int * dados, int cantidad);
void imprimirDados(int num);
string jugadores[2] = {"ALE", "PEDRO"};

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
  int RONDAS = 5;
  int contadorRondas = 1;
  int jugadorActual = 0;
  char eleccion;

  while(contadorRondas <= RONDAS){

    int totalRonda = 0;
    int lanzamientos = 1;
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

      cout << endl << endl << "GRAN CERDO" << endl;
      cout << " ----------------------------------------------------------------------- " << endl;

      cout << endl << jugadores[0] << ": " << total[0] << " trufas acumuladas             ";
      cout << jugadores[1] << ": " << total[1] << " trufas acumuladas" << endl;
      cout << endl << "TURNO DE "<< jugadores[JugadorActualLanzando] << endl;
      cout << "+=========================+" << endl;
      cout << "| RONDA #" << contadorRondas << "                |"<< endl ;
      cout << "| TRUFAS DE LA RONDA : " << totalRonda << "  |" << endl;
      cout << "| LANZAMIENTO #" << lanzamientos - 1 <<  "          |" << endl;
      cout << "+=========================+" << endl;
      cout << endl << "LANZAMIENTO #" << lanzamientos << endl << endl;
      /* Suma el resultado de los dados */
      for (int j = 0; j < CANT_DADOS; j++){
        resultadoDados[jugadorActual][j] += dados_jugadores[j];
        sumaDados += resultadoDados[jugadorActual][j];
        imprimirDados(dados_jugadores[j]);
      }
      sonIguales = iguales(dados_jugadores, CANT_DADOS);
      buscarUno = ladoUno(dados_jugadores, CANT_DADOS);


      if(sumaDados == CANT_DADOS * 1 && sonIguales == 1){ // TODOS LOS LADOS SON IGUALES

        if( CANT_DADOS == 2 ){
          CANT_DADOS++;
        }

        if(sumaDados == 3){
          if(jugadorActual == 0){
            total[1] += total[jugadorActual] ;
          } else {
            total[0] += total[jugadorActual] ;
          }
        }

        if(jugadorActual == 0){
          jugadorActual = 1;
        } else {
          jugadorActual = 0;
        }

        total[jugadorActual] = 0;
        totalRonda = 0;
        sumaDados = 0;

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

      if(total[JugadorActualLanzando] + totalRonda > 50 && CANT_DADOS == 2){
      CANT_DADOS++;
    }

      cout << endl << endl << "SUMASTA  " << sumaDados << " TRUFAS!" << endl;

      /* Cambiar jugador si desea ceder el turno */
      if(jugadorActual == JugadorActualLanzando){
        cout << endl << jugadores[jugadorActual]<< " continuar. " <<  " (S/N): "<<  endl << endl;
        cin >> eleccion;

        if(eleccion == 'N' || eleccion == 'n'){
          if(jugadorActual == 0){
            jugadorActual = 1;
          } else {
            jugadorActual = 0;
          }
        }
      }

      lanzamientos++;

    }

    total[JugadorActualLanzando] += totalRonda;
  
    if(JugadorActualLanzando == 1){
      contadorRondas++;
    }
  }
  cout << endl <<"===========================" << endl;
  cout << endl << jugadores[0] << " HIZO UN TOTAL DE " << total[0];
  cout << endl << jugadores[1] << " HIZO UN TOTAL DE " << total[1];
  cout << endl <<"===========================" << endl;
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

void imprimirDados(int num){
  int dado[5][9];
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 9; j++){

      if(i == 0 || i == 4){
        if(j == 0 || j == 8){
          cout << "+";
          if(j == 8){
            cout << endl;
          }
        } else{
          cout <<"-";
        }
      } else {
        if(j == 0 || j == 8){
          cout << "|";
          if(j == 8){
            cout << endl;
          }
        } else{
         if(num % 2 != 0){
          if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && num > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 3)){
            cout << "x";
            } else {
              cout <<" ";
            }
         } else {
           if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && num > 4)){
            cout << "x";
          } else {
            cout <<" ";
          }
         }
        }
      }
    }
  }
}