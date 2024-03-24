#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
void shell_sort(vector<T> &v, function<bool(T, T)> cmp){
    int n = v.size();
    int i, j, k, intervalo = n/2;
    while(intervalo > 0){
        for(i = intervalo; i<n; i++){
            j = i-intervalo; // j=0 por primera vez
            while(j >= 0){
                k = j+intervalo; // El elemento de criterio para empezar a la mitad
                if(cmp(v[j], v[k]) == true){ // if(v[j] <= v[k]){ // Comparacion
                    j = -1; // Se sale del bucle pues ya esta ordenado ese par de elementos
                }else{
                    swap(v[j], v[k]);
                    j = j-intervalo; // Se corre el j hacia atras
                }
            }
        }
        intervalo = intervalo/2;
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
    //shell_sort<int>(v);
    //shell_sort<int>(v, cmp_asc);
    shell_sort<int>(v, cmp_desc);
    imprimir(v);
    return 0;
}

// -std=c++11 -stdlib=libc++












































