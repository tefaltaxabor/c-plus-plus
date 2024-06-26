#include <iostream>
using namespace std;

double dividirDoubles(double numerador, double denominador){
    double cociente = numerador/denominador;
    return cociente;
}

int dividirEnteros(int numerador, int denominador){
    int cociente = numerador/denominador;
    return cociente;
}

template <typename T>
T dividir(T numerador, T denominador){
    T cociente = numerador/denominador;
    return cociente;
}

template <class T>
T getMax(T a, T b){
    if(b > a){
        return b;
    }  
    else{
        return a;
    }
    
}

int main(){
    cout << dividirEnteros(3, 2) << endl;
    cout << dividirDoubles(3 ,2) << endl;
    cout << dividir<int>(3, 2) << endl;
    cout << dividir<double>(3, 2) << endl;
    cout << getMax<int>(9,2) << endl;
    return 0;
}