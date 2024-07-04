#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
void insertion_sort(vector<T> &v, function<bool(T, T)> cmp){
    int n = v.size();
    for(int i = 1; i < n; i++){
        auto key = v[i]; // El elemento que voy a insertar
        int j = i-1;
        while(j >= 0 && cmp(key, v[j]) == true){ // while(j >= 0 && key < v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void insertion_sort_arrays(int A[],int n){
    int j = 0;
    while(j < n){
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key ;
        j++;
    } 
}



// [9,5,1,4,6,2,8,7,3]

void imprimir(vector<int> v){
    for(auto e: v){
        cout << e << "\t";
    }
    cout << endl;
}



int main(){

    int A[] = {9,5,1,4,6,11,2,8,7,3};
    vector<int> v = {9,5,1,4,6,2,8,7,3};
    auto cmp_asc = [](int n1, int n2){
        if(n1 <= n2) return true;
        else return false;
    };
    auto cmp_desc = [](int n1, int n2){
        if(n1 >= n2) return true;
        else return false;
    };
    int longitud  = sizeof(A)/sizeof(A[0]);
    cout << longitud << endl;
    imprimir(v);
    insertion_sort_arrays(A,longitud);
    //insertion_sort<int>(v);
    insertion_sort<int>(v, cmp_asc);
    //insertion_sort<int>(v, cmp_desc);
    cout << "Insertion sort con vectores" << endl;
    imprimir(v);
    /*cout << "Insertion sort con array" << endl;
    for (int i = 0 ; i < longitud ; i++)
        cout << A[i] << "\t";
    */
    return 0;

}

// -std=c++11 -stdlib=libc++