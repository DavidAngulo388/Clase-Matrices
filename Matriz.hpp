/** \file Matriz.hpp
 *  En este archivo se encuentran las declaraciones de los m&eacute;todos y los atributos de la clase Matriz.
 *
 * \authors
        Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 10/02/2026

 \code {.cpp}

    class Matriz
{
    friend std::ostream &operator<<(std::ostream &out, const Matriz &mat);
    friend Matriz operator*(float escalar, Matriz m);
    friend std::istream &operator>>(std::istream &entrada, Matriz &m);

  public:
    explicit Matriz(int n = 2, int m = 2, float valor = 0);
    ~Matriz();
    Matriz(const Matriz &m);
    void Imprimir() const;
    Matriz operator+(Matriz m) const;
    Matriz operator-(Matriz m) const;
    Matriz operator*(Matriz m) const;
    Matriz operator*(float escalar) const;
    Matriz &operator=(const Matriz &m);
    Matriz Transpuesta() const;
    float *operator[](int i);
    const float *operator[](int i) const;
    Matriz Inversa() const;
    float Determinante() const;
    void Redimensionar(int n, int m);

    int ObtenerRenglones();
    int ObtenerColumnas();

  private:

    int renglones;
    int columnas;
    float **entrada;

    void intercambiar_renglones(int a, int b);
    void renglon_escalar(int ren, float n);
    void sumar_renglones(int ren1, int ren2, float n = 1);
};

 \endcode
 */
#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

/** \brief Enumeraci&oacute;n que almacena los c&oacute;digos ASCII de los simbolos para el dibujado de matrices
 */
enum {  ESI = 218, /// Esquina superior izquierda
        BARRA = 196, /// Barra horizontal
        ESD = 191, /// Esquina superior derecha
        BARRA_V = 179, /// Barra vertical
        EII = 192, /// Esquina inferior izquierda
        EID = 217 /// Esquina inferior derecha
        };


/** \brief Clase para crear, operar y manejar matrices
 */
class Matriz
{
    /**
     * \brief Funci&oacute;n friend para la impresi&oacute;n de matrices mediante la sobrecarga del operador '<<'
     *
     * \param out Par&aacute;metro ostream
     * \param mat Matriz a imprimir
     * \return friend std::ostream& Matriz a imprimir
     *
     */
    friend std::ostream &operator<<(std::ostream &out, const Matriz &mat);
    /** \brief Funci&oacute;n friend para la multiplicaci&oacute;n de un n&uacute;mero escalar con una matriz, pudiendo ser invocado como 'escalar*m'
     *
     * \param escalar N&uacute;mero escalar
     * \param m Matriz a escalar
     * \return friend Matriz Matriz escalada
     *
     */
    friend Matriz operator*(float escalar, Matriz m);

    /** \brief Funci&oacute;n friend para la lectura de matrices mediante la sobrecarga del operador '>>'
     *
     * \param entrada Par&aacute;metro istream
     * \param m Matriz a leer
     * \return friend std::istream& Matriz leída
     *
     */
    friend std::istream &operator>>(std::istream &entrada, Matriz &m);

  public:
    /* ---- CONSTRUCTORES ---- */

    /** \brief Constructor por default
     *
     * \param n N&uacute;mero de renglones
     * \param m N&uacute;mero de columnas
     * \param valor Valor con el que se rellenar&aacute; la matriz
     * \return Nada
     *
     */
    explicit Matriz(int n = 2, int m = 2,
                    float valor = 0); // Constructor por default

    /** \brief Destructor de la funci&oacute;n
     *
     *
     */
    ~Matriz();                        // Destructor

    /** \brief Constructor de copias
     *
     * \param m Matriz copiada
     *
     */
    Matriz(const Matriz &m);          // Constructor de Copias
    /*-------------------------*/

    /* ---- MÉTODOS DE LA CLASE ---- */

    // TODO: De quedar tiempo, mejorar la impresión (en general, muy fea :( )
    /** \brief Funci&oacute;n para la impresi&oacute;n de la matriz sin invocar cout en main
     *
     * \return Nada
     *
     */
    void Imprimir() const;

    /** \brief Funci&oacute;n que suma 2 matrices mediante la sobrecarga del operador '+'
     *
     * \param m Matriz sumando
     * \return Matriz resultado
     *
     */
    Matriz operator+(Matriz m) const;

    /** \brief Funci&oacute;n que resta 2 matrices mediante la sobrecarga del operador '-'
     *
     * \param m Matriz sustraendo
     * \return Matriz resultado
     *
     */
    Matriz operator-(Matriz m) const;

    /** \brief Funci&oacute;n que m&uacute;ltiplica 2 matrices mediante la sobrecarga del operador '*'
     *
     * \param m Matriz
     * \return Matriz
     *
     */
    Matriz operator*(Matriz m) const;

    /** \brief Funci&oacute;n para la multiplicaci&oacute;n de una matriz con un n&uacute;mero escalar, pudiendo ser invocado como 'm*escalar'
     *
     * \param escalar N&uacute;mero escalar
     * \param m Matriz a escalar
     * \return Matriz escalada
     *
     */
    Matriz operator*(float escalar) const;

    /** \brief Funci&oacute;n que copia los contenidos de una matriz en otra mediante la sobrecarga del operador '='
     *
     * \param m Matriz a copiar
     * \return Copia de la matriz m
     *
     */
    Matriz &operator=(const Matriz &m);

    /** \brief Funci&oacute;n que saca la transpuesta de una matriz
     *
     * \return Matriz transpuesta
     *
     */
    Matriz Transpuesta() const;


    /** \brief Funci&oacute;n para encontrar los elementos de una matriz de una manera pr&aacute;ctica de la forma m[i][j]
     *
     * \param i Rengl&oacute;n/Columna en el cual se encuentra el valor que buscamos
     * \return Valor en el elemento de la matriz
     *
     */
    float *operator[](int i);             // Para cambiar un dato

    /** \brief Funci&oacute;n para encontrar los elementos de una matriz de una manera pr&aacute;ctica de la forma m[i][j], exclusivo para matrices constantes
     *
     * \param i Rengl&oacute;n/Columna en el cual se encuentra el valor que buscamos
     * \return Valor en el elemento de la matriz
     *
     */
    const float *operator[](int i) const; // Para leer un dato

    /** \brief Funci&oacute;n que calcula la inversa de una matriz
     *
     * \return Matriz inversa
     *
     */
    Matriz Inversa() const;

    /** \brief Funci&oacute;n que calcula el determinante de una matriz
     *
     * \return Determinante de la matriz
     *
     */
    float Determinante() const;

    /** \brief Funci&oacute;n que redimensiona la matriz
     *
     * \param n Nueva dimensi&oacute;n de los renglones
     * \param m Nueva dimensi&oacute;n de las columnas
     * \return Nada
     *
     */
    void Redimensionar(int n, int m);

    /** \brief Funci&oacute;n que le permite a funciones fuera de la clase conocer el n&uacute;mero de renglones
     *
     * \return N&uacute;mero de renglones
     *
     */
    int ObtenerRenglones();

    /** \brief Funci&oacute;n que le permite a funciones fuera de la clase conocer el n&uacute;mero de columnas
     *
     * \return N&uacute;mero de columnas
     *
     */
    int ObtenerColumnas();

  private:
    // Una matriz se representa con dimensiónes n*m
    int renglones; // n (vertical)
    int columnas;  // m  (horizontal)
    float **entrada;

    // Métodos de utilidad para escalonar
    /** \brief Funci&oacute;n que permite intercambiar los renglones de una matriz para el proceso del calculo de la determinante
     *
     * \param a Rengl&oacute;n 1
     * \param b Rengl&oacute;n 2
     * \return Nada
     *
     */
    void intercambiar_renglones(int a, int b);

    /** \brief Funci&oacute;n que permite escalar renglones por separados, usada para la funci&oacute;n del determinante
     *
     * \param ren Rengl&oacute;n a escalar
     * \param n N&uacute;mero escalar
     * \return Nada
     *
     */
    void renglon_escalar(int ren, float n);

    /** \brief Funci&oacute;n que permite sumar renglones, usada para la funci&oacute;n del determinante
     *
     * \param ren1 Rengl&oacute;n 1
     * \param ren2 Rengl&oacute;n 2
     * \param n Valor que multiplicara al rengl&oacute;n 1 antes de sumarlo
     * \return Nada
     *
     */
    void sumar_renglones(int ren1, int ren2, float n = 1);
};

#endif // UTILERIA_HPP_INCLUDED
