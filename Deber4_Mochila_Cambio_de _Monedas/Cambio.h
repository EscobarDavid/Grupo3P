/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber: Mochila - Cambio de moneda 
	Arias Sebasti�n, Escobar David, Portilla Diego, Valdiviezo Darwin, Y�nez Michelle
	Fecha de creaci�n: 13/08/2022
	Fecha de modificaci�n: 14/08/2022
	Grupo 8
	
*/
#pragma once
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
class Cambio
{
public:
	vector<int> v;
	vector<int> v1;
	void backtraking(int cantidad, int cambio[], int n, int indice);
    void ramdomSolution();
};
