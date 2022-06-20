#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;



int main(){
  system("cls");

  struct jugador{
     string nombre;
    
  };
 jugador jugadores[2];

  jugadores[0].nombre = "Uno";
  jugadores[1].nombre = "Dos";

  int actual = 1;

  cout << jugadores[actual].nombre << endl << (actual == 0 ? jugadores[1].nombre : jugadores[0].nombre) << endl;
  return 1;
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