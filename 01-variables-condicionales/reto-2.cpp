#include <iostream>
using namespace std;
int main()
{
    float s ,r ,c ,p;
    p = 3.14;

    cout << "Valor del Angulo en sexagecimales: ";
    cin >> s;
    r = s * (p/180);
    c = (s*10)/9;

    printf("El valor en radianes es: %.2lf.\n",r);
    printf("El valor en centecimales es: %.2lf.\n",c );
    
    return 0;
}