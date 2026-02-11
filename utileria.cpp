/** \file utileria.cpp
 *  En este archivo se encuentra la implementacion de una &uacute;nica funcion llamada ImprimirMatrices()
 *
 * \authors
        Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 10/02/2026

 \code {.cpp}

void ImprimirMatrices(Matriz A, Matriz B){

    system("cls");
    cout << "[ Matriz A] : ";
    cout << endl << A << endl;

    cout << "[ Matriz B ]: ";
    cout << endl << B << endl;
}


 \endcode
 */
#include <iostream>
#include "utileria.hpp"
#include "Matriz.hpp"

using std::cout;
using std::endl;

void ImprimirMatrices(Matriz A, Matriz B){

    system("cls");
    cout << "[ Matriz A] : ";
    cout << endl << A << endl;

    cout << "[ Matriz B ]: ";
    cout << endl << B << endl;
}
