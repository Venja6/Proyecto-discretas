#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000

int** LeerMatriz(const char* filename, int* size) {
    FILE *G = fopen(filename, "r");
    if (G == NULL) {
        perror("Error opening file");
        return NULL;
    }
    char buff[MAX];
    char *token;
    int vertice = 0;
    int arista = 0;

    if (fgets(buff, MAX, G)) {
        *size = atoi(buff); 
    } else {
        fclose(G);
        return NULL;
    }

    int **matriz = (int**)malloc(*size * sizeof(int*));
    for (int i = 0; i < *size; i++) {
        matriz[i] = (int*)calloc(*size, sizeof(int));
    }

    while (fgets(buff, MAX, G)) {
        token = strtok(buff, ":");
        vertice = atoi(token);
        token = strtok(NULL, ":");
        token = strtok(token, ",");
        while (token != NULL) {
            arista = atoi(token);
            matriz[vertice - 1][arista - 1] = 1;
            token = strtok(NULL, ",");
        }
    }
    fclose(G);
    return matriz;
}

int **crearMatrizCuadrada(int n) {
    int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }
    return matrix;
}

int **copiarMatrizCuadrada(int **original, int n) {
    int **matrix = crearMatrizCuadrada(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = original[i][j];
        }
    }
    return matrix;
}

int **crearMatrizValidacion(int **original, int n) {
    int **matrix = copiarMatrizCuadrada(original, n);
    int i = 0, j = 0;
    while(i < n && j < n){
        matrix[i][j] = 1;
        i++;
        j++;
    } 
    return matrix;
}

int **multiplicarMatriz(int **original, int **actual, int n) {
    int **resultado = crearMatrizCuadrada(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				resultado[i][j] += actual[i][k] * original[k][j];
			}
		}
	}
	return resultado;
}

void mostrarMatriz(int **matriz, int size) {
    int aux = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            aux = matriz[i][j];
            printf("%2d", aux);
        }
        printf("\n");
    }
}


int **remover_1(int **matriz, int size, int A) {
    int **matriz_menos_1 = crearMatrizCuadrada(size-1);
    int fila = 0;
    for (int i = 0; i < size; i++) {
        if (i == A) continue;
        int columna = 0;
        for (int j = 0; j < size; j++) {
            if (j == A) continue;
            matriz_menos_1[fila][columna] = matriz[i][j];
            columna++;
        }
        fila++;
    }
    return matriz_menos_1;
}

int **remover_2(int **matriz, int size, int A, int B) {
    int **matriz_menos_2 = crearMatrizCuadrada(size-2);
    int fila = 0;
    for (int i = 0; i < size; i++) {
        if (i == A || i == B) continue;
        int columna = 0;
        for (int j = 0; j < size; j++) {
            if (j == A || j == B) continue;
            matriz_menos_2[fila][columna] = matriz[i][j];
            columna++;
        }
        fila++;
    }
    return matriz_menos_2;
}

int **remover_3(int **matriz, int size, int A, int B, int C) {
    int **matriz_menos_3 = crearMatrizCuadrada(size-3);
    int fila = 0;
    for (int i = 0; i < size; i++) {
        if (i == A || i == B || i == C) continue;
        int columna = 0;
        for (int j = 0; j < size; j++) {
            if (j == A || j == B || j == C) continue;
            matriz_menos_3[fila][columna] = matriz[i][j];
            columna++;
        }
        fila++;
    }
    return matriz_menos_3;
}

int **remover_4(int **matriz, int size, int A, int B, int C, int D) {
    int **matriz_menos_4 = crearMatrizCuadrada(size-4);
    int fila = 0;
    for (int i = 0; i < size; i++) {
        if (i == A || i == B || i == C || i == D) continue;
        int columna = 0;
        for (int j = 0; j < size; j++) {
            if (j == A || j == B || j == C || j == D) continue;
            matriz_menos_4[fila][columna] = matriz[i][j];
            columna++;
        }
        fila++;
    }
    return matriz_menos_4;
}

bool conexidad(int **original, int n) {
    int **validacion = crearMatrizValidacion(original, n);
    int **actual = copiarMatrizCuadrada(original, n);

    for(int i = 0; i < n-1; i++) {
        actual = multiplicarMatriz(original, actual, n);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(actual[j][k] != 0) {
                    validacion[j][k] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(validacion[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

int gradoMaximo(int **matriz, int size) {
    int max = 0;
    int suma = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            suma = matriz[i][j]+ suma;
        }
        if(suma >= max){
            max = suma;
        }
        suma = 0;
    }
    return max;
}

int gradoMinimo(int **matriz, int size) {
    int min = 9999999;
    int suma = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            suma = matriz[i][j]+ suma;
        }
        if(suma <= min){
            min = suma;
        }
        suma = 0;
    }
    return min;
}


int main(int argc, char const *argv[]) {
	int size = 0;
	int aux = 0;
    int k = -1;
    int eleccion1 = 0;
    int eleccion2 = 0;
    int eleccion3 = 2;

    while(eleccion1 != 1 && eleccion1 != 2 && eleccion1 != 3 && eleccion1 != 4 && eleccion1 != 5 && eleccion1 != 6 && eleccion1 != 7) {
        printf("Entre las siguientes opciones, elija el ejemplo que quiera probar ingresando un número\n");
        printf("estos ejemplos los puede ver en la carpeta y sus descripciones en el informe.\n");
        printf("1 = Grafo que quiera dar, debe editar o crear el archivo: 'grafo.txt' con los datos deseados.\n");
        printf("2 = Grafo size 5\n");
        printf("3 = Grafo size 10\n");
        printf("4 = Grafo size 15\n");
        printf("5 = Grafo size 20\n");
        printf("6 = Caso especial donde queda un solo vertice despues de eliminar.\n");
        printf("7 = Caso donde sea disconexo desde el inicio.\n");
        scanf("%d", &eleccion1);
        printf("\n");
    }

    //Se hace la lectura de la matriz
    int **matriz;
    if(eleccion1 == 2 ) {
        matriz = LeerMatriz("size5.txt", &size);
    }else if(eleccion1 == 3 ) {
        matriz = LeerMatriz("size10.txt", &size);
    }else if(eleccion1 == 4 ) {
        matriz = LeerMatriz("size15.txt", &size);
    }else if(eleccion1 == 5 ) {
        matriz = LeerMatriz("size20.txt", &size);
    }else if(eleccion1 == 6) {
        matriz = LeerMatriz("casoExtremo.txt", &size);
    }else if(eleccion1 == 7) {
        matriz = LeerMatriz("disconexo.txt", &size);
    }else if(eleccion1 == 1) {
        matriz = LeerMatriz("grafo.txt", &size);
    }


    while(eleccion2 != 1 && eleccion2 != 2 && eleccion2 != 3) {
        printf("1 = Continuar al calculo de k\n");
        printf("2 = Mostrar grado maximo y minimo del grafo original\n");
        printf("3 = Opciones de display\n");
        scanf("%d", &eleccion2);
        printf("\n");

        if(size != 0 && eleccion2 == 2){
            int gradoMax = gradoMaximo(matriz, size);
            int gradoMin = gradoMinimo(matriz, size);
            printf("Grado maximo = %d\n", gradoMax);
            printf("Grado minimo = %d\n", gradoMin);
            eleccion2 = 0;
            printf("\n");
        }

        if(eleccion2 == 3) {
            printf("Puede elegir si quiere ver o no cada cambio de estado al eliminar vertices, \n");
            printf("Junto con los vertices eliminados al reducir la matriz.\n");
            printf("(Sera complicado de leer por la gran cantidad de operaciones en grafos mas grandes)\n");
            printf("1 = Ver eliminacion\n");
            printf("2 = No ver eliminacion (Predeterminado)\n");
            scanf("%d", &eleccion3);
            eleccion2 = 0;
            printf("\n");
        } 
    }

    if(size != 0) {
    printf("\nMatriz de adyacencia original: \n");
    }
    //Se completa la lectura de la matriz inicial y revisa la conexidad inicial
    mostrarMatriz(matriz, size);
    bool verdad_conexidad_inicial = conexidad(matriz, size);
    if(!verdad_conexidad_inicial) {
        k = 0;
    }
    if(k == 0){
        printf("El grafo es disconexo desde el inicio.\n");
    }

    if(size == 0){
        printf("No se entregaron los datos de forma correcta en el archivo leido\n");
    }
    //Si no es conexa k = 0, si es conexa se continua a k

    //Se inicia eliminando un vertice, la matriz sera 1 dimensión menor
    if(k == -1 && size > 1){
    int n = size-1;
        for(int i = 0; i < size; i++) {
            int **matriz_menos_1 = remover_1(matriz, size, i);
            bool verdad_menos_1 = conexidad(matriz_menos_1, n);
            if(eleccion3 == 1) {
                printf("\n");
                printf("se borra el vertice %d\n", i+1);
                mostrarMatriz(matriz_menos_1, n);
            }
            if(!verdad_menos_1) {
                k = 1;
                break;
            }
        }

        if(k == 1){
            printf("Es disconexo eliminando 1 vertice, k-conexidad o conectividad = %d\n", k);
        }
    }

    if(k == -1 && size > 2) {
        int n = size - 2;
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                int **matriz_menos_2 = remover_2(matriz, size, i, j);
                bool verdad_menos_2 = conexidad(matriz_menos_2, n);
                if(eleccion3 == 1){
                    printf("\n");
                    printf("se borran los vertices %d, %d\n", i+1, j+1);
                    mostrarMatriz(matriz_menos_2, n);
                }
                if(!verdad_menos_2) {
                    k = 2;
                    break;
                }
            }
            if(k == 2) {
            break;
            }
        }

        if(k == 2){
            printf("Es disconexo eliminando 2 vertices, k-conexidad o conectividad = %d\n", k);
        }
    }

    if(k == -1 && size > 3) {
        int n = size - 3;
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                for(int l = j + 1; l < size; l++) {
                    int **matriz_menos_3 = remover_3(matriz, size, i, j, l);
                    bool verdad_menos_3 = conexidad(matriz_menos_3, n);
                    if(eleccion3 == 1) {
                        printf("\n");
                        printf("se borran los vertices %d, %d, %d\n", i+1, j+1, l+1);
                        mostrarMatriz(matriz_menos_3, n);
                    }
                    if(!verdad_menos_3) {
                        k = 3;
                        break;
                    }
                }
                if(k == 3) {
                    break;
                }
            }
            if(k == 3) {
                break;
            }
        }
    }

    if(k == 3) {
        printf("Es disconexo eliminando 3 vertices, k-conexidad o conectividad = %d\n", k);
    }

    bool verdad_menos_4 = false;
    if(k == -1 && size > 4) {
        int n = size - 4;
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                for(int l = j + 1; l < size; l++) {
                    for(int p = l + 1; p < size; p++) {
                        int **matriz_menos_4 = remover_4(matriz, size, i, j, l, p);
                        bool verdad_menos_4 = conexidad(matriz_menos_4, n);
                        if(eleccion3 == 1) {
                            printf("\n");
                            printf("se borran los vertices %d, %d, %d, %d\n", i+1, j+1, l+1, p+1);
                            mostrarMatriz(matriz_menos_4, n);
                        }
                        if(!verdad_menos_4) {
                            k = 4;
                            break;
                        }
                    }
                    if(k == 4) {
                        break;
                    }
                }
                if(k == 4) {
                    break;
                }
            }
            if(k == 4) {
                break;
            }
        }
    }

    if(k == 4) {
        printf("Es disconexo eliminando 4 vertices, k-conexidad o conectividad = %d\n", k);
    }

    /*if(size == 5 && k == -1) {
        printf("El grafo queda con un solo vertice, tiene conectividad 4\n");
    }else if(size == 4 && k == -1) {
        printf("El grafo tiene conectividad 3\n");
    }else if(size == 3 && k == -1) {
        printf("El grafo tiene conectividad 2\n");
    }else if(size == 2 && k == -1) {
        printf("el grafo tiene conectividad 1\n");
    }else if(size == 1 && k == -1) {
        printf("el grafo es un unico vertice\n");
    }*/

    if(size <= 5 && size > 0 && k == -1) {
        printf("El grafo tiene una conectividad %d, aumentar k eliminaria el unico vertice restante\n", size-1);
    }

    if(k == -1 && size > 5) {
        printf("El grafo dado sigue siendo conexo para valores de k = 4, por lo que su conectividad es aún mayor.\n");
    }
    return 0;
}