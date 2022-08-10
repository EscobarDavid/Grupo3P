/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber:Cubo Magico
	Arias Sebastian, Escobar David, Portilla Diego, Valdiviezo Darwin, Yanez Michelle
	Fecha de creacion: 08/08/2022
	Fecha de modificacion: 09/08/2022
	Grupo 8
	
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define P 15 
#define CM(x,N) ( (x)<0 ? N+(x)%N : ((x)>=N ? (x)%N : (x)) )
using namespace std;

class CuboMagico{
private:
  int **cuadrado;
public:
    CuboMagico(int **);
    void llenar(int,int);
    void mostrar(int, int);
    int **getCuboMagicoCuadrado();
    void setCuboMagicoCuadrado(int **);
    void cuadradoLatino();
    void cuboMagicoCamila();
    void cuboMagicoMishell();
    void Prueba();
    void resolucionPiramidePascal(int n);


};

CuboMagico::CuboMagico(int **_cuadrado){
    cuadrado=_cuadrado;
}

int **CuboMagico::getCuboMagicoCuadrado(){
    return cuadrado;
}

void CuboMagico::setCuboMagicoCuadrado(int **_cuadrado){
    cuadrado=_cuadrado;
}


void CuboMagico::llenar(int a,int b){
    int x=0,k=0,p,j=0,t=0,s,d=0;
    cout<<"Ingrese el valor de incremento"<<endl;
    cin>>p;
    cout<<"Ingrese el valor de inicio"<<endl;
    cin>>s;

        x=(b-1)/2;
        t=((a+1)/2);
        s=(a-x-1)/2;
        d=x;

         for(int g=0; g<((a+1)/2);g++){
            j=g;
            k=g;
        for( int i=x;i>=j;i--){
            *(*(cuadrado+i)+k)=p;
             if( k<(d-s) ){
                *(*(cuadrado+i)+(k+t))=p;
			}
            if(k>(d+s)){
                *(*(cuadrado+i)+(k-t))=p;
            }
            if(i>(d+s)){
                *(*(cuadrado+(i-t))+k)=p;
            }
            if(i<(d-s)){
                *(*(cuadrado+(i+t))+k)=p;
            }

            k++;
            p++;
        }
        x++;
    }
}

void CuboMagico::mostrar(int a,int b){
    int x=0,t=0,s=0;
        t=((a+1)/2);
        x=(b-1)/2;
        s=(a-x-1)/2;
    cout<<"\nCuadrado Magico de orden "<<t<<"x"<<t<<endl;
     for(int l=0;l<a;l++){
                cout<<endl<<endl;
            for(int h=0;h<b;h++){
                if(h>=(x-s) && h<=(x+s) && l<=(x+s) && l>=(x-s)){
                    cout<<"\t"<<*(*(cuadrado+l)+h)<<"\t";
                }
        	}
		}
}



void CuboMagico :: cuboMagicoCamila(){
int cuadrado[15][15],x,y,n,N,centinela = 0,patron;
    do{
        cout<<"\n\tIngrese el orden (impar entre 3 y 15) : "<<endl;
        cin>>N;
    }while(!(N%2));
        for(x=0;x<N;x++)
        for(y=0;y<N;y++)
            cuadrado[x][y]=0;

        for(x=N/2,y=0,n=1;n<=N*N; )
        if (!cuadrado[x][y]){
            cuadrado[x][y]=n++;
            x=CM(x+1,N);
            y=CM(y-1,N);
        }else{x=CM(x-1,N),
              y=CM(y+2,N);
        }

        for(y=0;y<N;y++){
            cout<<endl;
            for(x=0;x<N;x++)
                cout<<cuadrado[x][y]<<"\t";
            cout<<endl;
        }

        cout <<"\n\n Suma = "<<((N*(N*N+1))/2)<<" -> Constante Magica"<<endl;

}

void CuboMagico :: resolucionPiramidePascal(int n){

    for (int i = 1; i <= n; i++)
	{ 
		int proceso = 1; 

		for (int j = 1; j < (n - i + 1); j++){
			cout << " ";
		}

		for (int k = 1; k <= i; k++)
		{

			cout << "  " << proceso ;
			proceso = proceso * (i - k) / k;
		}

		cout << endl << endl;
	}
    cout << endl;
}
    




void CuboMagico :: cuadradoLatino(){
    int n,i,j,k;
   
    printf ("ingrese el tamanio n del cuadrado: ");
    scanf ("%d",&n);
    cout<<"\nCuadrado latino de orden "<<n<<"x"<<n<<endl;
    cout <<endl;
    for(i=1;i<=n;i++) 
        {
            cout<<endl<<endl;
            for(j=i,k=1; k <=n ; k++,j++)
            {
                if (j>n) 
                {
                        for(j=1; k <= n ; k++,j++)
                        {
                              printf (" %d\t",j);
                        }
                }
               
                else
                     printf (" %d\t",j);
            }
        printf ("\n");
        }   
}

void CuboMagico :: cuboMagicoMishell(){
    int arr[P][P] = {0};
	int x=0,y,s=1,i,j,n=2,oldx,oldy,centinela=0, patron;
	
	while(n%2 == 0 || n > 15){
        cout<<"\n\tIngrese el orden (impar entre 3 y 15) : "<<endl;
        cin>>n;
	}
	y=n/2;
    cout<<"\nCuadrado Magico de orden "<<n<<"x"<<n<<endl;
	arr[x][y] = s;
	oldx = x;
	oldy = y;
	for(s = 2;s <= n*n;s++){			
		
		x = oldx - 1;
		y = oldy + 1;
		
		 
		 if (x <0) 
			 x = n-1; 
		 if (y> n-1) {
			 y = 0; 
		}
		if(arr[x][y] != 0){
			x = oldx+1;
			y = oldy;
		}
		arr[x][y] = s;
		oldx = x;
		oldy = y;
 
	}

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n\n");
	}
    cout <<"\n\n Suma = "<<((n*(n*n+1))/2)<<" -> Constante Magica"<<endl;

}

void CuboMagico :: Prueba(){
    int arr[P][P] = {0};
    int patron = 0 , centinela  =0,N,oldx,oldy,x,y,i,j,n=2,s;
    do{
        cout<<"\n\tIngrese el orden (impar entre 3 y 15) : "<<endl;
        cin>>N;
    }while(!(N%2));
    cout <<"Ingrese el centinela"<<endl;
    cin>>centinela;
    cout <<"Ingrese el patron"<<endl;
    cin>>patron;

    //funcion para sumar el centinela y el patron y luego el valor de la suma + el centinela
    int suma = centinela + patron;
    while (suma < N*N){
        suma = suma + centinela;
    }
    cout<<"\nCuadrado Magico de orden "<<N<<"x"<<N<<endl;
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            arr[i][j] = suma;
            suma = suma + centinela;
        }
    }
    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n\n");
    }
   
    

    

    
    
   


  
   
}