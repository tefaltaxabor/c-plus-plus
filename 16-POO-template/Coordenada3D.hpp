#include <iostream>
using namespace std;
class Coordenada3D{
    private:
        double x;
        double y;
        double z;
    public:
        Coordenada3D(){}
        Coordenada3D(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        ~Coordenada3D(){};
        void setX(double x){this->x = x;}
        void setY(double y){this->y = y;}
        void setZ(double z){this->z = z;}
        double getX(){return this->x;}
        double getY(){return this->y;}
        double getZ(){return this->z;}
        double calcularDistancia(Coordenada3D c){
            double distancia = sqrt(pow(c.x - this->x, 2) + pow(c.y - this->y, 2) + pow(c.z - this->z, 2));
            return distancia;
        }
        friend ostream &operator << (ostream &os, Coordenada3D c){
            os << c.x << ",";
            os << c.y << ",";
            os << c.z;
            return os;
        }
};