#include <stack>
#include <iostream>
using namespace std;
int main(){
    stack<char> pila;
    cout << "Tamanho: " << pila.size() << endl;
    pila.push('A');
    cout << "Tamanho: " << pila.size() << endl;
    pila.push('B');
    cout << "Tamanho: " << pila.size() << endl;
    pila.push('C');
    cout << "Tamanho: " << pila.size() << endl;
    cout << "Top: " << pila.top() << endl;
    cout << "Haciendo pop" << endl;
    pila.pop();
    cout << "Tamanho: " << pila.size() << endl;
    cout << "Top: " << pila.top() << endl;
    return 0;
}