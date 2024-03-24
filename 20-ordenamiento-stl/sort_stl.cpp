#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void imprimir(vector<int> v){
    for(auto e: v){
        cout << e << "\t";
    }
    cout << endl;
}

template <typename T>
bool cmp(T v1, T v2){
    if(v1 <= v2) return true;
    else return false;
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
    sort(v.begin(), v.end());
    imprimir(v);
    sort(v.begin(), v.end(), greater<int>());
    imprimir(v);
    sort(v.begin(), v.end(), cmp<int>);
    imprimir(v);
    sort(v.begin(), v.end(), cmp_desc);
    imprimir(v);
    return 0;
}

// -std=c++11 -stdlib=libc++
































