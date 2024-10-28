#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int matriz_aux[4][4] = {	
		{0,1,1,0},
		{1,0,1,1},
		{1,1,0,1},
		{0,1,1,0}
	};
	
	int matriz[4][4];
	int contador = 0;
	int aux = 0;

	for(int i = 0; i<4 /*tamaño*/;i++) {
		for(int j = 0; j<4 /*tamaño*/;j++) {
			matriz[i][j] = matriz_aux[i][j];
		}
	}


	int resultado[4][4];
	for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = 0;
        }
    }

    // Potencia M^n  n = 2
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                resultado[i][j] += matriz[i][k] * matriz[k][j];
            }
        }
    }

    for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			aux = resultado[i][j];
			printf("%d", aux);
			contador++;	
			if(contador == 4) {
				printf("\n");
				contador = 0;
			}
		}	
	}

	return 0;
}
