#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Punto3D{
    float x;
    float y;
    float z;
};

struct Punto3D generar_punto(){
    struct Punto3D p;
    int min = -10, max = 10;
    p.x = rand()%(max-min+1)+min;
    p.y = rand()%(max-min+1)+min;
    p.z = rand()%(max-min+1)+min;
    return p;
}

void mostrar_punto(struct Punto3D p){
    cout << "(" << p.x << ", " << p.y << ", " << p.z << ")"<< endl;
}

void mostrar_puntos(struct Punto3D* puntos, int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << "p" << i+1 << " = ";
        mostrar_punto(puntos[i]);
    }
}

struct Punto3D* generar_puntos(int n){
    struct Punto3D* puntos;
    puntos = new struct Punto3D[n];
    for(int i=0; i<n; i++){
        puntos[i] = generar_punto();
    }
    return puntos;
}

float calcular_distancia(struct Punto3D p1, struct Punto3D p2){
    float d;
    d = sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2)+pow(p1.z-p2.z, 2));
    return d;
}

struct Punto3D punto_medio(struct Punto3D p1 , struct Punto3D p2)
{
    struct Punto3D punto_medio;
    punto_medio.x = (p1.x + p2.x) / 2.0;
    punto_medio.y = (p1.y + p2.y) / 2.0;
    punto_medio.z = (p1.z + p2.z) / 2.0;
    return punto_medio;
}

struct Punto3D centroide(struct Punto3D *puntos , int n)
{
    struct Punto3D punto_c;
    punto_c.x = 0;
    punto_c.y = 0;
    punto_c.z = 0;
    for ( int i = 0 ; i < n ; i++)
    {
        punto_c.x = punto_c.x + puntos[i].x / n;
        punto_c.y = punto_c.y + puntos[i].y / n;
        punto_c.z = punto_c.z + puntos[i].z / n;
    }
    return punto_c;
}



int main(){
    struct Punto3D p1;
    struct Punto3D p2;
    struct Punto3D p3;
    struct Punto3D *puntos;
    int n = 4;
    p1 = generar_punto();
    p2 = generar_punto();
    puntos = new struct Punto3D[n];
    
    cout << "p1 = "; mostrar_punto(p1);
    cout << "p2 = "; mostrar_punto(p2);
    cout << "Distancia entre p1 y p2 = " << calcular_distancia(p1, p2) << endl;
    p3 = punto_medio(p1,p2);
    cout << "Punto medio entre p1 y p2 = "; mostrar_punto(p3);
    
    puntos = generar_puntos(n);
    mostrar_puntos(puntos, n);
    cout << "Centroide = ";
    mostrar_punto(centroide(puntos, n));


    return 0;
}