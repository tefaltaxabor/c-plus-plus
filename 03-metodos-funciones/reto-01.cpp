#include<iostream>
using namespace std;
void pedir_n(int &n) /*Paso de parametro por referencia ; significa que en lugar de pasar una copia 
del valor de la variable, se pasa una referencia a la ubicación de memoria donde se almacena 
la variable original. Esto permite que la función modifique directamente el valor de la variable original.*/
{
do {
        cout << "Ingrese un numero positivo: ";
        cin >> n;
        if (!(n > 3 && n%2!=0)) {
            cout << "Ingrese un numero positivo mayor que 3 e impar" << endl;
        }
    } while (!(n > 0 && n%2!=0));
}

void escribir_n(int n) // Paso de parametro por valor

{
    for (int i = 1; i <= n; i++) {
        cout << i;
    }
    cout << endl;
    for ( int )

}

int main(  ) 
{   
    int n;
    pedir_n(n);
    escribir_n(n);
    return 0;
}

