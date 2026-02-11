/**
 * \file  CapturaSegura.hpp
 * Se encuentra la definici&oacute;n de la CapturaSegura().
 * \author Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 10/02/2026

    \code {.cpp}
template <typename Tipo>
void CapturaSegura(Tipo &n, const char texto[]);
 \endcode
 */
#ifndef CAPTURASEGURA_HPP_INCLUDED
#define CAPTURASEGURA_HPP_INCLUDED

template <typename Tipo>
/** \brief
 *
 * \param n Tipo&
 * \param texto[] const char
 * \return void
 *
 */
void CapturaSegura(Tipo &n, const char texto[]);

#include "CapturaSegura.tpp"

#endif // CAPTURASEGURA_HPP_INCLUDED
