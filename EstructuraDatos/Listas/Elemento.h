//
// Created by Eduardo Gonzalez Olea on 2/21/18.
//

#ifndef LISTAS_ELEMENTO_H
#define LISTAS_ELEMENTO_H
#include <cstdlib>

class Elemento {
public:
    Elemento(int _valor,Elemento * _siguiente=NULL);


private:
    int valor;
    Elemento * siguiente;
};


#endif //LISTAS_ELEMENTO_H
