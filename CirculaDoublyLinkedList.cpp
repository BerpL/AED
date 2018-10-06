// CirculaDoublyLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// CDL

#include "pch.h"
#include <iostream>

using namespace std;

class Cnode {
public:
	int m_data;
	Cnode *m_next;
	Cnode *m_prev;
	Cnode(int x) {
		m_data = x;
		m_next = nullptr;
		m_prev = nullptr;
	}
	Cnode(int x, Cnode *ante, Cnode *sigue) {
		m_data = x;
		m_prev = ante;
		m_next = sigue;
	}
};


class CircularDoublyLinkedList {
public:
	Cnode *m_head;
	CircularDoublyLinkedList() {
		m_head = nullptr;
	};

	bool find(int x, Cnode *&p) {
		p = m_head;
		if (m_head->m_data == x)return 1;//encontrado
		p = m_head->m_next;
		while (p != m_head && p->m_data < x) { //recorrer la lista buscando el nodo
			p = p->m_next;
		}
		return (p->m_data == x);
	}

	void insert(int x) {
		Cnode* temp2 = new Cnode(x);
		if (m_head == nullptr) {
			m_head = new Cnode(x);
			m_head->m_next = m_head;
			m_head->m_prev = m_head;
			return;
		}
		if (x < m_head->m_data)
		{
			Cnode *n = new Cnode(x, m_head->m_prev, m_head);
			m_head->m_prev->m_next = n;
			m_head->m_prev = n;
			m_head = n;
			return;
		}
		Cnode *aux;
		if (find(x, aux))return;
		Cnode *nue = new Cnode(x, aux->m_prev, aux);
		aux->m_prev->m_next = nue;
		aux->m_prev = nue;
		return;
	}

	void remove(int x) {
		Cnode *aux;
		if (!find(x, aux)) return;
		if (aux == m_head) {
			m_head->m_prev->m_next = m_head->m_next;
			m_head->m_next->m_prev = m_head->m_prev;
			m_head = m_head->m_next;
			delete aux;
			return;
		}
		Cnode *temp = aux;
		aux->m_prev->m_next = aux->m_next;
		aux->m_next->m_prev = aux->m_prev;
		delete temp;
		return;
	}

	void display() {
		Cnode *aux = m_head;
		cout << aux->m_data << ' ';
		aux = aux->m_next;
		while (aux != m_head) {
			cout << aux->m_data << ' ';
			aux = aux->m_next;
		}
	
	}
};
int main() {
	CircularDoublyLinkedList Circular;
	Circular.insert(12);
	Circular.insert(3);
	Circular.insert(6);
	Circular.insert(5);
	Circular.insert(8);
	Circular.insert(3);
	Circular.insert(2);
	Circular.display();
	return 0;
}

