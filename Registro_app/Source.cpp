#include <iostream>
#include <fstream>
#include <conio.h>
//#include <algorithm>
//#include <vector>
//#include <ctime>
//#include <cmath>
#include"Archivos.hpp"
using namespace std;

void verificacionM(int respuesta) {
	//Archivos* incio = new Archivos;
	//srand(time(NULL));
	//bool validado = false;
	//int a = rand()%20, 
	//int b = rand()%20;
	//vector<int> verif{ a,b };

	//sort(verif.begin(), v.end(), [=](int a, int b) {
	//	return a + b;
	//	});
	//cout << "\nVerificar si no es un robot, colocar la respuesta: ";
	//cout << return a + b;
	//cin >> respuesta;
	//for_each(verif.begin(), v.end(), [](int respuesta) {
	//	cout << respuesta << endl;
	//	if (respuesta == return a + b)
	//	{
	//		cout << "\nVerificacion comprobado" << endl;
	//		bool validado = true;
	//		system("pause")
	//	}
	//	else cout << "\nNo se ha verificado" << endl;
	//	});
}
int menu() {
	int men;
	system("cls");
	cout << "<-----Bienvenido a la base de datos de viajes UBER----->" << endl;
	cout << "1.- Agregar Usuario" << endl;
	cout << "2,. Ver Usuarios" << endl;
	cout << "3,. Buscar Usuarios" << endl;
	cout << "4,. Editar Usuarios" << endl;
	cout << "5,. Eliminar Usuarios" << endl;
	cout << "6.- Salir" << endl;
	cout << "Opcion:";
	cin >> men;
	return men;
}
template <class T>
int main() {
	ofstream Escritura;
	ifstream lectura;
    Archivos<LinkedList<T>*>archivo;
	int m;
	do
	{
		m = menu();
		switch (m)
		{
		case 1:archivo.agregarUsuario(Escritura); break;
		case 2:archivo.verUsuarios(lectura); break;
		case 3:archivo.Buscarusuario(lectura); break;
		case 4:archivo.Editarusuario(lectura); break;
		case 5:archivo.EliminarUsuario(lectura); break;
		}
	} while (m != 6);
	return 0;
}