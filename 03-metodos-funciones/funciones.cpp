#include <iostream>
using namespace std;

int pedir_n(){ // Funcion sin parametros
    int n;
    do {
        cout << "Ingrese un numero positivo: ";
        cin >> n;
        if (!(n > 0)) {
            cout << "Ingrese un numero positivo." << endl;
        }
    } while (!(n > 0));
    return n;
}

void generar_z(int n){ // Paso de parametro por valor
    for (int i = 1; i <= n; i++) {
        cout << "#";
    }
    cout << endl;
    for (int i = 2; i <n; i++) {
        for(int j = 1; j<= n-i; j++){
            cout << " ";
        }
        cout << "#" << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << "#";
    }
    cout << endl;
}

int main() {
    int n;
    n = pedir_n(); // Toda llamada a funcion debe almacenar el valor devuelto
    generar_z(n);
    return 0;
}