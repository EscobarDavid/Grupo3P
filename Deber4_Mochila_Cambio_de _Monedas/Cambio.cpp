/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber Cambio  de monedas.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 14/08/2022
	Fecha de modificación: 14/08/2022
	Grupo 8
	https://github.com/EscobarDavid/Grupo3P
*/

#include "Cambio.h"

void Cambio::gen_cambio()
{
	int cantidad_entera = cantidad * 100;
	int monedas[5] = { 50, 25, 10, 5, 1 };
	int moneadas_cambio[5] = { 0,0,0,0,0 };
	int num_aleatorio = rand() % 5;
	int cambio;

	while (cantidad_entera < monedas[num_aleatorio]) {
		num_aleatorio = rand() % 5;
	}

	cambio = cantidad_entera / monedas[num_aleatorio];

	while (cambio < 1)
	{
		num_aleatorio = rand() % 5;
		cambio = cantidad_entera / monedas[num_aleatorio];
	}

	moneadas_cambio[num_aleatorio] = cambio;

	int restante = cantidad_entera - (monedas[num_aleatorio] * cambio);
	int resto_cambio = num_aleatorio;
	while (restante > 0) {
		if (num_aleatorio != resto_cambio) {
			cambio = restante / monedas[resto_cambio];

			if (cambio >= 1) {
				moneadas_cambio[resto_cambio] = cambio;
			}
			restante -= cambio * monedas[resto_cambio];

		}
		resto_cambio++;
	}
	cout << "Total Monedas " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "De " << monedas[i] << " centavos: " << moneadas_cambio[i] << endl;
	}
}
