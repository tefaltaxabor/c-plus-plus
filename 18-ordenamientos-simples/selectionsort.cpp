#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
void selection_sort(vector<T> &v, function<bool(T, T)> cmp){
    int n = v.size();
    for(int i = 0; i < n; i++){
        int min_index = i;
        // Busqueda del menor entre las posiciones i y n-1
        for(int j = i+1; j < n; j++){
            if(cmp(v[j], v[min_index]) == true){ // if(v[j] < v[min_index]){
                min_index = j;
            }
        }
        // Intercambio de elementos
        auto temp = v[i];
        v[i] = v[min_index];
        v[min_index] = temp;
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
    //selection_sort<int>(v);
    //selection_sort<int>(v, cmp_asc);
    selection_sort<int>(v, cmp_desc);
    imprimir(v);
    return 0;
}

// -std=c++11 -stdlib=libc++