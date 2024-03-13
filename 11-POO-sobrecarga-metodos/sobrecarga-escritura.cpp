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
        // Sobrecarga operador de escritura <<
        friend ostream &operator << (ostream &os, Punto3D p){
            os << "(";
            os << p.x << ", ";
            os << p.y << ", ";
            os << p.z << ")";
            return os;
        }
};
class Vector3D
{
    private:
        Punto3D pi;
        Punto3D pf;
        double modulo;
    public:
        Vector3D(Punto3D pi , Punto3D pf)
        {
            this->pi = pi;
            this->pf = pf;
        }
        ~Vector3D(){};
        void setPi(Punto3D pi){this->pi = pi;}
        void setPf(Punto3D pf){this->pf = pf;}
        void setModulo(){ this->modulo = sqrt(pow(this->pf.getX() - this->pi.getX(), 2) + pow(this->pf.getY()-this->pi.getY(),2) + pow(this->pf.getZ() - this->pi.getZ() , 2) );};
        Punto3D getPi(){return this->pi;}
        Punto3D getPf(){return this->pf;}
        double getModulo(){
            this->setModulo();
            return this->modulo;
        }
        // Sobrecarga operador de escritura <<
        friend ostream &operator << (ostream &os, Vector3D v){
            v.setModulo(); // Actualiza el valor del atributo modulo antes de usarlo
            os << "Punto inicial = ";
            os << v.pi << ", ";
            os << "Punto final = ";
            os << v.pf << ", ";
            os << "Modulo = ";
            os << v.modulo;
            return os;
        }
};


int main()
{
    Punto3D pi(3,2,0);
    Punto3D pf(8,7,1);
    Vector3D v(pi, pf);
    cout << v << endl;
    return 0;
}