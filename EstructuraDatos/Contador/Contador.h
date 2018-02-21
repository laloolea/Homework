//
// Created by Eduardo Gonzalez Olea on 1/29/18.
//

#ifndef CONTADOR_CONTADOR_H
#define CONTADOR_CONTADOR_H
#include <string>// Para tipo string (cadena de caracteres a estilo c++)
#include <iostream>

class Contador {
    friend Contador operator+ ( Contador i, Contador j);
    friend Contador operator* ( Contador i, Contador j);
    friend Contador operator/ ( Contador i, Contador j);
    friend Contador operator- ( Contador i, Contador j);
    friend std::ostream& operator<<(std::ostream &salida, Contador i);
public:
    Contador();
    Contador(int _inicial);

    Contador & operator++();
    const Contador  operator++(int);
    Contador & operator--();
    const Contador  operator--(int);
protected:


private:
    int valor=0;
};


#endif //CONTADOR_CONTADOR_H
