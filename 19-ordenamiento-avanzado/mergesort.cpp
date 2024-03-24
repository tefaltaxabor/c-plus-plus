#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
void merge(vector<T> &v, int l, int m, int r, function<bool(T, T)> cmp){
    // Calculo de longitudes
    int n1 = m-l+1;
    int n2 = r-m;
    // Creacion y dimensionamiento de vectores vl, vr
    vector<T> vl(n1);
    vector<T> vr(n2);
    // Asignacion de valores a elementos de los vectores vl y vr, con datos del vector v
    for(int i=0; i<n1; i++){
        vl[i] = v[l+i];
    }
    for(int i=0; i<n2; i++){ // Corres n1, siendo n1 la longitud del vector anterior vl
        vr[i] = v[m+1+i];
    }

    // Inicializar indices
    int i, j, k;
    i = 0; // Para vl
    j = 0; // Para vr
    k = l; // Para el v (vamos a chancar valores)

    // Buscando valores menores para asignarlos a v
    while(i<n1 && j<n2){
        if(cmp(vl[i], vr[j]) == true){ // if(vl[i] <= vr[j]){ // Comparacion
            v[k] = vl[i];
            i++;
        }else{
            v[k] = vr[j];
            j++;
        }
        k++;
    }

    while(i<n1){ // Cuando aun quedan elementos en vl
        v[k] = vl[i];
        i++;
        k++;
    }

    while(j<n2){ // Cuando aun quedan elementos en vr
        v[k] = vr[j];
        j++;
        k++;
    }
}

template <typename T>
void merge_sort(vector<T> &v, int l, int r, function<bool(T, T)> cmp){
    if(l<r){
        // Calcular el "punto medio"
        int m = l+(r-l)/2;
        merge_sort<T>(v, l, m, cmp);
        merge_sort<T>(v, m+1, r, cmp);
        merge<T>(v, l, m, r, cmp);
    }
}

void imprimir(vector<int> v){
    for(auto e: v){
        cout << e << "\t";
    }
    cout << endl;
}

int main(){
    vector<int> v = {9,5,1,4,6,2,8,7,3};

    auto cmp_asc = [](int n1, int n2){
        if(n1 <= n2) return true;
        else return false;
    };

    auto cmp_desc = [](int n1, int n2){
        if(n1 >= n2) return true;
        else return false;
    };
    
    imprimir(v);
    //merge_sort<int>(v, 0, v.size()-1);
    //merge_sort<int>(v, 0, v.size()-1, cmp_asc);
    merge_sort<int>(v, 0, v.size()-1, cmp_desc);
    imprimir(v);
    return 0;
}

// -std=c++11 -stdlib=libc++