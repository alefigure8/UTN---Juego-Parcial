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
bool dados_iguales (int * dados, int cantidad);
int dado_lado_uno(int * dados, int cantidad);
bool dados_coinciden(int *vec_1, int *vec_2);

#endif // DADO_H