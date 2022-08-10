/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber:Cubo Magico
	Arias Sebasti�n, Escobar David, Portilla Diego, Valdiviezo Darwin, Y�nez Michelle
	Fecha de creaci�n: 08/08/2022
	Fecha de modificaci�n: 09/08/2022
	Grupo 8
	
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include "CuboMagico.h"
#include "Ingreso.h"

using namespace std;

bool isNumber(string str);
void cuboMagicoLizardo();
int **cuadrado;
CuboMagico cubo=CuboMagico(cuadrado);

int main()
{
    string opcion;

    system("cls");

    do{
    cout << "\t\tBienvenido al programa de la resolucion de tablas " << endl;
    cout << "1. Resoluacion de cubo magico (Camila)" << endl;
    cout << "2. Resolucion de cubo magico (Michell)" << endl;
    cout << "3. Resolucion de cubo magico (Lizardo)" << endl;
    cout << "4. Resolucion de cuadrado latino (David)" << endl;
    cout << "5. Resolucion el codigo de pascal"<<endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    if(isNumber(opcion)){
            int opcion1 = atoi(opcion.c_str());
            switch(opcion1){
                case 1:
                    system("cls");   
                    cubo.cuboMagicoCamila();
                    system("pause"); 
                    break;
                case 2:
                    system("cls");      
                    cubo.cuboMagicoMishell();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    cuboMagicoLizardo();
                    cout<<endl;
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    cubo.cuadradoLatino();
                    cout<<endl;
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    int n;
                    cout<<"Ingrese la dimension de la piramide: "<<endl;
                    cin>>n;
                    cubo.resolucionPiramidePascal(n);
                    cout<<endl;
                    system("pause");
                    break;
                case 6:
                    cout << "Saliendo del programa" << endl;
                    system("pause");
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    system("pause");
                    break;
            } 
        }else{
            cout << "Opcion no valida" << endl;
            system("pause");
        }
        system ("cls");
    }while(opcion != "6");
}

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }

    }
    
    return true;
}
void cuboMagicoLizardo(){
    int **cuadrado;
            Ingreso ingreso;
            int num;
            string dim;
            do{
                dim=ingreso.leer("Ingrese el orden (impar entre 3 y 15) : ",2);
                istringstream (dim) >> num;
            }while(num%2==0||num<0);

                num=2*num-1;

                cuadrado=(int**)calloc(num,sizeof(int*));
                for(int i=0;i<num;i++){
                    *(cuadrado+i)=(int*)calloc(num,sizeof(int));
                }

                CuboMagico cubo=CuboMagico(cuadrado);
                cubo.llenar(num,num);
                cubo.mostrar(num,num);
}