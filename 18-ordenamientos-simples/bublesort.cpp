#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
void bubble_sort(vector<T> &v, function<bool(T, T)> cmp){
    int n = v.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(cmp(v[j], v[j+1]) == false){
                auto temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
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
    bubble_sort<int>(v, cmp_desc);
    imprimir(v);
    return 0;
}

// -std=c++11 -stdlib=libc++