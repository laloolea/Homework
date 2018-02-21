#include <iostream>
#include <string>
//#include <cstdlib>
#include "Vector.h"
using namespace std;
void funcionImprimir(Vector v);
//Vector operator+ ( Vector v, Vector w);
int main() {

    int dim;

    Vector v(5,4),w(5,2),a(5);

    std::cout << "Programa que...\n";
    /*
    cout << "Vector 1: ";
    //v.Imprimir();
    funcionImprimir(v);

    cout<< endl;
    cout << "Vector 2: ";
    //w.Imprimir();
    funcionImprimir(w);
    cout<<endl;
    cout << "Vector 3: ";
    //a.Imprimir();

    funcionImprimir(5);
    */
    //cout<<"Ingrese dimensión del vector: ";
    //cin>> dim;
    //Vector v(dim);

    //cout << "Captura de vector.\n";
    //v.capturarEntradas();


    //cout<<"\nV=";
    //v.Imprimir();
   // a = z(w);// Llamada explicita interno a clase.

    //a.Imprimir();
    /*
    cout << endl;

    //a = v + w;
    a = operator+(v,w);// explicita operador externo a la clase.
    //a = v+w ; // llamada implicita externo a clase.

    a.Imprimir();

    //string al (v);
    cout << endl <<string(v);

    cout <<endl<< a << endl;

    cin >> v;

    cout << v  << endl;
    */

    //v[0]=8;

    cout<< v<<endl;


    cout << v*3.2<<endl ;

    cout <<3.3*v<<endl;

    cout <<v<<endl;


    /*
    for(int i = 0 ; i < v.Obtenerdim(); ++ i ) {
        //v[i] = i + 1;
        cout << v[i];
    }
    */
    return 0;
}

void funcionImprimir(Vector v)
{
    v.Imprimir();
}

/*
Vector operator+ ( Vector v, Vector w)
{
    Vector s(v.Obtenerdim());

    for(int i = 0 ; i < v.Obtenerdim();++i){
        //s.AgregarEntrada(i,(v.ObtenerEntrada(i)+w.ObtenerEntrada(i)));
        s.entrada[i] = v.entrada[i] + w.entrada[i];
    }
    return s;
}
 */