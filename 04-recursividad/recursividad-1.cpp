#include <iostream>
using namespace std;
int leer_n(){
    int n;
    do{
        cout << "n = ";
        cin >> n;
        if(!(n>=0)){
            cout << "El valor debe ser mayor o igual a cero" << endl;
        }
    }while(!(n>=0));
    return n;
}
int calcular_factorial(int n){
    if(n == 0 || n == 1){ // Caso base
        return 1;
    }else{ // n >= 2 -> Caso recursivo o caso general
        return n*calcular_factorial(n-1);
    }
}
void mostrar_resultado(int n){
    cout << "n! = " << calcular_factorial(n) << endl;
}
int main(){
    int n;
    n = leer_n();
    mostrar_resultado(n);
    return 0;
}