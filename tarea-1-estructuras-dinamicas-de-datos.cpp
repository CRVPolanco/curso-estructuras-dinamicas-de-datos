// Ejercicio.

/* Vectores dinámicos. */
	
/* Operadores new y delete consisten en asignar un espacio en memoria para asi no utilizar más del que se necesite
y no desperdiciar memoria, el new crea el espacio que se necesitará únicamente y retorna la ubicación
en memoria mientras que el delete libera el espacio utilizado anteriormente con el new */
	
/* Números random, se guardarán en vector dinámico y mostrará lista de números y el mayor número obtenido de la aleartorización */

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
