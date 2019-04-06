/*	EXAMEN UNIDAD 1 - PRACTICO POR EQUIPO - 01/01/2019
	EQUIPO (GRUPO 2):
		- ARMANDO RODRIGUEZ HERNANDEZ  1730246
		- JOSE RAFAEL PEREZ RODRIGUEZ 1730269
		- PERLA CECILIA NAVA CEPEDA 1730033
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctime>
#include <fstream>
#include <stdio.h>
using namespace std;

//const int SOLUCIONES = 100;
int medida = 0;
char array[128][128]; // Guardara el contenido del .txt
int guiones[128][128]; // Guardara las posiciones de los guiones (1 = '-', 0 = un numero).
void limpiarArrayGuiones();



void imprimirArray(){
	int saltoLinea = 8;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<"\n";
	}
}

// Generara y situara los numeros de forma random en la posicion de los '-'
void generarRandom(){
	int n = 0, aux = 0;
	char convertir_n_char[2] ;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(1 == guiones[i][j]){
				aux++;
				n = (int)1+(rand() % (10-1));
				// El array es de tipo char, por tanto el numero generado debe ser del mismo.
				//itoa(n, convertir_n_char, 10);
				sprintf(convertir_n_char, "%d", n);
				array[i][j] = convertir_n_char[0];
			}
		}
	}
	imprimirArray();
}

// Buscara y guardara la posicion de los '-'
void buscarGuiones(){
	limpiarArrayGuiones();
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(array[i][j] == '-'){
				guiones[i][j] = 1; // 1 = existe un espacio en blanco (-).
			}
		}
	}
}

// Regresara los '-' a su posicion inicial
void regresarGuiones(){
	int aux = 0;
	for(int i = 0; i < (medida-1); i++){
		for(int j = 0; j < 9; j++){
			if(1 == guiones[i][j]){
				array[i][j] = '-';
				aux++;
			}
		}	
	}
}




int main(int argc, char const *argv[]){
	srand(time(0));
	ifstream archivo(argv[1]);
	int i = 0;
	//archivo.open(argv[1], ios::in);

	// Valida si escribe el argumento
	if(argc < 2){
		cout<<"NO se recibio ningun argumento."<<endl;
		return 0;
	}
	// Valida si el archivo se puede existe y se puede leer
	/*if(archivo == NULL){
		cout<<"El archivo NO se encontro. Revise el argumento!"<<endl;
		return 0;
	}*/else{
		cout<<endl<<"Abriendo archivo "<<argv[1]<<"..."<<endl;
	}

	while(!archivo.eof()){
		for(int j = 0; j < 9; j++){
			archivo >> array[i][j];
		}
		i++;
		//if(archivo != " ")
		//	medida++;
	}

	cout<<"VECTOR INICIAL: "<<endl;
	imprimirArray();

	buscarGuiones();

	//-----------------------------------------------
	// Genera 100 soluciones
	for(i = 0; i < 3; i++){
		cout<<endl<<"VECTOR "<<i+1<<":"<<endl;
		generarRandom();

	}



	regresarGuiones();
	cout<<endl<<"REGRESANDO AL VECTOR INICIAL: "<<endl;
	imprimirArray();

	archivo.close();
	return 0;
}


// inicializa todas las posiciones de la matriz en 0.
void limpiarArrayGuiones(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			guiones[i][j] = 0;
		}
	}
}



/*
- multiplicar toda la fila (cada fila) - 9! (factorial). 
- multiplicar toda la columna - 9!.
- sumar todos los resultados.

*/

