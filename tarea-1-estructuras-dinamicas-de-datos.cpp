// Ejercicio.

/* Vectores din�micos. */
	
/* Operadores new y delete consisten en asignar un espacio en memoria para asi no utilizar m�s del que se necesite
y no desperdiciar memoria, el new crea el espacio que se necesitar� �nicamente y retorna la ubicaci�n
en memoria mientras que el delete libera el espacio utilizado anteriormente con el new */
	
// Para el ejemplo crear� un minijuego que de 10 numeros escoger�s 3 y si sale alguno el numero espec�ficado por el mismo programa
// ganar�s, y sino perder�s, si te sali� a la primera consigues 5 puntos, si sali� a la segunda 3 puntos y a la tercera 1 punto
// Si no te sale el n�mero y especif�cas que s�, se te restar� un punto.

// Repositorio de GitHub: https://github.com/CRVPolanco/curso-estructuras-dinamicas-de-datos/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int *vector, mayor = 0;

void randomizarDatos(int );
void mostrarDatos(int, int *);

int main(){
	
	int cantidad;
	cout<<"Cuantos numeros quieres randomizar para sacar el mayor en el vector: "; cin>>cantidad;
	
	randomizarDatos(cantidad);
	mostrarDatos(cantidad, vector);
	
	delete[] vector;
	
	system("pause");
	return 0;
}

void randomizarDatos(int cantidad){
	cout<<"Randomicemos datos\n\n";
	srand(time(NULL));
	vector = new int[cantidad];
	for(int i=0; i<cantidad; i++){
		vector[i] = 1 + rand()%(1000);
	}
}
void mostrarDatos(int cantidad, int *vector){
	
	cout<<"\n\nMostrando Datos\n\n";
	
	for(int i=0; i<cantidad; i++){
		if(vector[i] > mayor){
			mayor = vector[i];
		}
		cout<<"  "<<vector[i];
	}
	
	cout<<"\n\nEl mayor numero del arreglo es: "<<mayor<<"\n\n"; 
	
}
