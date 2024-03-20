#include <iostream>
#include "Coordenada2D.hpp"
#include "Coordenada3D.hpp"
#include "Coordenada4D.hpp"

using namespace std;

template <class T>
class Vector{
    private:
        T inicio;
        T fin;
    public:
        Vector(){}
        Vector(T inicio, T fin){
            this->inicio = inicio;
            this->fin = fin;
        }
        ~Vector(){};
        void setInicio(T inicio){this->inicio = inicio;}
        void setFin(T fin){this->fin = fin;}
        T getInicio(){return this->inicio;}
        T getFin(){return this->fin;}
        void imprimir(){
            cout << "Inicio: (" << this->inicio << ")";
            cout << ", Fin: (" << this->fin << ")";
            cout << ", Modulo: " << this->inicio.calcularDistancia(this->fin) << endl;
        }
};

int main(){
    Coordenada2D ci2d(0, 0);
    Coordenada2D cf2d(5, 12);
    Coordenada3D ci3d(0, 0 , 0);
    Coordenada3D cf3d(3, 1 ,6);
    Coordenada4D ci4d(0, 0 , 0, 0);
    Coordenada4D cf4d(3, 1 ,6 ,0);
    Vector<Coordenada2D> v(ci2d, cf2d);
    Vector<Coordenada3D> h(ci3d ,cf3d);
    Vector<Coordenada4D> q(ci4d ,cf4d);
    v.imprimir();
    h.imprimir();
    q.imprimir();
    return 0;
}