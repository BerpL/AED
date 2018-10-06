// CircularLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>

using namespace std;

template <class T>
class Cnode {
public:
	T m_data;
	Cnode *m_next;
	Cnode(T x, Cnode<T>* nxt);
};

template <class T>
Cnode<T>::Cnode(T x, Cnode<T>* nxt) {
	this->m_data = x;
	this->m_next = nxt;
}

template <class T>
class CircularLinkedList {
private:
	Cnode<T> *m_head;
	Cnode<T> **m_headprev;
public:
	CircularLinkedList();
	CircularLinkedList(T x);
	bool find(T x, Cnode<T>**& p);
	bool insert(T x);
	bool remove(T x);
	void display();
};

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
	m_head = NULL;
}

template <class T>
CircularLinkedList<T>::CircularLinkedList(T x) {
	m_head = new CircularLinkedList<T>(x, m_head);
}

template <class T>
bool CircularLinkedList<T>::find(T x, Cnode<T>**& p) {
	bool aux = 1; 
	p = &m_head;
	if (*p == NULL) return 0;
	while (*p && (*p != m_head || aux) && ((*p)->m_data != x)) {
		p = &((*p)->m_next);
		aux = 0;
	}
	return ((*p) && (*p)->m_data == x);
}

template <class T>
bool CircularLinkedList<T>::insert(T x) {
	Cnode<T> **p;
	if (!find(x, p)) {
		*p = new Cnode<T>(x, m_head);
		m_headprev = &(*p)/*->next*/;
		return 1;
	}
	return 0;
}

template <class T>
bool CircularLinkedList<T>::remove(T x) {
	Cnode<T> **p;
	cout << "Borrando: " << x << endl;
	if (find(x, p)) {
		Cnode<T>* temp = (*p)->m_next;
		delete *p;
		*p = temp;
		(*m_headprev) = m_head;
		return 1;
	}
	return 0;
}

template <class T>
void CircularLinkedList<T>::display() {
	Cnode<T>* t = m_head;
	bool aux = 1;
	cout << "Head -> ";
	while ((t) && (t != m_head || aux)) {
		cout << (t)->m_data << " -> ";
		t = (t)->m_next;
		aux = 0;
	}
	cout << "NULL";
	cout << endl;
}


int main() {
	CircularLinkedList<int> List;
	List.insert(5);
	List.insert(6);
	List.insert(2);
	List.insert(4);
	List.insert(8);
	List.insert(2);
	List.display();
	List.remove(8);
	List.display();
	return 0;
}
