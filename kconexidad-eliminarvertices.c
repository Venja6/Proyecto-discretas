#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Función para eliminar vértices de la matriz de adyacencia
int** eliminar_vertices(int num_vertices, int matriz_adyacencia[num_vertices][num_vertices], int* vertices_a_eliminar, int cant_vertices_a_eliminar) {
    int num_vertices_copia = num_vertices - cant_vertices_a_eliminar;

    // Crear una nueva matriz dinámica para la copia sin los vertices dados
    int** copia_matriz_adyacencia = (int**)malloc(num_vertices_copia * sizeof(int*));
    for (int i = 0; i < num_vertices_copia; i++) {
        copia_matriz_adyacencia[i] = (int*)malloc(num_vertices_copia * sizeof(int));
    }

    int m = 0, n = 0;
    bool eliminar_fila, eliminar_columna;

    // Eliminar las filas y columnas correspondientes a los vértices a eliminar
    for (int i = 0; i < num_vertices; i++) {
        eliminar_fila = false;
        for (int v = 0; v < cant_vertices_a_eliminar; v++) {
            if (i == vertices_a_eliminar[v] - 1) {
                eliminar_fila = true;
                break;
            }
        }
        if (eliminar_fila) continue;

        n = 0;
        for (int j = 0; j < num_vertices; j++) {
            eliminar_columna = false;
            for (int v = 0; v < cant_vertices_a_eliminar; v++) {
                if (j == vertices_a_eliminar[v] - 1) {
                    eliminar_columna = true;
                    break;
                }
            }
            if (eliminar_columna) continue;

            // Copiar el valor de la matriz original a la nueva matriz
            copia_matriz_adyacencia[m][n] = matriz_adyacencia[i][j];
            n++;
        }
        m++;
    }

    return copia_matriz_adyacencia;
}

// Función para imprimir la matriz de adyacencia
void imprimir_matriz(int** matriz, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para verificar la conexidad
bool conexidad(int num_vertices, int** matriz_adyacencia) {
    //code
    return true;
}

// Función para la k-conexidad
int k_conexidad(int num_vertices, int matriz_adyacencia[num_vertices][num_vertices]) {
    int vertices_a_eliminar[4] = {0, 0, 0, 0};
    int num_vertices_copia = num_vertices;

    // Cambia el valor de k = {1, 2, 3, 4}
    for (int k = 1; k <= 4 && k < num_vertices; k++) {
        // Eliminar vértices hasta que se rompa la conexidad
        for (int i = 0; i <= num_vertices - k; i++) {
            vertices_a_eliminar[0] = i + 1;
            if (k == 1) {
                int cant_vertices_a_eliminar = 1;
                printf("Eliminando vertices: %d\n", vertices_a_eliminar[0]);
                int** copia_matriz = eliminar_vertices(num_vertices,matriz_adyacencia, vertices_a_eliminar, cant_vertices_a_eliminar);
                num_vertices_copia = num_vertices - cant_vertices_a_eliminar;
                
                // Imprimir la matriz resultante
                printf("Matriz de adyacencia resultante despues de eliminacion:\n");
                imprimir_matriz(copia_matriz, num_vertices_copia);
                
                if (!conexidad(num_vertices_copia, copia_matriz)) {
                    for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                    free(copia_matriz);
                    return k;
                }
                for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                free(copia_matriz);
            }
            for (int j = i + 1; j <= num_vertices - k + 1; j++) {
                vertices_a_eliminar[1] = j + 1;
                if (k == 2) {
                    int cant_vertices_a_eliminar = 2;
                    printf("Eliminando vertices: %d %d\n", vertices_a_eliminar[0], vertices_a_eliminar[1]);
                    int** copia_matriz = eliminar_vertices(num_vertices,matriz_adyacencia, vertices_a_eliminar, cant_vertices_a_eliminar);
                    num_vertices_copia = num_vertices - cant_vertices_a_eliminar;
                    
                    // Imprimir la matriz resultante
                    printf("Matriz de adyacencia resultante despues de eliminacion:\n");
                    imprimir_matriz(copia_matriz, num_vertices_copia);
                    
                    if (!conexidad(num_vertices_copia, copia_matriz)) {
                        for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                        free(copia_matriz);
                        return k;
                    }
                    for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                    free(copia_matriz);
                }
                for (int m = j + 1; m <= num_vertices - k + 2; m++) {
                    vertices_a_eliminar[2] = m + 1;
                    if (k == 3) {
                        int cant_vertices_a_eliminar = 3;
                        printf("Eliminando vertices: %d %d %d\n", vertices_a_eliminar[0], vertices_a_eliminar[1], vertices_a_eliminar[2]);
                        int** copia_matriz = eliminar_vertices(num_vertices, matriz_adyacencia, vertices_a_eliminar, cant_vertices_a_eliminar);
                        num_vertices_copia = num_vertices - cant_vertices_a_eliminar;
                        
                        // Imprimir la matriz resultante
                        printf("Matriz de adyacencia resultante despues de eliminacion:\n");
                        imprimir_matriz(copia_matriz, num_vertices_copia);
                        
                        if (!conexidad(num_vertices_copia, copia_matriz)) {
                            for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                            free(copia_matriz);
                            return k;
                        }
                        for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                        free(copia_matriz);
                    }
                    for (int l = m + 1; l <= num_vertices - k + 3; l++) {
                        vertices_a_eliminar[3] = l + 1;
                        if (k == 4) {
                            int cant_vertices_a_eliminar = 4;
                            printf("Eliminando vertices: %d %d %d %d\n", vertices_a_eliminar[0], vertices_a_eliminar[1], vertices_a_eliminar[2], vertices_a_eliminar[3]);
                            int** copia_matriz = eliminar_vertices(num_vertices,matriz_adyacencia, vertices_a_eliminar, cant_vertices_a_eliminar);
                            num_vertices_copia = num_vertices - cant_vertices_a_eliminar;
                            
                            // Imprimir la matriz resultante
                            printf("Matriz de adyacencia resultante despues de eliminacion:\n");
                            imprimir_matriz(copia_matriz, num_vertices_copia);
                            
                            if (!conexidad(num_vertices_copia, copia_matriz)) {
                                for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                                free(copia_matriz);
                                return k;
                            }
                            for (int i = 0; i < num_vertices_copia; i++) free(copia_matriz[i]);
                            free(copia_matriz);
                        }
                    }
                }
            }
        }
    }

    return 5; // Si no se rompió la conectividad para k = 1, 2, 3, 4, el grafo es 5-conexo (k-1 eeliminaciones de vertices = 4)
}


int main() {
    int num_vertices = 5;

    // Rellenar la matriz de adyacencia
    int matriz_adyacencia[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int k = k_conexidad(num_vertices, matriz_adyacencia);
    printf("El grafo es %d-conexo\n", k);

    return 0;
}
