#include <iostream>
using namespace std;

int main ()
{
    int n;
    do
    {
        cout << "Ingrese numero ";
        cin >> n;
        if (!(n > 0 && n%2 !=0))
        {
            cout << "El numero debe ser positivo e impar" << endl;
        }
    }
    while (!(n > 0 && n%2 !=0));
    {

        for (int f = 1 ; f <= n - 1  ; f++)
        {
            for (int c = 1 ; c <= 2*f - 1 ; c++)
    
            {
                cout << "*";
            }
            cout<<endl;   
        }
    
    }
    return 0; 
}