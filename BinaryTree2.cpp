// BinaryTree2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

template <class T>
class mayor {
public:
	inline bool operator()(T a, T b) {
		return a > b;
	}
};

template <class T>
class minor {
public:
	inline bool operator()(T a, T b) {
		return a < b;
	}
};


template <class T>
class Cnode {
public:
	Cnode(T x) {
		m_data = x;
		m_node[0] = m_node[1] = 0;
	}

	~Cnode() {
		m_node[0] = m_node[1] = 0;
	}

	T m_data;
	Cnode<T>*m_node[2];
};

template <class T, class S>
class Btree {
public:
	Btree() {
		m_root = 0;
	}
	bool find(T x, Cnode<T>** &p);
	bool insert(T x);
	bool remove(T x);
	void displayinorder(Cnode<T>*p);
	void displaypreorder(Cnode<T>*p);
	void displaypostorder(Cnode<T>*p);
	void getroot();
	Cnode<T>* m_root;
	S cmp;
};

template <class T, class S>
bool Btree<T, S>::find(T xi, Cnode<T> ** &p) {
	for (p = &m_root; (*p) && (*p)->m_data != xi; p = &((*p)->m_node[cmp((*p)->m_data, xi)]));
	return (*p) != 0;
};

template <class T, class S>
bool Btree<T, S>::insert(T x) {
	Cnode<T>** p;
	if (find(x, p)) return 0;
	(*p) = new Cnode<T>(x);
	return 1;
}

template<class T>
void rep(Cnode<T> **&q) {
	srand(time(NULL));
	int num = rand() % 2;
	//int num = 1;
	if (num) {
		q = &((*q)->m_node[1]);
		while ((*q)->m_node[0])q = &((*q)->m_node[0]);
	}
	else {
		q = &((*q)->m_node[0]);
		while ((*q)->m_node[1])q = &((*q)->m_node[1]);
	}
}


template <class T, class S>
bool Btree<T, S>::remove(T x) {
	Cnode<T> **p;
	if (!find(x, p))return 0;
	if ((*p)->m_node[0] && (*p)->m_node[1]) {
		//Nodo<T> **q = &((*p)->right->left);
		Cnode<T> **q = &m_root;
		rep(q);
		(*p)->m_data = (*q)->m_data;
		p = q;
	}
	Cnode<T> *t = *p;
	if ((*p)->m_node[1])*p = (*p)->m_node[1];
	else *p = (*p)->m_node[0];
	//*p = (*p)->m_node[(*p)->m_node[0]];
	delete t;
	return 1;
}

template <class T, class S>
void Btree<T, S>::displayinorder(Cnode<T>*p) {
	if (!p) return;
	displayinorder(p->m_node[0]);
	cout << (p->m_data) << endl;
	displayinorder(p->m_node[1]);
}

template <class T, class S>
void Btree<T, S>::displaypreorder(Cnode<T>*p) {
	if (!p) return;
	cout << (p->m_data) << endl;
	displaypreorder(p->m_node[0]);
	displaypreorder(p->m_node[1]);
}

template <class T, class S>
void Btree<T, S>::displaypostorder(Cnode<T>*p) {
	if (!p) return;
	displaypostorder(p->m_node[0]);
	displaypostorder(p->m_node[1]);
	cout << (p->m_data) << endl;
}
template<class T, class S>
void Btree<T, S>::getroot() {
	cout <<"Root :"<<m_root->m_data << endl;
}

int main() {

	Btree<int, minor<int> >arbolitodenectar;
	arbolitodenectar.insert(77);
	arbolitodenectar.insert(42);
	arbolitodenectar.insert(89);
	arbolitodenectar.insert(47);
	arbolitodenectar.insert(34);
	arbolitodenectar.insert(63);
	arbolitodenectar.insert(69);
	arbolitodenectar.remove(69);
	arbolitodenectar.remove(77);
	arbolitodenectar.remove(42);
	arbolitodenectar.remove(63);
	arbolitodenectar.remove(47);
	arbolitodenectar.remove(34);
	arbolitodenectar.remove(89);


	//arbolitodenectar.getroot();
	cout << "INORDER" << endl;
	arbolitodenectar.displayinorder(arbolitodenectar.m_root);
	cout << "PREORDER" << endl;
	arbolitodenectar.displaypreorder(arbolitodenectar.m_root);
	cout << "POSTORDER" << endl;
	arbolitodenectar.displaypostorder(arbolitodenectar.m_root);
	return 0;
}


