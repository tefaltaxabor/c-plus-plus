#include<iostream>

using namespace std;

void verificacion_de_datos(int (*ptr_a) , int (*ptr_b))
{
    do
    {

    cout << "Ingresar a = "; cin >> (*ptr_a);
    cout << "Ingresar b = "; cin >> (*ptr_a);
    if (!((*ptr_a) > 0 || (*ptr_a) > 0)) 
    {
        cout<< "Solo numero enteros " <<endl;
    }
    }
    while (!((*ptr_a) > 0 && (*ptr_b) > 0));
}
int suma (int (*ptr_a) , int (*ptr_b));
int suma (int (*ptr_a) , int (*ptr_b))
{
    return (*ptr_a) + (*ptr_b);
}
int resta (int (*ptr_a) , int (*ptr_b));
int resta (int (*ptr_a) , int (*ptr_b))
{
    return (*ptr_a) - (*ptr_b);
}
int multiplicacion(int (*ptr_a) , int (*ptr_b));
int multiplicacion(int (*ptr_a) , int (*ptr_b))
{
    return (*ptr_a) * (*ptr_b);
}
int division(int (*ptr_a) , int (*ptr_b));
int division(int (*ptr_a) , int (*ptr_b))

{
    return (*ptr_a) / (*ptr_b);
}
int main()
{   
    
    int a, b;
    char c;
    int* ptr_a;
    int* ptr_b;
    ptr_a = &a;
    ptr_b = &b;
    verificacion_de_datos(ptr_a, ptr_b);
    
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
                cout << "Suma = " << suma(ptr_a , ptr_b)<<endl;
                break;
            case 'b':
                cout << "Resta = " << resta(ptr_a , ptr_b)<<endl;
                break;
            case 'c':
                cout << "Mulplicacion  = " << multiplicacion(ptr_a , ptr_b)<<endl;
                break;
            case 'd':
                cout << "Division = " << division(ptr_a , ptr_b)<<endl;
                break;
            case 'e':
                return 0;
            default:
                cout<< "Opcion invalida "<< endl;
                break;
            }

    

   return 0; 
}