#include <iostream>

using namespace std;

int main() {
    int n;
    do {
        cout << "Ingrese un numero positivo: ";
        cin >> n;
        if (!(n > 0)) {
            cout << "Ingrese un numero positivo." << endl;
        }
    } while (!(n > 0));

    for (int i = 1; i <= n; i++) {
        cout << i;
    }
    cout << endl;

    for (int i = 2; i < n; i++) {

        for (int j = 1; j <= n; j++) {
            if(j==1){
                cout << i;
            }else if(j==n){
                cout << n-i+1;
            }else{
                cout << " ";
            }
            
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--) {
        cout << i;
    }
    cout << endl;

    return 0;
}
