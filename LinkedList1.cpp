// LinkedList1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>

using namespace std;

template <class T> 
class Cnode {
public:
	T m_data;
	Cnode<T>* m_next;
	Cnode(T x);
	Cnode(T x, Cnode<T>* n);
};

template <class T> 
Cnode<T>::Cnode(T x, Cnode<T> *n) {
	m_data = x;
	m_next = n;
}

template <class T>
Cnode<T>::Cnode(T x) {
	m_data = x;
	m_next = NULL;
}

template <class T> 
class Clist {
private:
	Cnode<T> *m_head;
public:
	Clist(T);
	Clist();
	void display();
	bool find(T x, Cnode<T>*& prev);
	void insert(T x);
	void remove(T x);
};

template <class T>
Clist<T>::Clist(T x) {
	Cnode<T> *first = new Cnode<T>(x, NULL);
	m_head = first;
	
}

template <class T>
Clist<T>::Clist() {
	m_head = NULL;
}

template <class T>
bool Clist<T>::find(T x, Cnode<T>*& prev) {
	Cnode<T> *p = m_head;
	prev = m_head;
	if (p && p->m_data < x) {
		p = p->m_next;
	}
	while (p && (p->m_data < x)) {
		p = p->m_next;
		prev = prev->m_next;
	}
	return (p && p->m_data == x);
}

template <class T>
void Clist<T>::insert(T x) {
	Cnode<T> *prev;
	bool busq = this->find(x, prev);
	if (!busq) {
		Cnode<T> *nod = new Cnode<T>(x);
		if (m_head == NULL) {
			this->m_head = nod;
		}
		else {
			if (prev != m_head) {
				if (!prev) {
					nod->m_next = NULL;
					prev->m_next = nod;
				}
				else {
					nod->m_next = prev->m_next;
					prev->m_next = nod;
				}
			}
			else {
				if (prev->m_data > x) {
					nod->m_next = prev;
				}
				else {
					nod->m_next = prev->m_next;
					prev->m_next = nod;
				}
			}

		}
	}
}

template <class T>
void Clist<T>::display() {
	Cnode<T>* t = m_head;
	cout << "Head -> ";
	while (t->m_next != NULL) {
		cout << t->m_data << " -> ";
		t = t->m_next;
	}
	cout << t->m_data<<" -> ";
	cout << " NULL " << endl;
}

template <class T>
void Clist<T>::remove(T a) {
	Cnode<T> *prev;
	cout << "Borrando: " << a << "\n";
	bool busq = this->find(a, prev);
	if (busq) {
		if (prev == m_head) {
			Cnode<T>* temp = m_head->m_next;
			delete m_head;
			m_head = temp;
		}
		else {
			Cnode<T>* temp = (prev->m_next->m_next);
			delete prev->m_next;
			prev->m_next = temp;
		}
	}
	else {
		cout << "El valor " << a << " no existe en la lista.\n";
	}
}

int main() {
	Clist<long> List;
	List.insert(29);
	List.display();
	List.insert(37);
	List.display();
	List.insert(42);
	List.display();
	List.remove(29);
	List.display();
	return 0;
}
