#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

#include "headers/dado.h"

enum COLOR_DADO {
  BLANCO = 240,
  NEGRO = 1,
};

void dibujar_dados(int *num, int cant_dados){

  int dado_1 = num[0];
  int dado_2 = num[1];
  int dado_3 = num[2];
  int pos = 40;

  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < ((cant_dados - 1)*10 + 9); j++){

      if(i == 0 || i == 4){

        int n1;
        int n2;

        for (int h = 0; h < cant_dados; h++){
          n1 = 0 + (h*10);
          n2 = 8 + (h*10);
          if(j == n1 || j == n2){
           SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
            if(j == ((cant_dados - 1) * 10) + 8){
              setw(pos); cout << "\n";
              }
          } else if(j==((h * 10) + 9)){
            SetConsoleTextAttribute(handle, COLOR_DADO::NEGRO); setw(pos); cout << " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
             SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
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
            SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO);setw(pos); cout << " ";
            if(j == ((cant_dados - 1) * 10) + 8){
               setw(pos); cout << "\n";
              }
          } else if(j==((h * 10) + 9)){
            SetConsoleTextAttribute(handle, COLOR_DADO::NEGRO); setw(pos); cout << " ";
          } else {
              if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
              //dado 1
              if(dado_1 % 2 != 0){
                if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && dado_1 > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 3)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << "X";
                  } else {
                    if(j > 0 && j < 8){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && dado_1 > 4)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << "X";
                } else {
                  if(j > 0 && j < 8){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
                  }
                }
              }
                // dado 2
              if(dado_2 % 2 != 0){
                if((i == 2 && j == 14) || (((i == 1 && j == 12) || (i == 3 && j == 16)) && dado_2 > 1) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 3)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << "X";
                  } else {
                    if(j >10 && j < 18){
                   SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 12) || (i == 3 && j == 16)) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 2) || (((i == 2 && j == 12) || (i == 2 && j == 16)) && dado_2 > 4)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << "X";
                } else {
                  if(j >10 && j < 18){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
                  }
                }
              }

              // dado 3
              if(dado_3 % 2 != 0){
                    if((i == 2 && j == 24) || (((i == 1 && j == 22) || (i == 3 && j == 26)) && dado_3 > 1) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 3)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << "X";
                  } else {
                    if(j > 20 && j < 28){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
                    }
                  }
                } else {
                    if(((i == 1 && j == 22) || (i == 3 && j == 26)) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 2) || (((i == 2 && j == 22) || (i == 2 && j == 26)) && dado_3 > 4)){
                  SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << "X";
                } else {
                  if(j > 20 && j < 28){
                    SetConsoleTextAttribute(handle, COLOR_DADO::BLANCO); setw(pos); cout << " ";
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

/* Funcion que simula los dados y devuelve numeros random */
void dados(int a[], int b){
  srand(time(0));
  for (int i = 0; i < b; i++){
    a[i] = rand() % 6 + 1;
  }
}

/* Funcion para imprimir los dados*/ 
string imprimirDados(int num){
  string resultado_dado;
  int dado[5][9];
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 9; j++){

      if(i == 0 || i == 4){
        if(j == 0 || j == 8){
         resultado_dado += "+";
          if(j == 8){
            resultado_dado += "\n";
          }
        } else{
          resultado_dado +="-";
        }
      } else {
        if(j == 0 || j == 8){
          resultado_dado += "|";
          if(j == 8){
            resultado_dado += "\n";
          }
        } else{
         if(num % 2 != 0){
          if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && num > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 3)){
            resultado_dado += "x";
            } else {
              resultado_dado +=" ";
            }
         } else {
           if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && num > 4)){
            resultado_dado += "x";
          } else {
            resultado_dado +=" ";
          }
         }
        }
      }
    }
  }
  return resultado_dado;
}

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