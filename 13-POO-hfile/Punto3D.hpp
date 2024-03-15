#include<iostream>
#include<cmath>
using namespace std;
class Punto3D
{
    private://Atributos
        double x;
        double y;
        double z;
    public: // metodo constructor
        Punto3D(){}; // constructor vacio
        Punto3D(double x, double y , double z) 
        {
            this->x = x; 
            this->y = y;
            this->z = z;
        }
        ~Punto3D(){}
        // Setter y Getter 
        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }
        void setZ(double z) { this->z = z; }
        double getX(){ return this->x; }
        double getY(){ return this->y; }
        double getZ(){ return this->z; }
        //metodos ah doc
         double calcular_distancia_origen()
        {
            return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
        }
        // Sobrecargar la escritura (1.2, 3.4, 7.9) -> 1.2,3.4,7.9
         friend ostream &operator << (ostream &os, Punto3D p){
            os << p.x << ",";
            os << p.y << ",";
            os << p.z;
            return os;
        }
};