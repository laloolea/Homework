#include "Vector.h"
#include <iostream>
#include <sstream>

using namespace std;

//si los atributos son constantes,un objeto de otra clase,o una referencia, tiene que ser inicializada con un inicializador
//
Vector::Vector(int _dim) : dim(_dim)
{
    //dim = _dim;

    for(int i=0;i < dim ; ++i){
        entrada [i] = 0;
    }

}
//***************************************

Vector::Vector() :dim(MAX_DIM)
{

    for(int i=0;i < dim ; ++i){
        entrada [i] = 0;
    }

}

Vector::Vector(int _dim,double _valor) :dim(_dim)
{

    for(int i=0;i < dim ; ++i){
        entrada [i] = _valor;
    }

}
//***************************************
int Vector::Obtenerdim()
{
    return dim;
}
//***************************************

void Vector::Imprimir()
{
    std::cout << "(";
    for(int i = 0 ;i <  dim ; ++i) std::cout << entrada[i] << ",";
    std::cout << "\b)";
}

//***************************************
/*

double Vector::capturarEntradas()
{

        for(int i = 0 ;i <  dim ; ++i) {
            std::cout << "Ingrese la entrada "<<(i+1) << "):";
            std::cin >> entrada[i];

        }
}
 */
//**************************************************
/*
Vector Vector::operator +(Vector v)
{
    Vector s(dim);
    for(int i = 0 ; i < dim ; ++i){
        s.entrada[i] = this->entrada[i] + v.entrada[i];
    }
    return s;
}
 */

void Vector::AgregarEntrada(int n, double valor) {
    entrada[n]=valor;
}

double Vector::ObtenerEntrada(int i) {
    return entrada[i];
}

Vector operator+ ( Vector v, Vector w)
{
    Vector s(v.dim);

    for(int i = 0 ; i < v.dim;++i){
       // s.AgregarEntrada(i,(v.ObtenerEntrada(i)+w.ObtenerEntrada(i)));
        s.entrada[i] = v.entrada[i] + w.entrada[i];
    }

    return s;
}
/*
Vector Vector::operator+(Vector v) {
    //return Vector();
}
*/
Vector::operator std::string()
{
    // Estilo cadenas de C
    /*har cadena[1024];
    sprintf(cadena, "%s","(");
    for (int i = 0 ; i < dim ; i++){
        sprintf(cadena,"%lf, ",entrada[i]);

    }
    sprintf(cadena,"\b\b)");
    return std::string(cadena);
     */


    std::stringstream s;
    s << "(";
    for(int i = 0 ; i < dim ; ++i){
        s<<entrada[i] << ",";
    }

    s<<"\b)";

    return s.str();


}

std::ostream& operator<<(std::ostream &salida, Vector v)
{
    salida << "(";
    for(int i = 0 ; i < v.dim ; ++i){
        salida << v.entrada[i] << ",";
    }
    salida << "\b)";
    return salida;
}

std::istream &operator>>(std::istream &entrada, Vector &v)
{
    for(int i = 0;i< v.dim ; ++i){
        cout << "Ingrese entrada No. "<<i+1<< ": ";
        entrada >>  v.entrada[i] ;
    }
    return entrada;
}

double &Vector::operator[](int i)
{
    return entrada[i];
}

const double Vector::operator[](int i) const {
    return entrada[i];
}

Vector Vector::operator*(double escalar) {
    Vector v(dim);
    for(int i = 0 ; i < dim ; ++i){
        v.entrada[i] = entrada[i] * escalar;
     }
    return v;
}

Vector operator*(double escalar, Vector v) {
    //Vector v(v.Obtenerdim());
    /*
    for(int i = 0 ; i < v.Obtenerdim() ; ++i){
       v.entrada[i] = v.entrada[i] * escalar;
    }
    return v;
    */
    return v*escalar;


}



