#include "Queue.hpp"
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
    Queue<Persona> cola;
    cola.display();
    cola.push(Persona("Jose", 20));
    cola.push(Persona("Gabriel", 19));
    cola.push(Persona("Maria", 16));
    cola.display();
    cout << "Se hace pop" << endl;
    cola.pop();
    cola.display();
    return 0;
}