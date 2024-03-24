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