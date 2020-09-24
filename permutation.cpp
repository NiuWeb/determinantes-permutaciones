#include <iostream>
#include <algorithm>
#include "./parity.cpp"
using namespace std;


class Determinant {
    private:  
    int *m; // matriz CUADRADA cuyo determinante calcular
    int s; // tamaño de la matriz (número de columnas/filas)
    int det = 0; // determinante actual de la matriz

    /**
     * Obtiene el elemento de la matrix en las coordenadas dadas.
     * @param x columna del elemento (de 0 a n-1)
     * @param y fila del elemento (de 0 a n-1)
     */
    int get(int x, int y) {
        return m[s*y + x%s];
    }
    /**
     * Se ejecuta cuando una nueva permutación sea encontrada
     * y calcula el producto correspondiente
     * @param a permutación actual
     * */
    void calc(int a[]) 
    { 
        int diag = 1; // valor inicial del producto
        for (int i = 0; i < s; i++) { 
            diag *= get(a[i], i); //  operar
        }
        // multiplicar por la pariedad de la permutación y sumar al determinante
        det += diag*parity(a, s);
    } 
    /**
     * Genera todas las permutaciones del vector dado
     * @param a vector a permutar, o permutación inicial.
     * */
    void permutations(int a[]) 
    {
        do { 
            // La nueva permutación se guarda en `a`y se
            // pasa como parámetro a calc()
            calc(a);
        } 
        // siguiente permutación
        while(next_permutation(a, a + s)); 
    }
    public:
    /**
     * Recibe una matriz nxn para calcular su determinante
     * @param _m matriz CUADRADA cuyo determinante calcular
     * @param _s tamaño (filas) de la matriz 
     * */
    int calculate(int _m[], int _s) {
        det = 0; // reiniciar determinante
        m = _m; // guardar matriz
        s = _s; // guardar tamaño de matriz

        int* a = new int[s]; // crear vector de permutación
        for(int i = 0; i < s; i++) {
            a[i] = i; // con los índices de 0 a n-1 ascendentemente
        }
        // permutar vector
        permutations(a);
        // devolver resultado una vez terminado el procedimiento
        return det;
    }
};