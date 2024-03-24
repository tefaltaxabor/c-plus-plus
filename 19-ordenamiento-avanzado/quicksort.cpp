#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
int partition(vector<T> &v, int l, int r, function<bool(T, T)> cmp){
    T x = v[r]; // Elegimos como pivote el elemento de mas hacia la derecha
    int i = l-1; // Indice o posicion temporal del menor valor (esta fuera del rango l, r)
    for(int j=l; j<r; j++){
        if(cmp(v[j], x) == true){ // if(v[j] <= x){ // comparacion
            i++;
            /*
            auto temp = v[j];
            v[j] = v[i];
            v[i] = temp;
            */
            swap(v[j], v[i]);
        }
    }
    swap(v[i+1], v[r]);
    return i+1;
}

template <typename T>
void quick_sort(vector<T> &v, int l, int r, function<bool(T, T)> cmp){
    if(l<r){
        // Eleccion del pivote
        int piv = partition(v, l, r, cmp);

        // Llamada a la recursion
        quick_sort<T>(v, l, piv-1, cmp);
        quick_sort<T>(v, piv+1, r, cmp);
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
    //quick_sort<int>(v, 0, v.size()-1);
    quick_sort<int>(v, 0, v.size()-1, cmp_asc);
    //quick_sort<int>(v, 0, v.size()-1, cmp_desc);
    imprimir(v);
    return 0;
}

// -std=c++11 -stdlib=libc++












































