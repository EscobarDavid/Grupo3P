/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber Cambio  de monedas.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 14/08/2022
	Fecha de modificación: 14/08/2022
	Grupo 8
	https://github.com/EscobarDavid/Grupo3P
*/

#include <iostream>
#include "Cambio.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Cambio cambio_monedas;
	cout << " Ingrese cantidad: " << endl;
	cin >> cambio_monedas.cantidad;
	cambio_monedas.gen_cambio();

}


