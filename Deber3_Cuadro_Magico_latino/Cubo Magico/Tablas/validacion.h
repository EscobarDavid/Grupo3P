/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber:Cubo Magico
	Arias Sebasti�n, Escobar David, Portilla Diego, Valdiviezo Darwin, Yanez Michelle
	Fecha de creacion: 08/08/2022
	Fecha de modificacion: 09/08/2022
	Grupo 8
	
*/

#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

class Validacion {
public:
	bool validar(string, int);
};



/**
	@param tipo 1 para enteros 2 para flotantes
*/
bool Validacion::validar(string entrada, int tipo) {
	int contador = 0;
	try {
		for (int i = 0; i < entrada.length(); i++) {
			if (isalpha(entrada[i])) {
				throw 1;
			}
			if (!isdigit(entrada[i]) && tipo == 1) {
				throw 1;
			}
			if (entrada[i] == '.') {
				contador++;
			}
			if ((isdigit(entrada[i]) == 0 && entrada[i] != '.') || (contador>1)) {				
				throw 1;
			}			
		}	
	}
	catch (int e) {
		return true;
	}	
	return false;
}
