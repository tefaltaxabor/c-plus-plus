#include "AVL.hpp"
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
    AVL<Persona> avl(imprimir);
    //avl.setProcess();
    
    //cout << "Cantidad de nodos: " << avl.quantity() << endl;
    cout << "Altura: " << avl.height() << endl;
    avl.insert(Persona("Jose", 45), criteriaAge);
    cout << "Altura: " << avl.height() << endl;
    avl.insert(Persona("Pedro", 23), criteriaAge);
    cout << "Altura: " << avl.height() << endl;
    avl.insert(Persona("Rodrigo", 2), criteriaAge);
    cout << "Altura: " << avl.height() << endl;
    avl.insert(Persona("Pepe", 7), criteriaAge);
    cout << "Altura: " << avl.height() << endl;
    avl.insert(Persona("Juan", 38), criteriaAge);
    cout << "Altura: " << avl.height() << endl;
    /*avl.insert(Persona("Maria",65), criteriaAge);
    avl.insert(Persona("Camila", 52), criteriaAge);
    avl.insert(Persona("Pablo", 48), criteriaAge);
    avl.insert(Persona("Marcelo", 96), criteriaAge);
    */
    //cout << "Cantidad de nodos: " << avl.quantity() << endl;
    cout << "Recorrido In Order: " << endl;
    avl.inOrder();
    cout<< endl;
    cout << "Recorrido Pre Order: " << endl;
    avl.preOrder();
    cout<< endl;
    cout << "Recorrido Post Order: " << endl;
    avl.postOrder();
    cout<< endl;
    cout << "Busqueda #1" << endl;
    /*if(avl.search(Persona("Maria",65),criteriaAge) == true){
        cout << "Si se encontro la informacion" << endl;
    }else{
        cout << "No se encontro la informacion" << endl;
    }
    cout << "Busqueda #2" << endl;
    if(avl.search(Persona("Roberto",60),criteriaAge) == true){
        cout << "Si se encontro la informacion" << endl;
    }else{
        cout << "No se encontro la informacion" << endl;
    }
    avl.display();
    */
    return 0;
}

//-std=c++11 -stdlib=libc++