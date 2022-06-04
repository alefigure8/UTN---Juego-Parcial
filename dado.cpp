#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

#include "headers/dado.h"

string dibujar_dados(int *num, int cant_dados){

  int dado_1 = num[0];
  int dado_2 = num[1];
  int dado_3 = num[2];

  string dado_dibujado;

  for (int i = 0; i < 5; i++){
    for (int j = 0; j < ((cant_dados - 1)*10 + 9); j++){

      if(i == 0 || i == 4){

        int n1;
        int n2;

        for (int h = 0; h < cant_dados; h++){
          n1 = 0 + (h*10);
          n2 = 8 + (h*10);
          if(j == n1 || j == n2){
            dado_dibujado += "+";
            if(j == ((cant_dados - 1) * 10) + 8){
                dado_dibujado += "\n";
              }
          } else if(j==((h * 10) + 9)){
            dado_dibujado += " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
             dado_dibujado += "-";
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
           dado_dibujado += "|";
            if(j == ((cant_dados - 1) * 10) + 8){
               dado_dibujado += "\n";
              }
          } else if(j==((h * 10) + 9)){
           dado_dibujado += " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
             dado_dibujado += " ";
            }
          }
        }
      }
     }
  }

  return dado_dibujado;
 }

/* Funcion que simula los dados y devuelve numeros random */
void dados(int a[], int b){
  srand(time(0));
  for (int i = 0; i < b; i++){
    a[i] = rand() % 6 + 1;
  }
}

/* Funcion para imprimir los dados*/ 
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