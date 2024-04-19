#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {1,5,2,3,4,6,9,7,8};

    cout << "Recorrido utilizando posiciones" << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\t";
    }
    cout << endl;

    cout << "Recorrido for each (solo valores)" << endl;
    for(auto e: v){ // for(auto &e: v) // Para manipular los valores
        cout << e << "\t";
    }
    cout << endl;

    cout << "Recorrido for each (manipulacion de valores)" << endl;
    for(auto &e: v){ 
        cout << e + 1 << "\t"; // v[i] + 1
    }
    cout << endl;

    cout << "Recorrido utilizando iteradores" << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << "\t";
    }
    cout << endl;

    // it++ = advamce(it, 1)
    // Puede haber un desvordamiento si no esta correctamente ubicadas las posiciones -> segmentation fault

    cout << "Recorrido utilizando iteradores (advance)" << endl;
    for(vector<int>::iterator it = v.begin(); it != v.end(); advance(it, 3))/*arriba señalado para avanzar de 3 en 3*/ {
        cout << *it << "\t"; // *it para acceder al valor almacenado en la direccion de memoria
    }
    cout << endl;


    return 0;
}

//-std=c++11 -stdlib=libc++