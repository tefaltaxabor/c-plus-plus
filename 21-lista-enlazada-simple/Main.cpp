#include "App.hpp"

int main()
{
    auto criterioDni = [](Dato d1, Dato d2){
        if(d1.getDni() <= d2.getDni()){
            return true;
        }else{
            return false;
        }
    };
    auto criterioSaldo = [](Dato d1, Dato d2){
        if(d1.getSaldo() <= d2.getSaldo()){
            return true;
        }else{
            return false;
        }
    };
    App app;
    app.leer();
    app.mostrar();
    app.llenarSLL();
    app.mostrarSLL();
    //app.ordenar(criterioDni);
    app.ordenar(criterioSaldo);
    app.mostrar();
    app.escribir();
    app.buscarPorNombre("Pedro Luis");
    return 0;
}


//-std=c++11 -stdlib=libc++