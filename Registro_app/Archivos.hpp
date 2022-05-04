#pragma once
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <Windows.h>
#include "Arreglo.hpp"
using namespace std;
template <class T>
class Archivos
{
public:

	void agregarDato(T dato) {
		datos.add(dato);
	}
	void agregarUsuario(ofstream& archivo) {
		system("cls");
		cout << "Digite el destino del viaje : ";
		cin>>nameapp;
		archivo.open(nameapp.c_str(), ios::out | ios::app);
		cout << "Agregar el nombre del usuario" << endl;
		cin >> nombre;
		cout << "Agregar el apellido del usuario" << endl;
		cin >> apellido;
		cout << "Agregar DNI: ";
		cin >> codigo;
		cout << "Agregar edad: ";
		cin >> edad;
		cout << "Agregar lugar de recojo: ";
		cin >> ruta;
		archivo << nombre << " " << apellido << " " << codigo << " " << edad << " " << ruta << "\n";
		archivo << datos.getSize();
		for (int i = 0; i < datos.getSize(); i++) {
			datos.get(i).agregarUsario(archivo);
		}
		archivo.close();
		
	}
	void verUsuarios(ifstream& archivo) {
		system("cls");
		cout << "Digite el viaje que desea visualizar: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		cout << "\nUsuarios Registrados:" << endl;
		archivo >> nombre;
		while (!archivo.eof())
		{
			archivo >> apellido;
			archivo >> codigo;
			archivo >> edad;
			archivo >> ruta;
			cout << "Nombre-----:" << nombre << endl;
			cout << "Apellido---:" << apellido << endl;
			cout << "DNI--------:" << codigo << endl;
			cout << "Edad-------:" << edad << endl;
			cout << "Ruta de desplazamiento-----:" << ruta << endl;
			cout << "****************************************************" << endl;
			archivo >> nombre;
			for (int i = 0; i < datos.getSize(); i++) {
				datos.get(i).verUsuarios(archivo);
			}
		}

		archivo.close();
		system("pause");
	}
	void Buscarusuario(ifstream& archivo) {
		system("cls");
		cout << "Digite el destino para buscar el usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		bool usuarioencontrado = false;
		cout << "Digite el DNI que desea buscar" << endl;
		cin >> codigoaux;
		archivo >> nombre;
		while (!archivo.eof() && !usuarioencontrado)
		{
			archivo >> apellido;
			archivo >> codigo;
			if (codigo == codigoaux)
			{
				cout << "Nombre-----:" << nombre << endl;
				cout << "Apellido---:" << apellido << endl;
				cout << "DNI--------:" << codigo << endl;
				cout << "Edad-------:" << edad << endl;
				cout << "Ruta de desplazamiento-----:" << ruta << endl;
				cout << "****************************************************" << endl;
				usuarioencontrado = true;
			}
			archivo >> nombre;
		}
		archivo.close();
		if (!usuarioencontrado)
		{
			cout << "*****El usuario que desea encontrar no existe o no esta registrado*****" << endl;

		}
		system("pause");
	}
	void Editarusuario(ifstream& archivo) {
		system("cls");
		cout << "Digite el destino del viaje para editar el nombre de usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		ofstream archivoaux("datosauxiliar.txt", ios::out);
		if (archivo.is_open())
		{
			cout << "\nDigite el DNI del usuario: ";
			cin >> codigoaux;
			archivo >> nombre;
			while (!archivo.eof())
			{
				archivo >> apellido;
				archivo >> codigo;
				if (codigo == codigoaux)
				{
					cout << "Digite el nuevo Nombre: " << endl;
					cin >> nombreaux;
					archivoaux << nombreaux << " " << apellido << " " << codigo <<edad <<" "<<ruta<< "\n";
				}
				else {
					archivoaux << nombre << " " << apellido << " " << codigo << edad << " " << ruta << "\n";
				}
				archivo >> nombre;
				archivo << datos.getSize();
				for (int i = 0; i < datos.getSize(); i++) {
					datos.get(i).EliminarUsuario(archivo);
				}
			}
			archivo.close();
			archivoaux.close();
		}
		remove(nameapp.c_str());
		rename("datosauxiliar.txt", nameapp.c_str());
	}
	void EliminarUsuario(ifstream& archivo) {
		system("cls");
		cout << "Digite el destino del viaje para eliminar el usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		ofstream archivoaux("datosauxiliar.txt", ios::out);
		if (archivo.is_open())
		{
			cout << "\nDigite el DNI del usuario: ";
			cin >> codigoaux;
			archivo >> nombre;
			while (!archivo.eof())
			{
				archivo >> apellido;
				archivo >> codigo;
				if (codigo == codigoaux)
				{
					cout << "El usuario ha sido eliminado " << endl;
					system("pause");

				}
				else {
					archivoaux << nombre << " " << apellido << " " << codigo << edad << " " << ruta << "\n";
				}
				archivo >> nombre;
				archivo << datos.getSize();
				for (int i = 0; i < datos.getSize(); i++) {
					datos.get(i).EliminarUsuario(archivo);
				}
			}
			archivo.close();
			archivoaux.close();
		}
		remove(nameapp.c_str());
		rename("datosauxiliar.txt", nameapp.c_str());
	}
	void buscarpornombre() {

	}
private:
	LinkedList<T> datos;
	string nombre, apellido, nombreaux, codigo, codigoaux, edad, ruta, nameapp;
};




