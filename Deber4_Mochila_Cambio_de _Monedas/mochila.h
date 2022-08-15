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
#include <vector>
#include <stdio.h>

#define maxN 200	
#define maxC 1000	

using namespace std;


class Mochila{
    public:
    int tabela[maxN+1][maxC+1];
    int peso[maxN+1];
    int valor[maxN+1];
    void backpack();
};

void Mochila::backpack(){
	int c, v, x, i, b, n, s, soma, aux;
	vector<int> mochilaFinal;
 	
 	printf("\nDigite la capacidad de la mochila y el numeros de objetos \n");
 
    scanf("%d %d", &c, &n);
	
 
		for(i = 1; i<=n; i++){
			cout << "Digite el peso del item " << i << ": ";
            scanf("%d", &x);
            cout << "Digite el valor del item " << i << ": ";
            scanf("%d", &v);
			peso[i] = x;
			valor[i] = v;
		}
		for(i=0; i<=n; i++){
			tabela[i][0] = 0;
		}
 
		for(b = 1; b<=c; b++){
			tabela[0][b] = 0;
 
			for(i=1; i<=n; i++){
				s = tabela[i-1][b];
 
				if( peso[i] <= b){
					soma = tabela[i-1][b-peso[i]] + valor[i];
					if( s < soma){
						s = soma;
					}
				}
 
				tabela[i][b] = s;
			}
		}
 
 
		printf("%d\n", tabela[n][c]); 
 
    
 
 
		for(i= 0; i<=n; i++){
			for(b = 0; b<=c; b++){
				printf("%d\t", tabela[i][b]);
			}
			puts("");
		}
 
 
 
		 i = n;
		 b = c;
		 aux = tabela[i][b];
 
		 while(aux){
			 if(tabela[i][b] != tabela[i-1][b]){ 
				 mochilaFinal.push_back(i);
				 b -= peso[i];
			 }
			 i--;
			 aux = tabela[i][b];
		 }
 
		 cout<<"Los items : ";
		 for(i=0; i<int(mochilaFinal.size()); i++){
			 printf("%d ", mochilaFinal[i]);
		 }
		 cout<<"->entraron en la mochila"<<endl;

        mochilaFinal.clear();
    
    

}


