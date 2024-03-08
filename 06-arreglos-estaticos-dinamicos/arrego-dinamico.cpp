/*
Se desea almacenar en arreglo dinamico los nombres de estudiantes de un curso
*/
#include <iostream>
using namespace std;
int main(){
    string arreglo_estatico[] = {"Jorge", "Luis", "Ana"};
    string* arreglo_dinamico; // Declaracion de puntero
    arreglo_dinamico = new string[3]; // Definicion del tamaño del arreglo dinamico (reserva de espacios de memoria)
    arreglo_dinamico[0] = "Jorge";
    arreglo_dinamico[1] = "Ana";
    arreglo_dinamico[2] = "Luis";
    for(int i=0; i<3; i++){
        cout << "Estudiante #" << i+1 << ": " << arreglo_dinamico[i] << endl;
    }
    delete [] arreglo_dinamico; // Liberas los espacios de memoria reservados
    arreglo_dinamico = NULL; // Vacias los valores
    return 0;
}
