//
// Created by Eduardo Gonzalez Olea on 2/10/18.
//

#include "Matriz.h"
#include <iostream>
#include <limits>
#include <iomanip>
//#include <fstream>
#include <sstream>
using namespace std;


Matriz::Matriz () :m(1),n(1),entrada(NULL) {}


Matriz::Matriz (int _m , int _n , double valor)
{
    m = _m;
    n = _n;
    entrada= CreaMatriz ();
    for(int i=0; i<m; ++i){
        for(int j=0;j<n;++j){
            entrada[i][j]= valor;
        }
    }
}
Matriz::Matriz (const Matriz &m)
{
    *this=  m;
}


Matriz::~Matriz () {
    DestruyeMatriz();
}


void Matriz::DestruyeMatriz () {
    for(int i = 0; i < m; ++i)
        delete [] entrada[i];
    delete [] entrada;
    entrada = NULL;
}

//template<typename T>
void Matriz::CapturaNum (const char *mensage , double &num)
{
    while(true){
        std::cout << mensage;
        std::cin >> num;

        if(std::cin.bad()) throw "Ha ocurrido un error fatal en el flujo de entrada, el programa ha terminado";

        if(std::cin.fail()){
            std::cout << "\n\nError: el tipo de dato proporcionado no corresponde con el tipo de dato solicitado" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        return;
    }
}

std::ostream &operator<< (std::ostream &o , const Matriz &m)
{

    for(int i = 0; i < m.m; i++) {
        for ( int j = 0 ; j < m.n ; j++ )
            o <<m.entrada[ i ][ j ] << " ";
        o << endl;
    }
    return o;

}


double **Matriz::CreaMatriz () {
    entrada = new (std::nothrow) double*[m];


   // if(Mat == NULL) return Mat;

    for(int i = 0; i < m; i++) {
        entrada[i] = new (std::nothrow) double[n];
        if(entrada[i] == NULL){
            DestruyeMatriz();
            break;
        }
    }

    return entrada;
}

std::istream &operator>> (std::istream &entrada , Matriz &w) {
    for(int i = 0; i < w.m; i++) {
        for(int j = 0; j < w.n; j++) {
            ostringstream mensajeCaptura;
            mensajeCaptura << "\nIngrese el componente [" << i+1 << ", " << j+1 << "]: ";
            w.CapturaNum(mensajeCaptura.str().c_str(), w.entrada[i][j]);
        }
    }
    return entrada;
}

Matriz Matriz::operator+ (const Matriz &A) const {
    //float **C = CreaMatriz();
    Matriz s(A.m,A.n,0);
    if(m != A.m || n != A.n) throw Excepcion("Tamaños incompatibles. El programa se cerrara");
    //if(s==NULL) return s;

    for(int i=0; i<A.m; ++i){
        for(int j=0;j<n;++j){
            s.entrada[i][j]= entrada[i][j]+A.entrada[i][j];
        }
    }
    return s;

}


Matriz Matriz::operator- (const Matriz &A) const {
    //float **C = CreaMatriz();
    Matriz r(A.m,A.m,0);

    if(m != A.m || n != A.n) throw Excepcion("Tamaños incompatibles. El programa se cerrara");
    //if(s==NULL) return s;

    for(int i=0; i<A.m; ++i){
        for(int j=0;j<n;++j){
            r.entrada[i][j]= entrada[i][j]-A.entrada[i][j];
        }
    }
    return r;

}

Matriz Matriz::operator* (double escalar) const
{
    Matriz p(m,n,0);

    //if(s==NULL) return s;

    for(int i=0; i<m; ++i){
        for(int j=0;j<n;++j){
            p.entrada[i][j]= entrada[i][j]*escalar;
        }
    }
    return p;
}

Matriz Matriz::operator* (const Matriz &b) const
{
        if(n!=b.m) throw Excepcion("Matrices incompatibles. El progrmaa se cerrara");

            Matriz p (m , b.n , 0);


            for ( int i = 0 ; i < m ; i++ ) {
                for ( int j = 0 ; j < b.n ; j++ ) {
                    //p.entrada[ i ][ j ] = 0;
                    for ( int k = 0 ; k < n ; k++ ) {
                        p.entrada[ i ][ j ] += entrada[ i ][ k ] * b.entrada[ k ][ j ];
                    }
                }
            }

        return p;

}

Matriz operator* (double escalar , const Matriz &v)  {
    return v * escalar;
}

Matriz Matriz::Transpuesta () const
{
    Matriz T(n,m,0);
    for(int i=0; i<n; ++i){
        for(int j=0;j<m;++j){
            T.entrada[i][j]= entrada[j][i];
        }
    }
    return T;
}


Matriz &Matriz::operator= (const Matriz &w) {
    if(this == &w) {
        return *this;
    }else {

        DestruyeMatriz ();

        m = w.m;
        n = w.n;

        entrada = CreaMatriz ();

        for ( int i = 0 ; i < w.m ; ++i ) {
            for ( int j = 0 ; j < w.n ; ++j ) {
                entrada[ i ][ j ] = w.entrada[ i ][ j ];
            }
        }
    }
    return *this;

}

double Matriz::operator() (int m , int n) const{

    return entrada[m][n];
}
