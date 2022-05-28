// Ejercicio.

/* Vectores dinámicos. */
	
/* Operadores new y delete consisten en asignar un espacio en memoria para asi no utilizar más del que se necesite
y no desperdiciar memoria, el new crea el espacio que se necesitará únicamente y retorna la ubicación
en memoria mientras que el delete libera el espacio utilizado anteriormente con el new */
	
// Para el ejemplo crearé un minijuego que de 10 numeros escogerás 3 y si sale alguno el numero específicado por el mismo programa
// ganarás, y sino perderás, si te salió a la primera consigues 5 puntos, si salió a la segunda 3 puntos y a la tercera 1 punto
// Si no te sale el número y especifícas que sí, se te restará un punto.

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>

using namespace std;

int tiradas = 3, *vector;

void juego();

int main(){
	
	juego();
	
	//Liberamos el espacio en memoria luego de haberlo usado.
	delete vector;
	
	system("pause");
	return 0;
}
void juego(){
	
	int numero, numeroConseguido, numeroEspecificado, puntuacion = 0, i=0;
	bool verificador = true;
	char opt, opt2, repetir;
	
	//Aquí se crea el espacio necesario para que el vector guarde lo necesario en memoria. Y no desperdiciar espacio en memoria.
	vector = new int[tiradas];
	
	cout<<"Bienvenido al juego.\n\n";
	cout<<"\nQue comience el juego.\n";
	
	srand(time(NULL));
	
	numeroEspecificado = 1 + rand()%(10);
	
	cout<<"Se requiere conseguir el numero: "<<numeroEspecificado<<"\n\n";
	
	do{
		if(i == 3){
			break;
		}
		fflush(stdin);
		cout<<"Deseas escoger un numero (S/N): "; cin>>opt;
		numero = 1 + rand() % (10);
		cout<<"Te salio el numero: "<<numero<<endl;
		cout<<"Era ese (S/N): "; cin>>opt2;
		
		vector[i] += numero;
		
		if(opt2 == 'S' || opt == 's'){
			if(numero == numeroEspecificado && i == 0){
				puntuacion += 5;
				numeroConseguido = numero;
				verificador = false;
				break;
			}else if(numero == numeroEspecificado && i == 1){
				puntuacion += 3;
				numeroConseguido = numero;
				verificador = false;
				break;
			}else if(numero == numeroEspecificado && i == 2){
				puntuacion += 1;
				numeroConseguido = numero;
				verificador = false;				
				break;
			}else if(numero != numeroEspecificado && (opt2 == 's' || opt2 == 'S')){ 
				cout<<"No te ha salido ese numero, pierdes un punto.\n"<<endl;
				verificador = true;	
				puntuacion-=1;
			}
		}else if((opt2 == 'n' || opt2 == 'N') && i != 2){
			cout<<"\nOk, sigamos\n"<<endl;
		}
		i++;
		if(verificador == false){
			break;
		}
	}while((opt == 's' || opt == 'S') && verificador == true);
	
	if(numeroConseguido == numeroEspecificado){
		cout<<"\nFelicidades ganaste :D, lo conseguiste al intento Nro "<<i+1<<endl<<endl;
		cout<<"Tuviste una puntuacion de: "<<puntuacion<<endl<<endl;
	}else{
		cout<<"\n\nNo te salio el numero :(, tranquilo, puedes jugar de nuevo, esperemos que para la proxima tengas suerte :)"<<endl;
		cout<<"\nTuviste una puntuacion de: "<<puntuacion<<endl;
	};
	i=0;
	puntuacion = 0;
	verificador = true;
}
