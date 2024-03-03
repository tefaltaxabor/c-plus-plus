/*
Dado un numero ingresdo por el usuario. Que debe ser impar y positivo
Imprimir la siguiente figura
n = 3
 *
***
n = 5 
  *
 ***
*****
*/

#include <iostream>
using namespace std;
int main(){
    int n;
    // Ingreso de datos con validacion
    do{
        cout << "n: ";
        cin >> n;
        if(!(n%2 != 0 && n > 0)){
            cout << "El valor debe ser impar y positivo" << endl;
        }
    }while(!(n%2 != 0 && n > 0));
    // Impresion de figura
    for(int f = 1; f <= (n+1)/2; f++){
        for(int c = 1; c <= n/2-f+1; c++){
            cout << " ";
        }
        for(int c = 1; c <= 2*f-1; c++){
            cout << "#";
        }
        cout << endl;
    }
    
}