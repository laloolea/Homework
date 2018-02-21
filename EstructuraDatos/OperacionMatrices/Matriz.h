//
// Created by Eduardo Gonzalez Olea on 2/10/18.
//

#ifndef OPERACIONMATRICES_MATRIZ_H
#define OPERACIONMATRICES_MATRIZ_H
#include <string>
class Matriz {
    friend std::ostream & operator<< (std::ostream & o, const Matriz &v);

public:
    Matriz();
    Matriz(int m,int n,double **entrada);
    Matriz(const Matriz &m);

    template <typename T>
    void CapturaNum(const char mensage[100], T &num);


private:
    int m;
    int n;
    double ** CreaMatriz();
    void DestruyeMatriz(float **& Mat, int m);
    double **entrada;

};


#endif //OPERACIONMATRICES_MATRIZ_H
