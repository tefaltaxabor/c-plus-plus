#include <iostream>
using namespace std;

void pedir_n(int &n){ // Paso de parametro por referencia
    do {
        cout << "Ingrese un numero positivo: ";
        cin >> n;
        if (!(n > 0)) {
            cout << "Ingrese un numero positivo." << endl;
        }
    } while (!(n > 0));
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
    pedir_n(n);
    generar_z(n);
    return 0;
}