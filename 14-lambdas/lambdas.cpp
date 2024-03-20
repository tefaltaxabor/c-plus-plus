#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void mostrar_segun_criterio(vector<int> v, function<bool(int)> f){
    for(int i=0; i<v.size(); i++)
    {
        if(f(v[i]) == true)
        {
            cout << v[i] << "\t";
        }
    }
    cout << endl;
}

int main(){
    // criterio de paridad
    auto criterioParidad = [](int n){
        if(n%2 == 0){
            return true;
        }else{
            return false;
        }
    };

    auto criterioDivisibilidadPor5 = [](int n){
        if(n%5 == 0){
            return true;
        }else{
            return false;
        }
    };

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    
    // mostrar_segun_criterio(v, criterioParidad);
    mostrar_segun_criterio(v, criterioDivisibilidadPor5);
    return 0;
}

//Crear una aplicaicon que permita leer datos de una archivo> nombre,sexo,saldo
//Jose,M,5800
//Ana,F,7200
//Y usando funciones lambda cree un archivo con los datos de varones y otro con los de mujeres