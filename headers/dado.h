#pragma once
#ifndef DADO_H
#define DADO_H

#include <Windows.h>
#include <iostream>
#include <string>
#include "../dado.cpp"
using namespace std;


void dibujar_dados(int *num, int cant_dados);
void dados(int a[], int b);
string imprimirDados(int num);
bool dados_iguales (int * dados, int cantidad);
int dado_lado_uno(int * dados, int cantidad);


#endif // DADO_H