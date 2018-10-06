// Linkedlist2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>

using namespace std;

template <class T>
class Cnode {
public:
	Cnode(T x)
	{
		m_data = x;
		m_next = 0;
	};
	T m_data;
	Cnode<T>*m_next;
};

template<class T>
class Clist {
public:
	Clist() {
		m_head = 0;
	}
	bool find(T x, Cnode<T>**&p);
	bool insert(T x);
	bool remove(T x);
	bool print();

	Cnode<T>*m_head;
};

template<class T>
bool Clist<T>::find(T x, Cnode<T>**&p) {
	for (p = &m_head; *p && (*p)->m_data < x; p = &((*p)->m_next));
	return (*p) && (*p)->m_data == x;
}

template<class T>
bool Clist<T>::insert(T x) {
	Cnode<T>**p;
	if (find(x, p))return 0;
	Cnode<T>*t = new Cnode<T>(x);
	t->m_next = *p;
	*p = t;
	return 1;
}

template<class T>
bool Clist<T>::remove(T x) {
	Cnode<T>**p;
	if (!find(x, p))return 0;
	Cnode<T>*t = *p;
	*p = t->m_next;
	delete t;
	return 1;
}

template<class T>
bool Clist<T>::print() {
	cout << "head-> ";
	for(Cnode<T>**p=&m_head;*p; p = &((*p)->m_next))
		cout << (*p)->m_data << " -> ";
	cout << " NULL";
	return 1;
}

int main() {
	Clist<int> list;
	list.insert(3);
	list.insert(5);
	list.insert(1);
	list.insert(7);
	list.insert(9);
	list.insert(2);
	list.remove(1);
	list.remove(9);
	list.print();
	return 0;
}
