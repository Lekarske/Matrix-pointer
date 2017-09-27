#include <iostream>
#include <stdlib.h>

using namespace std;

int **matriz_1,fila,columna_fila,**matriz_2,columna,**matriz_3;//varaibles de caracter global

void espacio_matriz_1(int **matriz_1,int fila,int columna_fila){//separa espacio para una matriz 1
	for (int i=0;i<fila;i++) matriz_1[i] = new int [columna_fila];
}
void espacio_matriz_2(int **matriz_2,int columna_fila,int columna){//separa espacio para una matriz 2
	for (int i=0;i<columna_fila;i++) matriz_2[i] = new int [columna];
}
void espacio_matriz_3(int **matriz_3,int fila,int columna){//separa espacio para una matriz 3 que es la resultante
	for (int i=0;i<fila;i++) matriz_3[i] = new int [columna];
}
 
void crear_matriz_1(int **matriz_1,int fila,int columna_fila){//ingresa los datos para la matriz 1
	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna_fila; j++) cin >> *(*(matriz_1+i)+j);
	}
}
void crear_matriz_2(int **matriz_2,int columna_fila,int columna){//ingresa los datos para la matriz 2
	for (int i = 0; i < columna_fila; i++){
		for (int j = 0; j < columna; j++) cin >> *(*(matriz_2+i)+j);
	}
}

void imprimir_matriz_1(int **matriz_1,int fila,int columna_fila){//imprime la primera matriz
	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna_fila; j++){
		cout << *(*(matriz_1+i)+j) << " ";
		}cout << endl;
	}
}
void imprimir_matriz_2(int **matriz_2,int columna_fila,int columna){//imprime la segunda matriz
	for (int i = 0; i < columna_fila; i++){
		for (int j = 0; j < columna; j++){
		cout << *(*(matriz_2+i)+j) << " ";
		}cout << endl;
	}
}
void imprimir_matriz_3(int **matriz_3,int fila,int columna){//imprime la matriz resultante
	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna; j++){
		cout << *(*(matriz_3+i)+j) << " ";
		}cout << endl;
	}
}

void multiplicar_matrices(int **matriz_1,int **matriz_2,int **matriz_3,int fila,int columna_fila,int columna){//multiplica las 2 matrices (1y2) y lo almacena en la matriz resultante (3)
	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna; j++){
			matriz_3[i][j]=0;
			for (int x = 0; x < columna_fila; x++) //para multiplicar la fila por la columna
			*(*(matriz_3+i)+j)+= *(*(matriz_1+i)+x) * *(*(matriz_2+x)+j);//fila de matriz 1 con columna de matriz 2. el resultado se suma a la matriz 3
	}	}
}

void liberar_memoria_1(int **matriz_1,int fila,int columna_fila){//se libera el espacio reservado para la matriz 1
	for (int i = 0; i < fila; i++) delete[] matriz_1[i];
	delete[] matriz_1;
}
void liberar_memoria_2(int **matriz_2,int columna_fila,int columna){//se libera el espacio reservado para la matriz 1
	for (int i = 0; i < columna_fila; i++) delete[] matriz_2[i];
	delete[] matriz_2;	
}
void liberar_memoria_3(int **matriz_3,int fila,int columna){//se libera el espacio reservado para la matriz 1
	for (int i = 0; i < fila; i++) delete[] matriz_3[i];
	delete[] matriz_3;	
}
	
int main(){
	cout << "Ingrese el numero de filas de la 1ra matriz \n"; cin >> fila;
	cout << "\nIngrese el numero de columnas de la 1ra matriz (filas de la 2da matriz): \n"; cin >> columna_fila;
	cout << "\nIngrese el numero de columnas de la 2da matriz: \n"; cin >> columna;
	matriz_1 = new int *[fila];
	matriz_2 = new int *[columna_fila];
	matriz_3 = new int *[fila];
	espacio_matriz_1(matriz_1,fila,columna_fila);
	espacio_matriz_2(matriz_2,columna_fila,columna);
	espacio_matriz_3(matriz_3,fila,columna);
	cout << "Ingrese los datos de la primera matriz\n";
	crear_matriz_1(matriz_1,fila,columna_fila);
	cout << "Ingrese los datos de la segunda matriz\n";
	crear_matriz_2(matriz_2,columna_fila,columna);
	cout << "La primera matriz es: \n";
	imprimir_matriz_1(matriz_1,fila,columna_fila);
	cout << "La segunda matriz es: \n";
	imprimir_matriz_2(matriz_2,columna_fila,columna);
	cout << "La matriz resultante es: \n";
	multiplicar_matrices(matriz_1,matriz_2,matriz_3,fila,columna_fila,columna);
	imprimir_matriz_3(matriz_3,fila,columna);
	liberar_memoria_1(matriz_1,fila,columna_fila);
	liberar_memoria_2(matriz_2,columna_fila,columna);
	liberar_memoria_3(matriz_3,fila,columna);
	system ("pause");
	return 0;
}
