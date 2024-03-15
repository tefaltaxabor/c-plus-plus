#include<iostream>
#include<cmath>
using namespace std;

// Clase de tipo dato/registro
class Vector3D
{
    private:
        Punto3D pi;
        Punto3D pf;
        double modulo;
    public:
        Vector3D(double pi_x, double pi_y, double pi_z, double pf_x, double pf_y, double pf_z)
        {
            this->pi = Punto3D(pi_x, pi_y, pi_z);
            this->pf = Punto3D(pf_x, pf_y, pf_z);
        }
        Vector3D(Punto3D pi , Punto3D pf)
        {
            this->pi = pi;
            this->pf = pf;
        }
        ~Vector3D(){};
        void setPi(Punto3D pi){this->pi = pi;}
        void setPf(Punto3D pf){this->pf = pf;}
        void setModulo(){ this->modulo = sqrt(  pow(this->pf.getX() - this->pi.getX(), 2) + pow(this->pf.getY()-this->pi.getY(),2) + pow(this->pf.getZ() - this->pi.getZ() , 2) );};
        Punto3D getPi(){return this->pi;}
        Punto3D getPf(){return this->pf;}
        double getModulo(){
            this->setModulo();
            return this->modulo;
        }
        friend ostream &operator << (ostream &os, Vector3D v){
            v.setModulo(); // Actualiza el valor del atributo modulo antes de usarlo
            os << v.pi << ",";
            os << v.pf << ",";
            os << v.modulo;
            return os;
        }
};