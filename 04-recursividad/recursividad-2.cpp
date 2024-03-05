#include <iostream>
using namespace std;

// Declaracion de prototipos de funciones
int sumar_recursivamente(int a, int b);

// Definicion/implementacion de funciones
int sumar_recursivamente(int a, int b){
    if(b == 0){
        return a;
    }else{
        return sumar_recursivamente(a, b-1)+1;
    }
}

int main(){
    int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "a + b = " << sumar_recursivamente(a,b) << endl;
    return 0;
}