#include <iostream>
using namespace std;
int main(){
    int x;
    float y;
    x = 3;
    y = 4.5;
    cout << "Valor de x: " << x << endl;
    cout << "Valor de y: " << y << endl;
    cout << "Direccion de memoria de x: " << &x << endl;
    cout << "Direccion de memoria de y: " << &y << endl;
    cout << "Valor de x+y: " << x+y << endl;
    int* ptr_x;
    float* ptr_y;
    ptr_x = &x;
    ptr_y = &y;
    cout << "Direccion de memoria de x: " << ptr_x << endl;
    cout << "Direccion de memoria de y: " << ptr_y << endl;
    *ptr_x = *ptr_x + 1;
    cout << "Direccion de memoria de x: " << ptr_x << endl;
    cout << "Direccion de memoria de y: " << ptr_y << endl;
    cout << "Valor de x: " << x << endl;
    cout << "Valor de y: " << y << endl;
    cout << "Valor de x+y: " << (*ptr_x) * (*ptr_y) << endl;
    return 0;
}