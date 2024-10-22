#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int X = 0;
	int matriz[4][4];
	int matriz_aux[4][4] = {	
		{0,1,1,0},
		{1,0,1,1},
		{1,1,0,1},
		{0,1,1,0}
	};

	for(int i = 0; i<4 ;i++) {
		for(int j = 0; j<4; j++) {
			matriz[i][j] = matriz_aux[i][j];
		}
	}


	for(int k = 1; k<=4; k++) {
		//eliminacion de vertice 
		for(int i = 0; i<4 ;i++) {
			for(int j = 0; j<4; j++) {
					

			}
		}
	}




	return 0;
}