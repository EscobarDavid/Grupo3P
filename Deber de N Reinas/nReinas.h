/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber de las 8 reinas.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 04/08/2022
	Fecha de modificación: 05/08/2022
	Grupo 8
	https://github.com/EscobarDavid/Grupo3P
*/

#include <iostream>
#include <fstream>
#define A 8
#define N 6

using namespace std;

int reinas[N];
string tablero[A][A];
int contador;
fstream archivo;

bool valido(int i){
    bool v = true;

    for(int r=0;r<i;r++){
        v = v && (reinas[i] != reinas[r]);
        v = v && ((reinas[i]-i) != (reinas[r]-r));
        v = v && ((reinas[i]+i) != (reinas[r]+r));
    }
    return v;
}

void mostrarTablero(){
   
    contador++;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            *(tablero[i]+j) = "*";
        }
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            tablero[reinas[j]][j] = "R";
        }
    }

    cout << "\nMostrando Tablero" << endl;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout <<*(tablero[i]+j)<<"|";
        }
        cout << endl;
    }
    cout << endl;
    

}

void ponerReina(int i, bool &solucion){
    int k=0;
    solucion = false;
    
    do{
       reinas[i] = k;
        k++;

        mostrarTablero();
        cout << endl;

        if(valido(i)){
            if(i<(N-1)){
                ponerReina(i+1, solucion);

                if(!solucion){
                    reinas[i]  = 0;
                }
            }
            else{
                solucion = true;
            }
        }
    }while(!solucion && (k<N));
    
    
}
void guardarSolucionTxt(){
    ofstream archivo;
    archivo.open("sol.txt", ios::out);
    archivo << "Solucion del problema de las N reinas" << endl;
    archivo << "-------------------------------------" << endl;
    archivo << "N = " << N << endl;
    archivo << "-------------------------------------" << endl;
    archivo << "Solucion:" << endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            archivo << tablero[i][j]<< "|";
        }
        archivo << endl;
    }
    archivo << endl;
    archivo.close();
}

void nReinas(){
    bool solucion;

    ponerReina(0, solucion);

    if(solucion){
        cout << "Solucion encontrada" << endl;
        mostrarTablero();
        cout << "Se guardo en el txt" << endl;
        guardarSolucionTxt();

    }
    else{
        cout << "No hay solucion" << endl;
    }
}