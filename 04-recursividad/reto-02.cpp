#include<iostream>
using namespace std;

void validacion_de_entrada_de_datos(int &n)
{
    do
    {
        cout << "Ingrese valor: "; 
        cin >> n;
        if (!(n >= 1))
        {
            cout << "El valor debe ser positivo y mayor que 1" << endl;
        }
    } while (!(n >= 1));
}

int Serie_de_Fibonnacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return Serie_de_Fibonnacci(n - 1) + Serie_de_Fibonnacci(n - 2); // Rekursiv Folge
    }
}

int main()
{
    int n;
    validacion_de_entrada_de_datos(n);
    cout << "El término " << n << " de la serie de Fibonacci es: " << Serie_de_Fibonnacci(n) << endl;
    return 0; 
}
