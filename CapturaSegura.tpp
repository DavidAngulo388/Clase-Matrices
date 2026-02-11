/** \file CapturaSegura.tpp
 *  En este archivo se encuentran la implementaci&oacute;n de la funcion CapturaSegura().
 *
 * \authors
        Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 10/02/2026

 \code {.cpp}

using std::cin;
using std::cout;

template <typename Tipo>

void CapturaSegura(Tipo &n, const char texto[])
{
    cout << texto;
    cin >> n;
    while(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');

        cout << texto;
        cin >> n;
    }

}

 \endcode
 */
#include <iostream>
#include <limits>

using std::cin;
using std::cout;

template <typename Tipo>

void CapturaSegura(Tipo &n, const char texto[])
{
    cout << texto;
    cin >> n;
    while(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');

        cout << texto;
        cin >> n;
    }

}
