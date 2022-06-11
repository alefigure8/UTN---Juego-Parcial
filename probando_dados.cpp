#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

bool dados_iguales(int *vec_1, int *vec_2);

int main(){
  system("cls");

  int vec_1[5] = {1,2};
  int vec_2[5] = {2,1};

  if(dados_iguales(vec_1, vec_2)){
    cout << "Los dados son iguales" << endl;
  } else {
    cout << "Los dados no son iguales" << endl;
  }

  return 1;
}


bool dados_iguales(int *vec_1, int *vec_2){
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

  // comparar
  for(int i = 0; i < 5; i++){
    if(vec_1[i] != vec_2[i]){
      return iguales = false;
    }
  }

  return iguales;
}



// /* Funcion para imprimir los dados*/ 
// string imprimirDados(int num){
//   string resultado_dado;
//   int dado[5][9];
//   for (int i = 0; i < 5; i++){
//     for (int j = 0; j < 9; j++){

//       if(i == 0 || i == 4){
//         if(j == 0 || j == 8){
//          resultado_dado += "+";
//           if(j == 8){
//             resultado_dado += "\n";
//           }
//         } else{
//           resultado_dado +="-";
//         }
//       } else {
//         if(j == 0 || j == 8){
//           resultado_dado += "|";
//           if(j == 8){
//             resultado_dado += "\n";
//           }
//         } else{
//          if(num % 2 != 0){
//           if((i == 2 && j == 4) || (((i == 1 && j == 2) || (i == 3 && j == 6)) && num > 1) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 3)){
//             resultado_dado += "x";
//             } else {
//               resultado_dado +=" ";
//             }
//          } else {
//            if(((i == 1 && j == 2) || (i == 3 && j == 6)) || (((i == 1 && j == 6) || (i == 3 && j == 2)) && num > 2) || (((i == 2 && j == 2) || (i == 2 && j == 6)) && num > 4)){
//             resultado_dado += "x";
//           } else {
//             resultado_dado +=" ";
//           }
//          }
//         }
//       }
//     }
//   }
//   return resultado_dado;
// }