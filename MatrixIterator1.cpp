// MatrixIterator.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<class T>
class ite {
protected:
	int i_i;
	int i_j;
	T** i_m;
public:
	ite() {
		this->i_i = 0;
		this->i_j = 0;
		this->i_m = NULL;
	}
	ite(T** m, int i, int j) {
		this->i_m = m;
		this->i_i = i;
		this->i_j = j;
	}
	ite<T> operator = (ite<T> x) {
		this->i_m = x.i_m;
		this->i_i = x.i_i;
		this->i_j = x.i_j;
		return *this;
	}
	bool operator != (ite<T> x) {
		return i_i != x.i_i && i_j != x.i_j;
	}
	void operator ++ () {
			if (!(i_j < 3)) { //Hasta que sea menor que m_j
				i_j = -1;
				i_i++;
			}
			i_j++;
	}
	T & operator *() {
		return *(*(i_m + i_i) + i_j);
	}
};

template<class T>
class Matrix {
	
protected:
	int m_i;
	int m_j;
	T **m_m;
public:
	typedef ite<T> iterator;
	Matrix() {
		this->m_i = 0;
		this->m_j = 0;
	}
	Matrix(int x, int y){
		this->m_i = x;
		this->m_j = y;
		//m_m = new T[x*y];
		m_m = new T*[x];

		for (int i = 0; i < x; i++)
			m_m[i] = new T[y];
	}
	T & operator() (int x, int y){
		return *(*(m_m + x) + y);
		//return m_m[x][y];
	}
	int get_i() {
		return m_i;
	}
	int get_j() {
		return m_j;
	}
	void fill() {
		srand(time(NULL));
		for (int i = 0; i < m_i; i++) {
			for (int j = 0; j < m_j; j++) {
				*(*(m_m + i) + j) = rand() % 10 + 1;
			}
		}
	}
	void display() {
		for (int i = 0; i < m_i; i++)
		{
			for (int j = 0; j < m_j; j++)
				cout << *(*(m_m + i) + j) << " ";

			cout << endl;
		}
	}
	iterator begin() {
		return iterator(m_m, 0, 0);
	}
	iterator end() {
		return iterator(m_m, m_i, m_j);
	}
};

int main()
{
	Matrix<int> m(4,4);
	m.fill();
	m.display();
	Matrix<int>::iterator i;
	for (i = m.begin(); i != m.end(); ++i)
		cout << *i<<" ";
	
}
