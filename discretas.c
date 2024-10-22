#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int main() {

	/*La lectura funcionara para archivos con el formato:
	cantidad de vertices
	Vertice:conexion a vertice () , conexion a vertice ()...
	Vertice:...
	...

	Ejemplo:
	3
	1:3,2
	2:1,3
	3:1,2

	*/

	FILE *G = fopen("grafo.txt", "r");
	char buff[MAX];
	char conex[500];
	char *token;
	int contador = 0;
	int size = 0;
	int vertice = 0;
	int arista = 0;
	int aux = 0;

	//leer primer dato (tamaño)
	if(fgets(buff, MAX, G)){
		size = atoi(buff);
	}

	//crear matriz asociada
	int matriz[size][size];

	//llenar de 0s para representar aristas no conectadas
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			matriz[i][j] = 0;
			}
		}

	//lectura del vertice
	while(fgets(buff, MAX, G)) {
			token = strtok(buff, ":");
			//vertice actual
			vertice = atoi(token);
			token = strtok(NULL, ":");
			//comenzar a leer las aristas
			token = strtok(token, ",");
			while(token != NULL) {
				arista = atoi(token);
				//guardar la arista, representada por un 1
				matriz[vertice-1][arista-1] = 1;
				//pasar al siguiente numero
				token = strtok(NULL, ",");
			}
		}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			aux = matriz[i][j];
			printf("%d", aux);
			contador++;	
			if(contador == size) {
				printf("\n");
				contador = 0;
			}
		}	
	}
	fclose(G);
	return 0;
}