#include "BinarySearchTree.hpp"
#include "Persona.hpp"
#include <iostream>

using namespace std;

int main(){
    auto criteriaAge = [](Persona p1, Persona p2){
        if(p1.getEdad() < p2.getEdad()){
            return -1;
        }else if(p1.getEdad() > p2.getEdad()){
            return 1;
        }else{
            return 0;
        }
    };
    BinarySearchTree<Persona> bst;
    cout << "Cantidad de nodos: " << bst.quantity() << endl;
    bst.insert(Persona("Jose", 20), criteriaEdad);
    cout << "Cantidad de nodos: " << bst.quantity() << endl;
    return 0;
}

//-std=c++11 -stdlib=libc++