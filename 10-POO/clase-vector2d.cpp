#include <iostream>
#include <cmath>
using namespace std;

class Punto2D{
    // Atributos
    // Atributos private
    private:
        double x;
        double y;
    
    // Metodos
    public:
        // Metodo constructor
        Punto2D(){} // Constructor vacio
        Punto2D(double x, double y){
            this->x = x;
            this->y = y;
        }
        // Metodo destructor
        ~Punto2D(){}
        // Setter y getter
        // Metodos set
        void setX(double x){  this->x = x; }
        void setY(double y){ this->y = y; }
        // Metodos get
        double getX(){ return this->x; }
        double getY(){ return this->y; }
        // Metodos ah doc
        double calcular_distancia_origen(){
            return sqrt(pow(this->x,2)+pow(this->y,2));
        }
};

class Vector2D{
    private:
        // Atributos
        Punto2D pi;
        Punto2D pf;
        double modulo;
    public:
        // Constructor
        Vector2D(Punto2D pi, Punto2D pf){
            this->pi = pi;
            this->pf = pf;
        }
        // Destructor
        ~Vector2D(){}
        // Setter y getter
        void setPi(Punto2D pi){ this->pi = pi; }
        void setPf(Punto2D pf){ this->pf = pf; }
        void setModulo(){ this->modulo = sqrt(pow(this->pf.getX()-this->pi.getX(),2)+pow(this->pf.getY()-this->pi.getY(),2)); };
        Punto2D getPi(){ return this->pi; }
        Punto2D getPf(){ return this->pf; }
        double getModulo(){
            this->setModulo();
            return this->modulo;
        }
};

int main(){
    Punto2D pi(1,1);
    Punto2D pf(5,4);
    Vector2D v(pi, pf);
    cout << v.getModulo();
    return 0;
}