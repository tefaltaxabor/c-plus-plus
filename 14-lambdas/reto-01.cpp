#include<iostream>
#include<functional>
#include<fstream>
#include<vector>

using namespace std;

//recibir la entrada de datos
//utilizar las funciones lambda para separar como mostrar_por_sexo(sexo,criterio_masculino/femenino) y tenga salida como fichero

void lectura_de_datos(vector<struct Datos>& datos){
    string cabecera;
    string Nombre; 
    string sexo_str; char sexo;
    string saldo_str; int saldo;
    ifstream f("datos.txt");
    getline(f, cabecera);
    while(getline(f, Nombre, ',')) {
        getline(f, sexo_str , ',');
        getline(f, saldo_str);
        sexo = sexo_str[0];
        saldo = stoi(saldo_str); 
        //Variable temporal
        struct Datos p;
        p.Nombre = Nombre;
        p.sexo = sexo;
        p.saldo =  saldo;
        datos.push_back(p);
    }
    f.close();
}

void mostrar_por_sexo(vector<struct Datos> p , function<bool(char)>f, char sexo){
    if(f(sexo == 'M' )){
    ofstream v("Datos Mujeres");
    v << "Datos Mujeres" << endl;
    for(int i = 0 ; i < p.size() ; i++){
        cout<< p[i].Nombre << ",";
        cout<< f(sexo = 'M') <<",";
        cout<< p[i].saldo << endl;
    }
    v.close();
    }
    else{
    ofstream h ("Datos Hombre");
    h << "Datos Hombres" << endl;
    for(int i = 0 ; i < p.size() ; i++){
        cout<< p[i].Nombre << ",";
        cout<< f(sexo ='H') <<",";
        cout<< p[i].saldo << endl;
    }
    h.close();

    }
}

int main(){


    
    return 0;
}