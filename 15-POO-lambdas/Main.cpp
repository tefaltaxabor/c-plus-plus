#include "App.hpp"

int main()
{
    auto criterioH = [](Dato d){
        if(d.getSexo() == 'M'){
            return true;
        }else{
            return false;
        }
    };
    App app;
    app.leer();
    app.mostrar();
    app.escribir(criterioH);
    return 0;
}


//-std=c++11 -stdlib=libc++