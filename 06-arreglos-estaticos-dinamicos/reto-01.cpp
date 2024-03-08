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

void generar_Matriz_A(int n, int Matriz_A[][MAX]) {
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
}

void generar_Matriz_B(int n, int Matriz_B[][MAX]) {
    
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
}

void Suma_de_Matrices(int Matriz_A[][MAX], int Matriz_B[][MAX], int n, int Matriz_C[][MAX]) {
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

void Resta_de_Matrices(int Matriz_A[][MAX], int Matriz_B[][MAX], int n, int Matriz_E[][MAX]) {
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
void Producto_de_Matrices(int Matriz_A[][MAX], int Matriz_B[][MAX], int n, int Matriz_D[][MAX]) {
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
        cout << endl;
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
    int Matriz_A[MAX][MAX];
    int Matriz_B[MAX][MAX];
    int Matriz_C[MAX][MAX];
    int Matriz_D[MAX][MAX];
    int Matriz_E[MAX][MAX];
    recibir_tamaño_de_matriz(n);
    generar_Matriz_A(n, Matriz_A);
    generar_Matriz_B(n, Matriz_B);
    Suma_de_Matrices(Matriz_A, Matriz_B, n, Matriz_C); // Se pasan los cuatro parámetros requeridos.
    Resta_de_Matrices(Matriz_A, Matriz_B, n , Matriz_E);
    Producto_de_Matrices(Matriz_A, Matriz_B , n , Matriz_D);
    return 0;
}
