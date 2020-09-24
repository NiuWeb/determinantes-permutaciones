/**
 * Obtiene la pariedad de un vector de enteros ascendentes
 * consecutivos.
 * @param row el vector cuya pariedad calcular
 * @param size el tamaño del vector
 * */
int parity(int row[], int size) {
    int p = 0; // número de inversiones

    // combinar (i,j) todos los pares de números posibles en el vector
    // de modo que i < j
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            // comprobar si hay una inversión
            if(row[i] > row[j]) {
                p++; // añadirla al contador
            }
        }
    }
    // si el número de inversiones es par, devolver 1;
    // caso contrario devolver -1.
    return (p%2 == 0) ? 1: -1;
};