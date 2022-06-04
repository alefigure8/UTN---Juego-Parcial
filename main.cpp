#include <iostream>
#include <Windows.h>
#include <string>
#include "headers/dado.h"
using namespace std;


int main (){

  int dados[3] = {3,4,5};
  dibujar_dados(dados, 3);
  return 0;
}


