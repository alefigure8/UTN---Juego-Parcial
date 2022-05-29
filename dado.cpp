#include <iostream>
using namespace std;

void dados(int num);

int main (void){

  dados(1);
  dados(1);
  dados(1);

  return 0;
}

void dados(int num){
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