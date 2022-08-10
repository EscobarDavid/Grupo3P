/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber: Generar un laberinto desde un archivo txt.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 05/08/2022
	Fecha de modificación: 07/08/2022
	Grupo 8
	
*/

#include <iostream>
#include <fstream>
#include "Laberinto.h"
int main()
{
	Laberinto l;
	printf("----------Laberinto------------\n");
    int maze[N][N] = { { 1, 0, 0, 1 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 },};
					
    l.resolverLab(maze);  
    l.leerArchivo("laberinto.txt",maze);
    return 0;
}
