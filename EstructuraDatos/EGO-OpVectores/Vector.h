#ifndef VECTOR_H
#define VECTOR_H
#define MAX_DIM 100
#include <string>// Para tipo string (cadena de caracteres a estilo c++)
#include <iostream>
class Vector
{
    friend Vector operator+ ( Vector v, Vector w);
    friend std::ostream& operator<<(std::ostream &salida, Vector v);
    friend std::istream& operator >> (std::istream &entrada,Vector &v);
    friend Vector operator*(double escalar,Vector v) ;
public:
    //Default constructor
    explicit Vector(int _dim);
    Vector(int _dim, double _valor );
    Vector();
    int Obtenerdim();
    void Imprimir();
    //double capturarEntradas();
    //Vector operator +(Vector v);
    void AgregarEntrada(int n,double valor);
    double ObtenerEntrada(int i);
    /**Operador de conversión
     *
     */
    operator std::string();
    double &  operator[] (int i);
    const double  operator[](int i) const;
    Vector operator*(double escalar);

protected:
private:
    int dim;
    double entrada[MAX_DIM];
};

#endif // VECTOR_H
