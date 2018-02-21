//
// Created by Eduardo Gonzalez Olea on 2/12/18.
//

#ifndef EGO_ESTRUCTURALIFO_PILA_H
#define EGO_ESTRUCTURALIFO_PILA_H
#include "Excepciones.h"
#include "Complejo.h"
//  #define CAP_MAX 50
template <typename  tipo=int,int cap=50>
class Pila {
//metodo estatico solo puede acceder a los atributos estaticos

public:

    Pila ();

    tipo ObtenerTope();

    void AgregarElemento(tipo valor); // push();

    tipo EliminarElemento();          // int pop();

    int ObtenerTamanio();            // int size();

     const int ObtenerCapacidad();          // int capacity();

    bool EstaVacia();                // bool empty();

    bool EstaLlena();                // bool full();

    void VaciarPila();

private:
    int tope;
    int CAPACIDAD;
    tipo elemento[cap];
    bool EstaLlena();
};

template <typename tipo,int cap>
Pila<tipo,cap>::Pila() : tope(-1),CAPACIDAD(cap){ }



template <typename tipo,int cap>// plantilla de función
tipo Pila<tipo,cap>::ObtenerTope () {// segundo cambio<tipo>

    if(EstaVacia()) throw Excepcion("Esta Vacia");
    return elemento[tope];
}
template <typename tipo,int cap>
void Pila<tipo,cap>::AgregarElemento (tipo valor)
{
    //++tope;


    if(EstaLlena ())
    {

    }

    //cuando esta vacia y quieres sacar elemento,
    // cuando esta vacia y queires conocer tope pila

    elemento[++tope]= valor;
}

template <typename tipo,int cap>
tipo Pila<tipo,cap>::EliminarElemento () {

    if(EstaVacia ())throw Excepcion("Pila vacia no puedes eliminar");
    return elemento[ tope-- ];// devuelve tope y luego decrementa en uno


}
template <typename tipo,int cap>
int Pila<tipo,cap>::ObtenerTamanio () {
    return tope+1;
}
template <typename tipo,int cap>
const int Pila<tipo,cap>::ObtenerCapacidad () {
    return CAPACIDAD;
}
template <typename tipo,int cap>
bool Pila<tipo,cap>::EstaVacia () {
    return tope==-1;
}
template <typename tipo,int cap>
bool Pila<tipo,cap>::EstaLlena () {
    return tope==(CAPACIDAD -1);
}
template <typename tipo,int cap>
void Pila<tipo,cap>::VaciarPila ()
{
    tope = -1;
}


#endif //EGO_ESTRUCTURALIFO_PILA_H
