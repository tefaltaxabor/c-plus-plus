#include "SimpleLinkedList.hpp"
#include "Persona.hpp"
int main(){
    SimpleLinkedList<Persona> lista;
    lista.insert(Persona("Maria", 32));
    lista.insert(Persona("Luis", 16));
    cout << "Elementos de la lista" << endl;
    lista.print();
    return 0;
}

// -std=c++11 -stdlib=libc++