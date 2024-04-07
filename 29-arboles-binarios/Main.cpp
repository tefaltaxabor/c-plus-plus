#include "BinarySearchTree.hpp"
#include "Persona.hpp"
#include <iostream>

using namespace std;

void imprimir(Persona p){
    cout << p << " ";
}

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
    bst.setProcess(imprimir);
    cout << "Cantidad de nodos: " << bst.quantity() << endl;
    cout << "Altura: " << bst.height() << endl;
    bst.insert(Persona("Jose", 45), criteriaAge);
    bst.insert(Persona("Pedro", 23), criteriaAge);
    bst.insert(Persona("Rodrigo", 2), criteriaAge);
    bst.insert(Persona("Pepe", 7), criteriaAge);
    bst.insert(Persona("Juan", 38), criteriaAge);
    bst.insert(Persona("Maria",65), criteriaAge);
    bst.insert(Persona("Camila", 52), criteriaAge);
    bst.insert(Persona("Pablo", 48), criteriaAge);
    bst.insert(Persona("Marcelo", 96), criteriaAge);
    cout << "Cantidad de nodos: " << bst.quantity() << endl;
    cout << "Altura: " << bst.height() << endl;
    cout << "Recorrido In Order: " << endl;
    bst.inOrder();
    cout<< endl;
    cout << "Recorrido Pre Order: " << endl;
    bst.preOrder();
    cout<< endl;
    cout << "Recorrido Post Order: " << endl;
    bst.postOrder();
    cout<< endl;
    cout << "Busqueda #1" << endl;
    if(bst.search(Persona("Maria",65),criteriaAge) == true){
        cout << "Si se encontro la informacion" << endl;
    }else{
        cout << "No se encontro la informacion" << endl;
    }
    cout << "Busqueda #2" << endl;
    if(bst.search(Persona("Roberto",60),criteriaAge) == true){
        cout << "Si se encontro la informacion" << endl;
    }else{
        cout << "No se encontro la informacion" << endl;
    }
    bst.display();
    return 0;
}

//-std=c++11 -stdlib=libc++