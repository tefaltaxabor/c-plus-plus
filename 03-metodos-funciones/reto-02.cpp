#include<iostream>

using namespace std;
double a, b, c, d;

double calcular_cuadratica()
{   
    cout << "Ingrese valor de a: ";
    cin >> a;
    cout << "Ingrese valor de b: ";
    cin >> b;
    cout << "Ingrese valor de c: ";
    cin >> c;

    d = b*b - 4*a*c;
    return d;
}

double soluciones_reales_y_no_reales(double d)
{
    if(d >=0 )
        {
        cout << "Tiene solución en los reales" << endl; 
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("Las dos soluciones son x1 : %.2lf y x2 : %.2lf.\n", x1, x2 );

        }
    else if (d<0)
        {
            cout << "Tiene soluciön en los complejos " << endl;
            double c = sqrt (d*d);
            double parteReal = -b / (2 * a);
            double parteImaginaria = c / (2 * a);
            printf("Las dos soluciones son x1: %.2lf + %.2lfi y x2: %.2lf - %.2lfi.\n",
               parteReal, parteImaginaria, parteReal, parteImaginaria);
        }
    
    return 0;

}

int main()
{
    
    
    d = calcular_cuadratica();
    soluciones_reales_y_no_reales(d);
    return 0; 
}
