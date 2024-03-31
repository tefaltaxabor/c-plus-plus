/*
Decir si un texto tienen balanceados los signos de agrupacion
Caso simple ()
Caso general (){}[]<>
*/
#include "Stack.hpp"
#include <iostream>

using namespace std;

class Persona{
    private:
        string nombre;
        int edad;
    public:
        Persona(){}
        Persona(string nombre, int edad){
            this->nombre = nombre;
            this->edad = edad;
        }
        friend ostream &operator << (ostream &os, Persona p){
            os << p.nombre << ",";
            os << p.edad;
            return os;
        }
};

int main(){
    Stack<Persona> pila(5);
    pila.display();
    pila.push(Persona("Jose", 20));
    pila.push(Persona("Gabriel", 19));
    pila.push(Persona("Maria", 16));
    pila.display();
    return 0;
}