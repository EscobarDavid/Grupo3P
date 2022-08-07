/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber: Generar un laberinto desde un archivo txt.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 04/08/2022
	Fecha de modificación: 05/08/2022
	Grupo 8
	
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include <fstream>
using namespace std;
#define N 4
class Laberinto
{
public:
    bool backtraking(int maze[N][N], int x,int y, int sol[N][N]);
    void imprimirSolucion(int sol[N][N]);
    bool validar(int maze[N][N], int x, int y);
    bool resolverLab(int maze[N][N]);
    void leerArchivo(char *fileName,int sol[N][N]);
    void MuestraLaberinto();
};
