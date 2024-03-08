#include <iostream>
using namespace std;
int main(){
    // Arreglo dinamico
    int* arr;
    arr = new int[2]; // Dimensionamiento (reserva de espacios de memoria) [para el arreglo dinamico]
    // Matriz dinamica
    int** matriz;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    matriz = new int*[2]; // Por filas
    for(int i=0; i<2; i++){ // Por fila dimensiono las columnas
        matriz[i] = new int[3];
    }
    matriz[0][0] = 1;
    matriz[0][1] = 3;
    matriz[0][2] = 1;
    matriz[1][0] = 2;
    matriz[1][1] = 4;
    matriz[1][2] = 6;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    // Por cada fila libero las columnas
    for(int i=0; i<2; i++){
        delete [] matriz[i]; // Libero columnas
    }
    // Libero las filas de la matriz dinamica
    delete [] matriz; // Libero las filas
    return 0;
}