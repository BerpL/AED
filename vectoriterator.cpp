#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<class T>
struct reverseite {
	int m_i;//contador 
	T *m_v;// puntero al inicio del vector 
	reverseite() {
		this->m_i = 0;
		this->m_v = NULL;
	}
	reverseite(T *v, int i) {
		this->m_i = i;
		this->m_v = v;
	}
	reverseite<T> operator = (reverseite<T> x) {
		m_v = x.m_v;
		m_i = x.m_i;
		return *this;
	}
	bool operator != (reverseite<T> x) {
		return m_i != x.m_i;
	}
	void operator ++() {
		m_i--;
	}
	T & operator *() {
		return m_v[m_i];
	}
};

template<class T>
struct ite {
	int m_i;//contador 
	T *m_v;// puntero al inicio del vector 
	ite() {
		this->m_i = 0;
		this->m_v = NULL;
	}
	ite(T *v, int i) {
		this->m_i = i;
		this->m_v = v;
	}
	ite<T> operator = (ite<T> x) {
		m_v = x.m_v;
		m_i = x.m_i;
		return *this;//-------------->
	}
	bool operator != (ite<T> x) {
		return m_i != x.m_i;
	}
	void operator ++() {
		m_i++;
		//return *this;
	}
	T & operator *() {//-------->
		return m_v[m_i];
	}

};
template<class T>
struct Cvector {
	typedef ite<T> iterator;
	typedef reverseite<T> reverse_iterator;
	Cvector(T n) {
		m = n;
		m_v = new T[n];
	}
	T & operator [] (int x) {
		return *(m_v + x);
	}
	iterator begin() {
		return iterator(m_v, 0);
	}
	iterator end() {
		return iterator(m_v, m);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(m_v, m-1);
	}
	reverse_iterator rend() {
		return reverse_iterator(m_v, -1);
	}
	int m;
	T *m_v;
};


int main()
{
	Cvector<int> v(5);
	Cvector<int>::iterator i;
	Cvector<int>::reverse_iterator j;
	srand(time(NULL));
	for (int j = 0; j < 5; j++) {
		v[j] = rand() % 10 + 1;
	}
	cout << "iterator normal" << endl;
	for (i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;
	cout << "reverse iterator" << endl;
	for (j = v.rbegin(); j != v.rend(); ++j)
		cout << *j << " ";
	return 0;
}
