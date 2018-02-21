//
// Created by Eduardo Gonzalez Olea on 2/10/18.
//

#ifndef OPERACIONMATRICES_MATRIZ_H
#define OPERACIONMATRICES_MATRIZ_H
#include <string>
#include "Excepciones.h"

class Matriz {
    /** \brief  sobrecarga de operador << para imprimir una matriz
 *
 * \param ostream o donde se almacenara la cadena
 * \param Matriz v matriz a imprimir
 * \return devuelve una variable de tipo ostream que contiene a la matriz
 *
 */
    friend std::ostream & operator<< (std::ostream & o, const Matriz &v);
    /** \brief  sobrecarga de operador >> para capturar una matriz
    *
    * \param istream entrada en la cual se almacena las entradas de la matriz
    * \param Matriz v matriz a capturar
    * \return devuelve una variable de tipo istream
    *
    */
    friend std::istream & operator>> (std::istream & entrada, Matriz &w);
    /** \brief sobrecarga del operador * para la multiplicaci&oacute;n por un escalar conmutativa
     *
     * \param double escalar el escalar por el cual se multiplicara la matriz
     * \param Matriz v Matriz a multiplicar
     * \return la matriz operada
     *
     */
    friend Matriz operator*(double escalar, const Matriz &v);
public:
    /** \brief Constructor de la clase Matriz
     * \return La matriz
 */
    Matriz();
    /** \brief Constructor explicito de la clase Matriz
 *
 * \param int m n&uacute;mero de renglones de la matriz
 * \param int n n&uacute;mero de columnas de la matriz
 * \return La Matriz
 *
 */
    explicit Matriz(int m,int n,double valor);
    /** \brief Constructor de copias
 *
 * \param una referencia constante de la matriz a copiar
 * \return la matriz nueva con el contenido copiado
 *
 */
    Matriz(const Matriz &m);
    /** \brief destructor de la clase Matriz manda a llamar la funci&oacute;n DestruyeMatriz
     */
    ~Matriz();


    /** \brief Funci&oacute;n que sirve para capturar un dato tipo double
    *
    * \param const char mensage[100] Mensaje para pedir el dato
    * \param double & num referencia a un double
    */
    void CapturaNum(const char mensage[100], double &num);
   // double & operator[][](int i,int j);
    //const double &operator[][](int i, int j) const;
    /** \brief Sobrecarga operador +  para sumar matrices
     *
     * \param const Matriz &w una referencia constante de una matriz
     * \return La matriz de la suma
     *
     */
    Matriz operator+(const Matriz &w) const;
    /** \brief Sobrecarga operador -  para restar matrices
      *
      * \param const Matriz &w una referencia constante de una matriz
      * \return La matriz de la resta
      *
      */
    Matriz operator-(const Matriz &w) const;
    /** \brief Sobrecarga operador *  para multiplicar matrices por un escalar
     *
     * \param  double escalar el escalar por la cual multiplicara la matriz
     * \return La matriz multiplicada
     *
     */
    Matriz operator*(double escalar) const;
     /** \brief Sobrecarga operador *  para multiplicar matrices
     *
     * \param const Matriz &w una referencia constante de una matriz
     * \return La matriz multiplicada
     */
    Matriz operator*(const Matriz &b)const;
    /** \brief Funci&oacute;n para calcular la transpuesta de una matriz
     *
     * \return La matriz  transpuesta
     *
     */
    Matriz Transpuesta() const ;
    /** \brief Sobrecarga operador =  para igualar matrices
     *
     * \param const Matriz &w una referencia constante de una matriz
     * \return La matriz devuelve la matriz por la que se igualo
     *
     */
    Matriz &operator=(const  Matriz &w);

    double  operator()(int m,int n) const;


private:
    int m;
    int n;
    /** \brief Funci&oacute;n para crear una matriz
     *
     * \return Un puntero a puntero double
     *
     */
    double ** CreaMatriz();
    /** \brief Funci&oacute;n para liberar memoria de una matriz
     */
    void DestruyeMatriz();
    double **entrada;

};


#endif //OPERACIONMATRICES_MATRIZ_H
