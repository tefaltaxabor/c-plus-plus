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
