#include <iostream>
#include "Pila.h"

#include <cmath>
//#include "Complejo.h"
using namespace std;


int main () {

    Pila<char>pilaChar ;


    try {
/*
        for ( int i = 1 ;!pilaChar.EstaLlena () ; ++i ) {
            pilaChar.AgregarElemento (char(i));
            std::cout << "Pila [ " << i << "] = " << pilaChar.ObtenerTope () << std::endl;
        }
*/

        //pilaChar.VaciarPila();
        //cout << pilaChar.ObtenerTope()<<endl;
/*
        pilaChar.AgregarElemento ('u');

        pilaChar.AgregarElemento ('p');
        pilaChar.AgregarElemento ('u');
        pilaChar.AgregarElemento ('t');

        while(!pilaChar.EstaVacia ()){
            cout<<pilaChar.EliminarElemento ();
        }
        cout<< endl;

        Pila <string> pilaString;

        pilaString.AgregarElemento ("anita");
        pilaString.AgregarElemento ("lava");
        pilaString.AgregarElemento ("la");
        pilaString.AgregarElemento ("tina");
        while(!pilaChar.EstaVacia ()){
            cout<<pilaString.EliminarElemento ();
        }
        cout<<endl;
*/


        Pila<Complejo *> pilaComplejoPtr;

        pilaComplejoPtr.AgregarElemento(new Complejo(9.5f,-6.8f));
        cout<<*pilaComplejoPtr.ObtenerTope()<<endl;


        Complejo *ptr;
        while(!pilaComplejoPtr.EstaVacia ()){
            ptr = pilaComplejoPtr.EliminarElemento ();
            delete ptr;
        }

        Pila<Complejo,10> pilaComplejo10;
        cout<< pilaComplejo10.ObtenerCapacidad ()<<endl;
        if(pilaComplejo10.EstaVacia ()) cout<<"Pila de complejos de tamaño 10 vacia"<<endl;

        pilaComplejo10.AgregarElemento (Complejo(10,3));

        cout << pilaComplejo10.ObtenerTope () << endl;


    }catch(Excepcion &exc){
            std::cout << exc.QuePaso()<<std::endl;
        }
    catch(...) {
        cout<< "Algun error ocurrio"<<endl;
    }
    //std::cout  <<"Pila [ " <<

    return 0;
}