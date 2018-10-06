// BinaryTree1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// BinaryTree single pointer

#include "pch.h"
#include <iostream>

using namespace std;

template<class T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
template<class T>
struct mayor {
	inline bool operator()(int a, int b) {
		return a < b;
	}
};
struct minor {
	inline bool operator()(int a, int b) {
		return a > b;
	}
};
template<class T>
class Cnode {
public:
	Cnode(T, Cnode<T>* = NULL, Cnode<T>* = NULL);
	T m_data;
	Cnode <T>* m_node[2];
};
template<class T, class C>
struct Btree {
	C cmp;
	Cnode <T> * m_root = NULL;
	int t = 0;

	bool find(T, Cnode<T>*&);
	void insert(T);
	void remove(T);
	void displayinorder(Cnode<T>*p);
	void displaypreorder(Cnode<T>*p);
	void displaypostorder(Cnode<T>*p);
};

//Definicion Funciones
template<class T>
Cnode<T>::Cnode(T v, Cnode<T> * p, Cnode<T> * q) {
	m_data = v;
	m_node[0] = p;
	m_node[1] = q;
}
template<class T, class C>
bool Btree<T, C>::find(T a, Cnode<T>*&p) {
	Cnode<T>*t = p;
	while (p && a != p->m_data) {
		t = p;
		p = p->m_node[cmp((p->m_data), a)];
	}
	bool b = p;
	p = t;
	return b;
}
template<class T, class C>
void Btree<T, C>::insert(T a) {
	if (m_root) {
		Cnode<T>*p = m_root;
		if (!find(a, p)) {
			p->m_node[cmp((p->m_data), a)] = new Cnode<T>(a);
		}
	}
	else m_root = new Cnode<T>(a);
}
template <class T, class C>
void Btree<T, C>::remove(T a) {
	if (m_root) {
		Cnode<T>*p = m_root;
		bool b = 0;
		if (find(a, p)) {
			if (p->m_data != a) {
				b = p->m_node[1] && p->m_node[1]->valor == a;
				if (p->m_node[b]->next[1]) {
					Cnode<T>*y = p->m_node[b];
					p = p->m_node[b];
					b = 1;
					Cnode<T>*x = p->m_node[b];
					while (x->m_node[0]) {
						p = p->m_node[b];
						x = x->m_node[0];
						b = 0;
					}
					y->m_data = p->m_node[b]->valor;
					y = p->m_node[b];
					p->m_node[b] = p->m_node[b]->next[1];
					delete y;
				}
				else {
					Cnode<T>*x = p->m_node[b];
					p->m_node[b] = p->m_node[b]->next[0];
					delete x;
				}
			}
			else {
				p = m_root;
				if (m_root->m_node[1]) {
					bool b = 1;
					Cnode<T>* x = p->m_node[b];
					while (x->m_node[0]) {
						p = p->m_node[b];
						x = x->m_node[0];
						b = 0;
					}
					m_root->m_data = p->m_node[b]->valor;
					x = p->m_node[b];
					p->m_node[b] = p->m_node[b]->next[1];
					delete x;
				}
				else {
					m_root = m_root->m_node[0];
					delete p;
				}
			}
		}
	}
}

template <class T, class C>
void Btree<T, C>::displayinorder(Cnode<T>*p) {
	if (!p) return;
	displayinorder(p->m_node[0]);
	cout << (p->m_data) << endl;
	displayinorder(p->m_node[1]);
}

template <class T, class C>
void Btree<T, C>::displaypreorder(Cnode<T>*p) {
	if (!p) return;
	cout << (p->m_data) << endl;
	displaypreorder(p->m_node[0]);
	displaypreorder(p->m_node[1]);
}

template <class T, class C>
void Btree<T, C>::displaypostorder(Cnode<T>*p) {
	if (!p) return;
	displaypostorder(p->m_node[0]);
	displaypostorder(p->m_node[1]);
	cout << (p->m_data) << endl;
}

int main() {
	Btree<int, mayor<int>> arbolitodenectar;
	arbolitodenectar.insert(77);
	arbolitodenectar.insert(42);
	arbolitodenectar.insert(89);
	arbolitodenectar.insert(47);
	arbolitodenectar.insert(34);
	arbolitodenectar.insert(63);
	arbolitodenectar.insert(69);
	cout << "INORDER" << endl;
	arbolitodenectar.displayinorder(arbolitodenectar.m_root);
	cout << "PREORDER" << endl;
	arbolitodenectar.displaypreorder(arbolitodenectar.m_root);
	cout << "POSTORDER" << endl;
	arbolitodenectar.displaypostorder(arbolitodenectar.m_root);
	return 0;
	



	return 0;

}
