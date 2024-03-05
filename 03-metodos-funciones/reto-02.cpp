#include<iostream>

using namespace std;
double a, b, c, d;

void leer_coeficientes(double &a, double &b, double &c)
{   
    cout << "Ingrese valor de a: ";
    cin >> a;
    cout << "Ingrese valor de b: ";
    cin >> b;
    cout << "Ingrese valor de c: ";
    cin >> c;
}

double soluciones_reales_y_no_reales(double a, double b, double c)
{
    double d = b*b - 4*a*c;
    if(d >=0 )
        {
        cout << "Tiene solución en los reales" << endl; 
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("Las dos soluciones son x1 : %.2lf y x2 : %.2lf.\n", x1, x2);

        }
    else if (d<0)
        {
            cout << "Tiene soluciön en los complejos " << endl;
            double sqrtdp = sqrt (-d);
            double parteReal = -b / (2 * a);
            double parteImaginaria = sqrtdp / (2 * a);
            if(parteImaginaria > 0){
                printf("Las dos soluciones son x1: %.2lf + %.2lfi y x2: %.2lf - %.2lfi.\n", parteReal, parteImaginaria, parteReal, parteImaginaria);
            }else{
                printf("Las dos soluciones son x1: %.2lf + %.2lfi y x2: %.2lf - %.2lfi.\n", parteReal, -parteImaginaria, parteReal, -parteImaginaria);
            }
        }
    
    return 0;

}

int main()
{
    
    double a, b, c;
    leer_coeficientes(a,b,c);
    soluciones_reales_y_no_reales(a,b,c);
    return 0; 
}
