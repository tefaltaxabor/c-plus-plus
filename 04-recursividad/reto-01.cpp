#include<iostream>
using namespace std;
void validacion_de_datos(int &a, int &b)
{
    do
    {
      
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        if(!( a > 0 && b > 0 ))
        {
            cout<< "Ingresar valores positivos y enteros " << endl;
        }
    } while (!( a > 0 && b > 0 ));
}

int multiplicacion_recursiva(int a, int b);

int multiplicacion_recursiva(int a, int b) 
{
    if (b == 1 )
    {
        return a;

    }
    else
    {
        return a + multiplicacion_recursiva(a, b-1);
    }
}
int main()
{  
    int a, b;
    validacion_de_datos(a, b);
    cout <<  "a x b : " <<  multiplicacion_recursiva(a,b) <<  endl;
    
    return 0;
    
}