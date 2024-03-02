#include <iostream>

using namespace std;
int main ()
{
    double a, b, c, d;
    cout << "Ingrese valor de a: ";
    cin >> a;
    cout << "Ingrese valor de b: ";
    cin >> b;
    cout << "Ingrese valor de c: ";
    cin >> c;

    d = b*b - 4*a*c; 
    if(d >=0 )
        {
        cout << "Tiene solución en los reales" << endl; 
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("Las dos soluciones son x1 : %.2lf y x2 : %.2lf.\n", x1, x2 );

        }
    else if (d<0)
        {
            cout << "No tiene solución en los reales " << endl;
        }
    
    return 0;
}