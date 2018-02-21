//
// Created by Eduardo Gonzalez Olea on 2/10/18.
//

#include "Matriz.h"
#include <iostream>
#include <limits>
#include <iomanip>
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


double **Matriz::CreaMatriz () {
    double **Mat = new (std::nothrow) double*[m];


    if(Mat == NULL) return Mat;

    for(int i = 0; i < m; i++) {
        entrada[i] = new (std::nothrow) float[n];
        if(entrada[i] == NULL){
            DestruyeMatriz();
            break;
        }
    }

    return Mat;

}

void Matriz::DestruyeMatriz (float **&Mat , int m) {
    for(int i = 0; i < m; ++i) delete [] Mat[i];
    delete [] Mat;
    Mat = NULL;
}

template<typename T>
void Matriz::CapturaNum (const char *mensage , T &num)
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

std::ostream &operator<< (std::ostream &o , const Matriz &m) {
    for(int i = 0; i < m.m; i++) {
        for ( int j = 0 ; j < m.n ; j++ )
            o << setw (12) << m[ i ][ j ] << " ";
        o << endl;
    }
    return o;
}



