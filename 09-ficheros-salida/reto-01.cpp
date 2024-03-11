#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Circuitos
{
    string cabecera;
    string nombre_del_circuito;
    double r1;
    double r2;
    double r3;
    double resistencias_en_serie;
    double resistencias_en_paralelo;
};

void leer_datos(vector<struct Circuitos> &datosreto )
{
    string cabecera;
    string nombre_del_circuito;
    string r1_str; double r1;
    string r2_str; double r2;
    string r3_str; double r3;
    ifstream f("datosreto.txt");
    getline(f, cabecera);
    while(getline(f, nombre_del_circuito, ',' )){
        getline(f, r1_str  , ',');
        getline(f, r2_str , ',');
        getline(f , r3_str);
        //Casting de datos
        r1 = stod(r1_str);
        r2 = stod(r2_str);
        r3 = stod(r3_str);
        //Variable temporal
        struct Circuitos p;
        p.r1 = r1;
        p.r2 = r2;
        p.r3 = r3;
        p.nombre_del_circuito = nombre_del_circuito;
        p.resistencias_en_serie = p.r1 + p.r2 + p.r3;
        p.resistencias_en_paralelo = 1.0 / (1.0 / p.r1 + 1.0 / p.r2 + 1.0 / p.r3);
        datosreto.push_back(p);
    }
    f.close();
}

void escribir_datos_resistencias_en_serie(vector<struct Circuitos> datosreto)
{
    int n = datosreto.size();
    ofstream f("Resistencias-en-serie.txt");
    f << "Nombres del Circuito,Resistencia Total" << endl;
    for(int i = 0; i < n ; i++)
    {
        f <<datosreto[i].nombre_del_circuito<<",";
        f <<datosreto[i].resistencias_en_serie << endl;
    }
    f.close();
}

void escribir_datos_resistencias_en_paralelo(vector<struct Circuitos> datosreto)
{
    int n = datosreto.size();
    ofstream f("Resistencias-en-paralelo.txt");
    f << "Nombres del Circuito,Resistencia Total" << endl;
    for(int i = 0; i < n ; i++)
    {
        f <<datosreto[i].nombre_del_circuito<<",";
        f <<datosreto[i].resistencias_en_paralelo << endl;
    }
    f.close();
}

int main()
{
    vector<struct Circuitos> datosreto;
    leer_datos(datosreto);
    escribir_datos_resistencias_en_serie(datosreto);
    escribir_datos_resistencias_en_paralelo(datosreto);
    return 0;
}