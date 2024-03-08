#include<iostream>

using namespace std;

void verificacion_de_datos(int &a , int &b)
{
    do
    {

    cout << "Ingresar a = "; cin >> a;
    cout << "Ingresar b = "; cin >> b;
    if (!(a > 0 || b > 0)) 
    {
        cout<< "Solo numero enteros " <<endl;
    }
    }
    while (!(a > 0 && b > 0));
}
int suma (int &a , int &b);
int resta (int (*ptr_a) , int (*ptr_b));
int multiplicacion(int (*ptr_a) , int (*ptr_b));
int division(int (*ptr_a) , int (*ptr_b));

int suma (int &a , int &b)
{
    int* ptr_a = &a;
    int* ptr_b = &b;
    int s = (*ptr_a) + (*ptr_b);
    return s;
}
int resta (int &a , int &b)
{
    int (*ptr_a) = &a;
    int (*ptr_b) = &b;
    return (*ptr_a) - (*ptr_b);
}
int multiplicacion(int &a , int &b)
{
    int (*ptr_a) = &a;
    int (*ptr_b) = &b;
    int m = (*ptr_a) * (*ptr_b);
    return m;
}
int division(int &a , int &b)
{
    int (*ptr_a) = &a;
    int (*ptr_b) = &b;
    int d = (*ptr_a) / (*ptr_b);
    return d;
}
int main()
{   
    
    int a, b;
    char c;
    
    verificacion_de_datos(a, b);
    
    cout<< "Calculadora" <<endl;
    cout<< "a) Suma " << endl;
    cout<< "b) Resta" <<endl;
    cout<< "c) Multiplicacion" << endl;
    cout<< "d) Division"<< endl;
    cout<< "e) Cerrar"<< endl;
    cout << "Elija una opcion:"; cin >> c; 
       
    
            switch (c)
            {
            case 'a':
                cout << "Suma = " << suma(a , b)<<endl;
                break;
            case 'b':
                cout << "Resta = " << resta(a,b)<<endl;
                break;
            case 'c':
                cout << "Mulplicacion  = " << multiplicacion(a ,b)<<endl;
                break;
            case 'd':
                cout << "Division = " << division(a ,b )<<endl;
                break;
            case 'e':
                return 0;
            default:
                cout<< "Opcion invalida "<< endl;
                break;
            }

    

   return 0; 
}