#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    // Arreglos en 1d
    int arr1[5];
    for(int i=0; i<5; i++){
        arr1[i] = i*i;
    }
    for(int i=0; i<5; i++){
        cout << arr1[i] << "\t";
    }
    cout << endl;
    // Arreglos 2d
    cout << "Matriz de float" << endl;
    srand(time(NULL)); // Reiniciar la semilla aleatoria
    float arr2[4][3];
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            arr2[i][j] = rand();
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            cout << arr2[i][j] << "\t";
        }  
        cout << endl;
    }
    // Arreglos 2d enteros
    cout << "Matriz de enteros entre 0 y 20" << endl;
    srand(time(NULL)); // Reiniciar la semilla aleatoria
    int arr3[4][3];// Matriz 4 x 4 
    int min = 0, max = 20; // "limites"
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            arr2[i][j] = rand()%(max-min+1) + min;
        }   
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            cout << arr2[i][j] << "\t";
        }  
        cout << endl;
    }
    return 0;
}