/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber: Mochila - Cambio de moneda 
	Arias Sebasti�n, Escobar David, Portilla Diego, Valdiviezo Darwin, Y�nez Michelle
	Fecha de creaci�n: 13/08/2022
	Fecha de modificaci�n: 14/08/2022
	Grupo 8
	
*/


#include "Cambio.h"

void Cambio::backtraking(int cantidad, int cambio[], int n, int indice)
{
    int c1 = 0, c2 = 0, c3 = 0, c = 0, c4 = 0, total=0;
        if (cantidad < 0) {
           return;
        }

        if (cantidad == 0) {
            for (int i = 0; i < v.size(); i++)
            {
                if (v.at(i) == 50)
                {
                    c++;
                }
                if (v.at(i) == 25)
                {
                    c1++;
                }
                if (v.at(i) == 10)
                {
                    c2++;
                }
                if (v.at(i) == 5)
                {
                    c3++;
                }
                if (v.at(i) == 1)
                {
                    c4++;
                }
            }
            total = c +c1 + c2 + c3 + c4 ;
            if (total == cantidad)
            {
                for (int i = 0; i < v.size(); i++)
                {
                    cout << v.at(i) << " ";
                }
                cout << endl;
            }
            v1.push_back(total);
            if (total== *min_element(std::begin(v1), std::end(v1)))
            {
                cout << "\n";
                cout << "Total Monedas " << total << endl;
                cout << "Numero de 50 centavos: " << c << endl;
                cout << "Numero de 25 centavos: " << c1 << endl;
                cout << "Numero de 10 centavos: " << c2 << endl;
                cout << "Numero de 5 centavos: " << c3 << endl;
                cout << "Numero de 1 centavos: " << c4 << endl;
            }
        }
        for (int i = indice; i < n; ++i) {
                v.push_back(cambio[i]);
                backtraking(cantidad - cambio[i], cambio, n, i);
                v.pop_back();
        }
}


