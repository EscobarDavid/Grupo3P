/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber: Mochila - Cambio de moneda 
	Arias Sebasti�n, Escobar David, Portilla Diego, Valdiviezo Darwin, Y�nez Michelle
	Fecha de creaci�n: 13/08/2022
	Fecha de modificaci�n: 14/08/2022
	Grupo 8
	
*/


#include "mochila.h"
#include "Cambio.h"
#include "Cambio.cpp"
#include <time.h>
#include <iostream>
using namespace std;


void cambioDinero();
void mochila();
bool isNumber(string s);

int main()
{
    string opcion;

    system("cls");

    do{
        cout << "Bienvenido al programa de mochila y cambio de monedas" << endl;
        cout << "1. Cambio de dinero" << endl;
        cout << "2. Mochila" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if(isNumber(opcion)){
            int opcion1 = atoi(opcion.c_str());
            switch(opcion1){
                case 1:
                    system("cls");
                    cambioDinero();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    mochila();
                    system("pause");
                    break;
                case 3:
                    cout << "Saliendo del programa" << endl;
                    system("pause");
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
        }else{
            cout << "Opcion no valida" << endl;
        }
        system("cls");
    }while(opcion != "3");
    return 0;
}


void cambioDinero(){
    srand(time(NULL));
	Cambio cambio_monedas;
	cout << " Ingrese cantidad: " << endl;
	cin >> cambio_monedas.cantidad;
	cambio_monedas.gen_cambio();
}

void mochila(){
    Mochila m;
    m.backpack();

}

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }

    }
    
    return true;
}