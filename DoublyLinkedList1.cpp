// DoublyLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Ordered with-repeated values Double Linked List single pointer

#include "pch.h"
#include <iostream>
using namespace std;

template <class T>
class Cnode {
public:
	T m_data;
	Cnode* m_prev;
	Cnode* m_next;
	Cnode(Cnode<T>* nxt, Cnode<T>* prv, T x);
	Cnode(T x);
};

template <class T>
Cnode<T>::Cnode(Cnode<T>* nxt, Cnode<T>* prv, T x) {
	m_next = nxt;
	m_prev = prv;
	m_data = x;
}

template <class T>
Cnode<T>::Cnode(T x) {
	m_data = x;
}

template <class T>
class DoublyLinkedList {
private:
	Cnode<T>* m_head;
	Cnode<T>* m_tail;
public:
	DoublyLinkedList();
	bool find(T x, Cnode<T>*& p);
	bool insert(T x);
	bool remove(T x);
	void displayhead();
	void displaytail();
	void i(T x, Cnode<T>* &p, Cnode<T>* &q);
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	m_head = 0;
	m_tail = 0;
}

template <class T>
bool DoublyLinkedList<T>::find(T x, Cnode<T>*& p) {
	p = m_head;
	while (p && p->m_next && p->m_data < x) {
		p = p->m_next;
	}
	return (p && (p)->m_data == x);
}

template<class T>
void DoublyLinkedList<T>::i(T x, Cnode<T>* &p, Cnode<T>* &q) {
		q = new Cnode<T>(x);
		if (!m_head) {
			m_head = q;
			m_tail = q;
			q->m_prev = NULL;
			q->m_next = NULL;
		}
		else {
			if (!(p->m_next)) { ///p->next es nulo, insercion al final
				m_tail = q;
				q->m_next = p->m_next;
				p->m_next = q;
				q->m_prev = p;
			}
			else if (!(p->m_prev)) { ///p->prev es nulo, insercion al comienzo
				m_head = q;
				q->m_prev = p->m_prev;
				p->m_prev = q;
				q->m_next = p;
			}
			else { ///insercion al medio
				q->m_next = p;
				q->m_prev = p->m_prev;
				q->m_prev->m_next = q;
				p->m_prev = q;
			}
		}	
}

template <class T>
bool DoublyLinkedList<T>::insert(T x) {
	Cnode<T>* p, *q;
	if (find(x, p)) {
		i(x, p, q);
		return 0;
	}
	i(x, p, q);
	return 1;
	
}
template <class T>
bool DoublyLinkedList<T>::remove(T x) {
	Cnode<T>* p;
	if (!find(x, p)) return 0;
	cout << "Borrando " << x << ":\n";
	Cnode<T>* temp;
	if (p == m_head) { ///borrado de la cabeza
		temp = p->m_next;
		delete p;
		m_head = temp;
		temp->m_prev = NULL;
	}
	else if (p == m_tail) { ///borrado al final
		temp = p->m_prev;
		delete p;
		m_tail = temp;
		temp->m_next = NULL;
	}
	else { ///borrado al medio
		temp = p->m_next;
		p->m_prev->m_next = temp;
		temp->m_prev = p->m_prev;
		delete p;
	}
	return 1;
}

template <class T>
void DoublyLinkedList<T>::displayhead() {
	Cnode<T>* h;
	cout << "Head -> ";
	for (h = m_head; h; h = h->m_next)
		cout << h->m_data << " -> ";
	cout << "Tail ";
	cout << endl;
}

template <class T>
void DoublyLinkedList<T>::displaytail() {
	Cnode<T>* h;
	cout << "Head <- ";
	for (h = m_tail; h; h = h->m_prev)
		cout << h->m_data << " <- ";
	cout << " Tail ";
	cout << endl;
}

int main() {
	DoublyLinkedList<int> List;
	List.insert(5);
	List.insert(5);
	List.displayhead();
	List.displaytail();
	List.remove(5);
	List.displayhead();
	List.displaytail();
	List.insert(8);
	List.insert(10);
	List.insert(12);
	List.displayhead();
	List.displaytail();
	List.insert(9);
	List.displayhead();
	List.displaytail();
	List.insert(1);
	List.displayhead();
	List.displaytail();
	List.insert(7);
	List.displayhead();
	List.displaytail();
	List.remove(8);
	List.displayhead();
	List.displaytail();
	List.remove(1);
	List.displayhead();
	List.displaytail();
	List.remove(12);
	List.displayhead();
	List.displaytail();
	return 0;
}
