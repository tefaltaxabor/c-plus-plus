#include <iostream>
using namespace std;
int main(){
    int n = 5;
    
    //n++ // n = n+1; n+=1;
    //cout << n << endl;

    // Imprimiendo 5 primeros numeros pares
    for(int i=1; i<=n; i++){
        cout << 2*i << "\t";
    }
    cout << endl;
    for(int i=2; i<=10; i+=2){
        cout << i << "\t";
    }
    cout << endl;
    // Imprimir los 10 primeros numeros que sean multiplos de 2 pero no de 5
    int cont = 0;
    for(int i=2; i<1000 && cont < 10; i+=2){
        if(i%5 != 0){
            cout << i << "\t";
            cont++;
        }
    }
    cout << endl;
    // Dado un valor de n, imprimir la figura asociada
    /*
    n = 5
    #####
    ####
    ###
    ##
    #
    */
    cout << "n: "; cin >> n;
    for(int f=1; f<=n; f++){
        for(int c=1; c<=n-f+1; c++){
            cout << "#";
        }
        cout << endl;
    }
    // Dado un valor de n, imprimir la figura asociada
    /*
    n = 5
    #####
     ####
      ###
       ##
        #
    */
    cout << "n: "; cin >> n;
    for(int f=1; f<=n; f++){
        for(int c=1; c<=f-1; c++){
            cout << " ";
        }
        for(int c=1; c<=n-f+1; c++){
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}