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
        string getNombre(){return this->nombre;}
        int getEdad(){return this->edad;}
        
        friend ostream &operator << (ostream &os, Persona p){
            os << p.nombre << ",";
            os << p.edad;
            return os;
        }

        bool operator == (Persona p){
            if(nombre == p.nombre && edad == p.edad){
                return true;
            }else{
                return false;
            }
        }
};