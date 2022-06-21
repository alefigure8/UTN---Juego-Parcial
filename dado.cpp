#include <Windows.h>
#include <iostream>
#include <string>
#include "headers/dado.h"
#include "headers/rlutil.h"
using namespace std;


// Color de los dados
enum COLOR_DADO {
  BLANCO = 240,
  NEGRO = 1,
};


// Funcion que genera el dibujo de los dados y los ubuca uno al lado del otro
void dibujar_dados(int *num, int cant_dados, int pantalla){

  int dado_1 = num[0];
  int dado_2 = num[1];
  int dado_3 = num[2];
  int COLUMNA;
  int FILA;

  if(cant_dados == 2){
    COLUMNA = 35;
  } else {
    COLUMNA = 30;
  }

  if(pantalla == 1){
    FILA = 15;
  } else {
    FILA = 17;
  }

  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

  for (int i = 0; i < 5; i++){
    for (int j = 0; j < ((cant_dados - 1)*10 + 9); j++){

      // Ubicacion de los dados
      rlutil::locate(COLUMNA + j, FILA + i);

      if(i == 0 || i == 4){

        int n1;
        int n2;

        for (int h = 0; h < cant_dados; h++){
          n1 = 0 + (h*10);
          n2 = 8 + (h*10);
          if(j == n1 || j == n2){

           SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO);

            cout << " ";

            if(j == ((cant_dados - 1) * 10) + 8){
              cout << "\n";
              }
          } else if(j==((h * 10) + 9)){
            SetConsoleTextAttribute(handle, COLOR_DADO::NEGRO); cout << " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
             SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
            }
          }
        }

      } else {
        int n3;
        int n4;
        for (int h = 0; h < cant_dados; h++){
          n3 = 0 + (h*10);
          n4 = 8 + (h*10);
          if(j == n3 || j == n4){
            SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO);cout << " ";
            if(j == ((cant_dados - 1) * 10) + 8){
               cout << "\n";
              }
          } else if(j==((h * 10) + 9)){
            SetConsoleTextAttribute(handle, COLOR_DADO::NEGRO); cout << " ";
          } else {
              if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
              //dado 1
              if(dado_1 % 2 != 0){
                if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && dado_1 > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 3)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << "X";
                  } else {
                    if(j > 0 && j < 8){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && dado_1 > 4)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << "X";
                } else {
                  if(j > 0 && j < 8){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
                  }
                }
              }
                // dado 2
              if(dado_2 % 2 != 0){
                if((i == 2 && j == 14) || (((i == 1 && j == 12) || (i == 3 && j == 16)) && dado_2 > 1) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 3)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << "X";
                  } else {
                    if(j >10 && j < 18){
                   SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 12) || (i == 3 && j == 16)) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 2) || (((i == 2 && j == 12) || (i == 2 && j == 16)) && dado_2 > 4)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << "X";
                } else {
                  if(j >10 && j < 18){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
                  }
                }
              }

              // dado 3
              if(dado_3 % 2 != 0){
                    if((i == 2 && j == 24) || (((i == 1 && j == 22) || (i == 3 && j == 26)) && dado_3 > 1) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 3)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << "X";
                  } else {
                    if(j > 20 && j < 28){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
                    }
                  }
                } else {
                    if(((i == 1 && j == 22) || (i == 3 && j == 26)) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 2) || (((i == 2 && j == 22) || (i == 2 && j == 26)) && dado_3 > 4)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << "X";
                } else {
                  if(j > 20 && j < 28){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); cout << " ";
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  SetConsoleTextAttribute(handle, 15);
 }


// Funcion que simula los dados y devuelve numeros random
void dados(int a[], int b){
  srand(time(NULL));
  for (int i = 0; i < b; i++){
    a[i] = rand() % 6 + 1;
  }
}

// Funcion que determina si las caras de los dados de un mismo jugador son iguales
bool dados_iguales (int * dados, int cantidad){
  for (int i = 0; i < cantidad - 1; i++){
    if (dados[i] != dados[i + 1]){
      return false;
    }
  }
  return true;
}

int dado_lado_uno(int * dados, int cantidad){
  int DADO = 1;
  int total = 0;

  for (int i = 0; i < cantidad; i++){
    if(DADO == dados[i]){
      total++;
    }
  }
  return total;
}

// Funcion para determinar si las caras de los dados de ambos jugadores son iguales
bool dados_coinciden(int *vec_1, int *vec_2){
  bool iguales = true;

  // ordenarlos de menor a mayor
    if(vec_1[0] > vec_1[1]){
    int aux = vec_1[0];
    vec_1[0] = vec_1[1];
    vec_1[1] = aux;
  }

  if(vec_2[0] > vec_2[1]){
    int aux = vec_2[0];
    vec_2[0] = vec_2[1];
    vec_2[1] = aux;
  }

  // comparar las caras de los dados
  for(int i = 0; i < 5; i++){
    if(vec_1[i] != vec_2[i]){
      return iguales = false;
    }
  }

  return iguales;
}


// Funcion para sumar los dados de un solo jugador
int sumar_dados(int vec[3], int CANT_DADOS){
  int total = 0;
   for (int j = 0; j < CANT_DADOS; j++){
      total += vec[j];
    }
  return total;
}