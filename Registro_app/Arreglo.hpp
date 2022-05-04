#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList
{
private:
	T data;
	int tam;
public:
	Node<T>* first;
	Node<T>* last;
	ofstream Escritura;
	ifstream lectura;

	// Constructor:
	LinkedList<T>() {
		tam = 0;
		first = NULL;
		last = NULL;
	}

	// Metodos:

	// Devuelve el elemento de una posición dada:
	T get(int index) {

		if (index == 0) {                     
			return this->first->data;         
		}
		else {
			Node<T>* curr = this->first;      
			for (int i = 0; i < index; ++i) { 
				curr = curr->next;
			}
			return curr->data;                
		}
	}
	
	/*int getSize() {
		return tam;
	}*/

	//lambda ver.
	
	auto getSize = [&tam]() { return tam };
	
	// Agrega un elemento al inicio de la lista:

	/*void buscarelement(ifstream& Escritura) {
		Node<T>* aux = first;                
		
		while (aux != NULL) {                
			cout << " " << aux->data;        
			aux = aux->next;                 
		}
		cout << endl;
	}*/

	//Lambda ver.

	auto buscarelement = [](ifstream& escritura) {
		Node<T>* aux = first;

		while (aux != NULL) {
			cout << " " << aux->data;
			aux = aux->next;
		}
		cout << endl;
	};
	
	//void editelement(ifstream& Escritura) {
	//	Node<T>* aux = first;              
	//	
	//	while (aux != NULL) {              
	//		cout << " " << aux->data;     
	//		aux = aux->next;              
	//	}
	//	cout << endl;
	//}

	// lambda ver.

	auto editelement = [](ifstream& Escritura) {
		Node<T>* aux = first;
			
		while (aux != NULL) {              
			cout << " " << aux->data;     
			aux = aux->next;              
		}
		cout << endl;
	};

	
	/*void push(ofstream& Escritura) {
		Node<T>* aux = new Node<T>;         
		
		aux->data = data;                   
		aux->next = first;                  
		first = aux;                        

		tam++;
	}*/

	auto push = [](ofstream& Escritura) {
		Node<T>* aux = new Node<T>;

		aux->data = data;
		aux->next = first;
		first = aux;

		tam++;
	};
	
	// Agrega un elemento al final de la lista:
	//void add(ifstream& Escritura) {

	//	if (!first) { // Lista vacia	
	//		first = new Node<T>;        
	//		first->data = data;         
	//		first->next = NULL;         
	//		last = first;               
	//	}
	//	else { // Lista con elementos
	//		if (last == first) {        
	//			last = new Node<T>;     
	//			last->data = data;      
	//			last->next = NULL;      
	//			first->next = last;     
	//		}
	//		else {
	//			Node<T>* aux = new Node<T>;
	//			aux->data = data;       
	//			aux->next = NULL;  
	//			last->next = aux; 
	//			last = aux;  
	//		}
	//	}tam++;

	//}

	auto add = [](ifstream& Escritura) {
		if (!first) { // Lista vacia	
			first = new Node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		}
		else { // Lista con elementos
			if (last == first) {
				last = new Node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else {
				Node<T>* aux = new Node<T>;
				aux->data = data;
				aux->next = NULL;
				last->next = aux;
				last = aux;
			}
		}tam++;
	};
	
	// Elimina un elemento de la lista:
	/*void deleteNode(ifstream& lectura) {

		if (first->data == data) {              
			first = first->next;                
		}
		else {
			Node<T>* aux = first;              
			while (aux->next != NULL) {        
				if (aux->next->data == data) { 
					aux->next = aux->next->next;
				}
				else {
					aux = aux->next; 
				}
			}
		}
		tam--;
	}*/
	
	auto deleteNode = [](ifstream& lectura) {
		if (first->data == data) {
			first = first->next;
		}
		else {
			Node<T>* aux = first;
			while (aux->next != NULL) {
				if (aux->next->data == data) {
					aux->next = aux->next->next;
				}
				else {
					aux = aux->next;
				}
			}
		}
		tam--;
	};

	// Imprimir lista
	/*void printList(ifstream& lectura) {
		Node<T>* aux = first;         
		while (aux != NULL) {         
			cout << " " << aux->data; 
			aux = aux->next;          
		}
		cout << endl;
	}*/

	auto printList = [](ifstream& lectura) {
		Node<T>* aux = first;
		while (aux != NULL) {
			cout << " " << aux->data;
			aux = aux->next;
		}
		cout << endl;
	};
	
};
