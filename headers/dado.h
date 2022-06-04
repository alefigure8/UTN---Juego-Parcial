#pragma once
#ifndef DADO_H
#define DADO_H

#include <Windows.h>
#include <iostream>
#include <string>
#include "../dado.cpp"
using namespace std;


string dibujar_dados(int *num, int cant_dados);
void dados(int a[], int b);
void imprimirDados(int num);



#endif // DADO_H