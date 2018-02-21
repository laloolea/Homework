//
// Created by Eduardo Gonzalez Olea on 1/29/18.
//

#include "Contador.h"


Contador::Contador(int _valor)
{
    valor = _valor;
}

Contador::Contador()
{
    valor=0;
}

Contador operator+(Contador i, Contador j)
{
    return Contador(i.valor + j.valor);
}

Contador operator*(Contador i, Contador j) {
    return Contador(i.valor*j.valor);
}

Contador operator/(Contador i, Contador j) {
    return Contador(i.valor/j.valor);
}

Contador operator-(Contador i, Contador j) {
    return Contador(i.valor-j.valor);
}

std::ostream &operator<<(std::ostream &salida, Contador i)
{
    salida << i.valor;
    /*
    for(int i = 0 ; i < v.dim ; ++i){
        salida << v.entrada[i] << ",";
    }
    salida << "\b)";
     */
    return salida;
}

Contador & Contador::operator++()
{
    ++valor ;
    return *this ;
}

Contador &Contador::operator--()
{
    --valor ;
    return *this ;
}

const Contador Contador::operator++(int) {
    Contador copia;
    copia= *this;

    ++valor ;

    return copia ;
}

const Contador Contador::operator--(int) {
    Contador copia;
    copia= *this;

    --valor ;

    return copia ;
}
