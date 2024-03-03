#include <iostream>
using namespace std;
int main(){
    // Imprimir los 5 primeros numeros impares
    int cont = 0;
    int n = 1;
    while(cont < 5){
        cout << n << " ";
        n+=2;
        cont++;
    }
    cout << endl;

    // Pide un numero por consola e imprime el doble. Dicho numero debe ser positivo
    
    do{
        cout << "n: ";
        cin >> n;
        if(n <= 0){
            cout << "El numero debe ser positivo" << endl;
        }
    }while(n <= 0);
    cout << 2*n << endl;
    return 0;
}