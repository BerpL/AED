// PunteroFuncion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include<iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
using namespace std;

void LlenarArray(int *arr, int tam) {
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		int temporal = rand() % 999999;
		*(arr + i) = temporal;
	}
}

void printArr(int *arr, int tam) {
	for (int i = 0; i < tam; i++) {
		if (i < tam - 1) {
			cout << *(arr + i) << ", ";
		}
		else {
			cout << *(arr + i) << ".";
		}
	}
}

bool Less(int a, int b) { if (a > b) { return true; }return false; }
bool Greater(int a, int b) { if (a < b) { return true; }return false; }

void BubbleSort (int *arr, int tam, bool(*Orden)(int, int)) {
	int aux;
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam - 1; j++) {
			if (Orden(*(arr + j), *(arr + j + 1))) {
				aux = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = aux;
			}
		}
	}
}

int main() {

	int tam;
	int *arr;
	float inicio, fin, t;
	int tamanios[4] = { 5000,10000,15000,20000 };
	for (int i = 0; i < 4; i++) {
		tam = tamanios[i];
		arr = new int[tam];
		LlenarArray(arr, tam);
		inicio = clock();
		BubbleSort(arr, tam, &Less);
		fin = clock();
		t = fin - inicio;
		printf("\nEl tiempo de proseso es: %f", t / CLOCKS_PER_SEC);
		printf("\n");
	}
	printf("\n");
	system("PAUSE");
	return 0;
}
