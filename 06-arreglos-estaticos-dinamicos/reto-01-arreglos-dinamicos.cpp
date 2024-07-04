#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;

void recibir_tamaño_de_matriz(int &n) {
    do {
        cout << "Ingresar tamaño de matriz n: "; 
        cin >> n;
        if(!(n > 0 && n < MAX)) {
            cout << "n debe ser positivo" << endl;
        }
    } while (!(n > 0 && n < MAX));   
}

int** generar_Matriz_A(int n) {
    int** Matriz_A;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    Matriz_A = new int*[n]; // Por filas
    for(int i=0; i<n; i++){ // Por fila dimensiono las columnas
        Matriz_A[i] = new int[n];
    }
    int min = 0, max = 10; // "limites"
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Matriz_A[i][j] = rand() % (max - min + 1) + min;
        }   
    }
    cout << "Matriz A" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matriz_A[i][j] << "\t";
        }  
        cout << endl;
    }
    return Matriz_A;
}

int** generar_Matriz_B(int n) {
    int** Matriz_B;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    Matriz_B = new int*[n]; // Por filas
    for(int i=0; i<n; i++){ // Por fila dimensiono las columnas
        Matriz_B[i] = new int[n];
    }
    int min = 0, max = 10; // "limites"
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Matriz_B[i][j] = rand() % (max - min + 1) + min;
        }   
    }
    cout << "Matriz B" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matriz_B[i][j] << "\t";
        }  
        cout << endl;
    }
    return Matriz_B;
}

void Suma_de_Matrices(int** Matriz_A, int** Matriz_B, int n) {
    int** Matriz_C;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    Matriz_C = new int*[n]; // Por filas
    for(int i=0; i<n; i++){ // Por fila dimensiono las columnas
        Matriz_C[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {   
        for(int j = 0; j < n; j++) {
            Matriz_C[i][j] = Matriz_A[i][j]  + Matriz_B[i][j];
        }
    }
    cout << "A+B = " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matriz_C[i][j] << "\t";
        }  
        cout << endl;
    }
}

void Resta_de_Matrices(int** Matriz_A, int** Matriz_B, int n) {
    int** Matriz_E;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    Matriz_E = new int*[n]; // Por filas
    for(int i=0; i<n; i++){ // Por fila dimensiono las columnas
        Matriz_E[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {   
        for(int j = 0; j < n; j++) {
            Matriz_E[i][j] = Matriz_A[i][j]  - Matriz_B[i][j];
        }
    }
    cout << "A-B = " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matriz_E[i][j] << "\t";
        }  
        cout << endl;
    }
}
void Producto_de_Matrices(int** Matriz_A, int** Matriz_B, int n) {
    int** Matriz_D;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    Matriz_D = new int*[n]; // Por filas
    for(int i=0; i<n; i++){ // Por fila dimensiono las columnas
        Matriz_D[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {   
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++){}
            Matriz_D[i][j] = Matriz_A[i][j]  + Matriz_B[i][j];
        }
    }
    cout << "A*B = " << endl;
    for (int i = 0; i < n; i++) {   
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++){}
            Matriz_D[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++){
                Matriz_D[i][j] += Matriz_A[i][k]*Matriz_B[k][j];
            }
        }  
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matriz_D[i][j] << "\t";
        }  
        cout << endl;
    }
}
int main() {
    srand(time(NULL)); // Reiniciar la semilla aleatoria
    int n;
    int** Matriz_A;
    int** Matriz_B;
    recibir_tamaño_de_matriz(n);
    Matriz_A = generar_Matriz_A(n);
    Matriz_B = generar_Matriz_B(n);
    Suma_de_Matrices(Matriz_A, Matriz_B, n); // Se pasan los cuatro parámetros requeridos.
    Resta_de_Matrices(Matriz_A, Matriz_B, n );
    Producto_de_Matrices(Matriz_A, Matriz_B , n );

    for(int i = 0; i < n; i++){
        delete [] Matriz_A[i];
        delete [] Matriz_B[i]; 
    }

    delete [] Matriz_A;
    delete [] Matriz_B;
    return 0;
}
