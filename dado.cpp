#include <iostream>
using namespace std;

void dados(int *num, int cant_dados);

int main (void){

  int dado[3] = {5, 6, 2};

  dados(dado, 3);

  return 0;
}

void dados(int *num, int cant_dados){

  int dado_1 = num[0];
  int dado_2 = num[1];
  int dado_3 = num[2];

  for (int i = 0; i < 5; i++){
    for (int j = 0; j < ((cant_dados - 1)*10 + 9); j++){

      if(i == 0 || i == 4){

        int n1;
        int n2;

        for (int h = 0; h < cant_dados; h++){
          n1 = 0 + (h*10);
          n2 = 8 + (h*10);
          if(j == n1 || j == n2){
            cout << "+";
            if(j == ((cant_dados - 1) * 10) + 8){
                cout << endl;
              }
          } else if(j==((h * 10) + 9)){
            cout << " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
              cout << "-";
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
            cout << "|";
            if(j == ((cant_dados - 1) * 10) + 8){
                cout << endl;
              }
          } else if(j==((h * 10) + 9)){
            cout << " ";
          } else {
            if(h == cant_dados - 1 && j != 0 && j!=8 && j!=9 && j!= 10 && j!=18 && j!=19 && j!=20 && j!=28){
              cout << " ";
            }
          }
        }
      }
     }
  }
 }