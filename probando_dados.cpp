#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "headers/rlutil.h"
using namespace std;

void dibujar_dados(int *num, int cant_dados);


int main(){
  system("cls");
  int dado[3] = {5,4,3};
  dibujar_dados(dado, 3);
 
  return 1;
}

enum COLOR {
  BLANCO = 240,
  NEGRO = 1,
};

void dibujar_dados(int *num, int cant_dados){

  int dado_1 = num[0];
  int dado_2 = num[1];
  int dado_3 = num[2];

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
           SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
            if(j == ((cant_dados - 1) * 10) + 8){
              cout << "\n";
              }
          } else if(j==((h * 10) + 9)){
            SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
             SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
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
            SetConsoleTextAttribute(handle, COLOR::BLANCO);cout << " ";
            if(j == ((cant_dados - 1) * 10) + 8){
               cout << "\n";
              }
          } else if(j==((h * 10) + 9)){
            SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
          } else {
              if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
              //dado 1
              if(dado_1 % 2 != 0){
                if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && dado_1 > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 3)){
                  SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
                  } else {
                    if(j > 0 && j < 8){
                    SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && dado_1 > 4)){
                  SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
                } else {
                  if(j > 0 && j < 8){
                    SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
                  }
                }
              }
                // dado 2
              if(dado_2 % 2 != 0){
                if((i == 2 && j == 14) || (((i == 1 && j == 12) || (i == 3 && j == 16)) && dado_2 > 1) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 3)){
                  SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
                  } else {
                    if(j >10 && j < 18){
                   SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 12) || (i == 3 && j == 16)) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 2) || (((i == 2 && j == 12) || (i == 2 && j == 16)) && dado_2 > 4)){
                  SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
                } else {
                  if(j >10 && j < 18){
                    SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
                  }
                }
              }

              // dado 3
              if(dado_3 % 2 != 0){
                    if((i == 2 && j == 24) || (((i == 1 && j == 22) || (i == 3 && j == 26)) && dado_3 > 1) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 3)){
                  SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
                  } else {
                    if(j > 20 && j < 28){
                    SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
                    }
                  }
                } else {
                    if(((i == 1 && j == 22) || (i == 3 && j == 26)) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 2) || (((i == 2 && j == 22) || (i == 2 && j == 26)) && dado_3 > 4)){
                  SetConsoleTextAttribute(handle, COLOR::NEGRO); cout << " ";
                } else {
                  if(j > 20 && j < 28){
                    SetConsoleTextAttribute(handle, COLOR::BLANCO); cout << " ";
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
              //dado 1
              if(dado_1 % 2 != 0){
                if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && dado_1 > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 3)){
                  dado_dibujado += "x";
                  } else {
                    if(j > 0 && j < 8){
                    dado_dibujado += " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && dado_1 > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && dado_1 > 4)){
                  dado_dibujado += "x";
                } else {
                  if(j > 0 && j < 8){
                    dado_dibujado += " ";
                  }
                }
              }
                // dado 2
              if(dado_2 % 2 != 0){
                if((i == 2 && j == 14) || (((i == 1 && j == 12) || (i == 3 && j == 16)) && dado_2 > 1) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 3)){
                  dado_dibujado += "x";
                  } else {
                    if(j >10 && j < 18){
                    dado_dibujado += " ";
                  }
                  }
              } else {
                if(((i == 1 && j == 12) || (i == 3 && j == 16)) || (((i == 1 && j == 16) || (i == 3 && j == 12)) && dado_2 > 2) || (((i == 2 && j == 12) || (i == 2 && j == 16)) && dado_2 > 4)){
                  dado_dibujado += "x";
                } else {
                  if(j >10 && j < 18){
                    dado_dibujado += " ";
                  }
                }
              }

              // dado 3
              if(dado_3 % 2 != 0){
                    if((i == 2 && j == 24) || (((i == 1 && j == 22) || (i == 3 && j == 26)) && dado_3 > 1) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 3)){
                  dado_dibujado += "x";
                  } else {
                    if(j > 20 && j < 28){
                    dado_dibujado += " ";
                    }
                  }
                } else {
                    if(((i == 1 && j == 22) || (i == 3 && j == 26)) || (((i == 1 && j == 26) || (i == 3 && j == 22)) && dado_3 > 2) || (((i == 2 && j == 22) || (i == 2 && j == 26)) && dado_3 > 4)){
                  dado_dibujado += "x";
                } else {
                  if(j > 20 && j < 28){
                    dado_dibujado += " ";
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return dado_dibujado;
 }