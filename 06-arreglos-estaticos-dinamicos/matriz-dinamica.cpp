#include <iostream>
using namespace std;
int main(){
    // Arreglo dinamico
    int* arr;
    arr = new int[2]; // Dimensionamiento (reserva de espacios de memoria) [para el arreglo dinamico]
    // Matriz dinamica
    int** matriz;
    // Dimensionamiento (reserva de espacios de memoria) de la matriz dinamica
    matriz = new int*[2]; // Por filas  m = 2
    for(int i=0; i<2; i++){ // Por fila dimensiono las columnas
        matriz[i] = new int[3];
    }
    
    //Result Matrix 2 x 3 

    matriz[0][0] = 1; // a_(11)
    matriz[0][1] = 3; // a_(12)
    matriz[0][2] = 1; // a_(13)
    matriz[1][0] = 2; // a_(21)
    matriz[1][1] = 4; // a_(22)
    matriz[1][2] = 6; // a_(23)
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