// Sort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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

template<class T>
class Sort {
public:
	void PBubbleSort(T *arr, int tam) {
		T aux;
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam - 1; j++) {
				if (pcmp(*(arr + j), *(arr + j + 1))) {
					aux = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = aux;
				}
			}
		}
	}
	virtual bool pcmp(T a, T b)=0;
};

template<class T>
class PLess : public Sort<T> {
public:
	bool pcmp(T a, T b) {
		return a < b;
	}
};

template<class T>
class PGreater : public Sort<T> {
public:
	bool pcmp(T a, T b) {
		return a > b;
	}
};

bool Less(int a, int b) { if (a > b) { return true; }return false; }
bool Greater(int a, int b) { if (a < b) { return true; }return false; }

void BubbleSort(int *arr, int tam, bool(*Orden)(int, int)) {
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

template<class T>
class CLess {
public:
	inline bool operator()(T a, T b) {
		return a < b;
	}
};

template<class T>
class CGreater {
public:
	inline bool operator()(T a, T b) {
		return a > b;
	}
};

template<class T, class S>
class CBubbleSort {
public:
	CBubbleSort(T *arr, int tam) {
		T aux;
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam - 1; j++) {
				if (cmp(*(arr + j), *(arr + j + 1))) {
					aux = *(arr + j);
					*(arr + j) = *(arr + j + 1);
					*(arr + j + 1) = aux;
				}
			}
		}
	}
	S cmp;
};

int main() {

	int tam;
	int *arr;
	float inicio, fin, t;
	int tamanios[5] = { 5000,10000,15000,20000,25000 };
	cout << "POLIMORFISMO" << endl;
	for (int i = 0; i < 5; i++) {
		tam = tamanios[i];
		arr = new int[tam];
		LlenarArray(arr, tam);
		inicio = clock();
		PLess<int> l;
		PGreater<int> g;
		l.PBubbleSort(arr,tam);
		fin = clock();
		t = fin - inicio;
		printf("\nEl tiempo de proseso es: %f", t / CLOCKS_PER_SEC);
	}
	cout << endl;
	cout << "PUNTERO A FUNCION" << endl;
	for (int i = 0; i < 5; i++) {
		tam = tamanios[i];
		arr = new int[tam];
		LlenarArray(arr, tam);
		inicio = clock();
		BubbleSort(arr, tam, &Less);
		fin = clock();
		t = fin - inicio;
		printf("\nEl tiempo de proseso es: %f", t / CLOCKS_PER_SEC);
	}
	cout << endl;
	cout << "FUNCTOR" << endl;
	for (int i = 0; i < 5; i++) {
		tam = tamanios[i];
		arr = new int[tam];
		LlenarArray(arr, tam);
		inicio = clock();
		CBubbleSort<int, CLess<int> >ar(arr,tam);
		fin = clock();
		t = fin - inicio;
		printf("\nEl tiempo de proseso es: %f", t / CLOCKS_PER_SEC);
	}
	printf("\n");
	system("PAUSE");
	return 0;
}
