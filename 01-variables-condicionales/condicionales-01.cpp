/*
Juan tiene gastos mensuales fijos y ingresos recurrentes
Se desean crear ua aplicacion que permita el ingreso de ambos valores
e indique con un mensaje si hay saldo a favor y de cuanto
o si hay saldo en contra y de cuanto, todo al mes
*/
#include <iostream>
using namespace std;
int main(){
    short gasto, ingreso, balance;
    cout << "Ingresa el gasto del mes: ";
    cin >> gasto;
    cout << "Ingresa el ingreso del mes: ";
    cin >> ingreso;
    balance = ingreso-gasto;
    if(balance > 0){
        cout << "Tienes saldo a favor de: " << balance << " soles" << endl;
    }else{
        if(balance < 0){
            cout << "Tienes saldo en contra de: " << balance << " soles" << endl;
        }else{
            cout << "No tienes saldo" << endl;
        }
    }
    return 0;
}