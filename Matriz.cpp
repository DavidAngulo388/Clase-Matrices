#include "Matriz.hpp"
#include <iostream>
#include <new>

using std::cout;
// using std::cin;
using std::endl;

/* ---- CONSTRUCTORES ---- */

// Constructor por default

// Constructor
Matriz::Matriz(int n, int m, float valor) {
  if (n <= 0 || m <= 0) {
    throw "Dimensi\162n inv\160lida";
  }

  renglones = n;
  columnas = m;

  // El puntero que apunta a punteros, esta apuntando a un bloque de memoria
  // de longitud 'renglones' tipo float
  try {

    entradas = new float *[renglones];
    for (int i = 0; i < renglones; ++i) {
      // A cada entrada, le asiga un bloque de memoria de longitud 'columnas'
      entradas[i] = new float[columnas];
    }

  } catch (std::bad_alloc &) {
    throw "Error en la asigaci\162n de memoria";
  }

  // Llenamos la matriz de puros ceros (menos batalla que dar la identidad).
  for (int i = 0; i < renglones; ++i) {
    for (int j = 0; j < columnas; ++j) {
      entradas[i][j] = valor;
    }
  }
}

// Constructor de copias
// TODO: Constructor de copias, pues Matriz A = B, será un caos.

Matriz::Matriz(const Matriz &v) : renglones(0), columnas(0), entradas(nullptr) {
  *this = v;
}
// Destructor
Matriz::~Matriz() {
  for (int i = 0; i < renglones; ++i) {
    delete[] entradas[i];
  }
  delete[] entradas;
}

Matriz &Matriz::operator=(const Matriz &m) {
  if (this == &m)
    return *this;

  // Primero borramos todo el objeto
  for (int i = 0; i < renglones; ++i) {
    delete[] entradas[i];
  }
  delete[] entradas;

  // Empezamos a copiar todo el objeto:
  renglones = m.renglones;
  columnas = m.columnas;

  // Volvemos a pedir memoria
  try {
    entradas = new float *[renglones];
    for (int i = 0; i < renglones; ++i) {
      entradas[i] = new float[columnas];
    }

    for (int i = 0; i < renglones; ++i) {
      for (int j = 0; j < columnas; ++j) {
        entradas[i][j] = m.entradas[i][j];
      }
    }

  } catch (std::bad_alloc &) {
    throw "Error en la asignaci\242n de memoria.";
  }

  return *this;
}

/* -------------------------------------------------- */
Matriz Matriz::operator+(Matriz m) const{
  if (renglones != m.renglones || columnas != m.columnas) {
    throw "Error: Operaci\162n fallida. Dimensiones distintas.";
  }

  Matriz matriz_suma(renglones, columnas);
  for (int i = 0; i < matriz_suma.renglones; ++i) {
    for (int j = 0; j < matriz_suma.columnas; ++j) {
      matriz_suma.entradas[i][j] = entradas[i][j] + m.entradas[i][j];
    }
  }

  return matriz_suma;
}

/* -------------------------------------------------- */
Matriz Matriz::operator-(Matriz m) const{
  if (renglones != m.renglones || columnas != m.columnas) {
    throw "Error: Operaci\162n fallida. Dimensiones distintas.";
  }

  Matriz matriz_resta(renglones, columnas);
  for (int i = 0; i < matriz_resta.renglones; ++i) {
    for (int j = 0; j < matriz_resta.columnas; ++j) {
      matriz_resta.entradas[i][j] = entradas[i][j] - m.entradas[i][j];
    }
  }

  return matriz_resta;
}

/* -------------------------------------------------- */
Matriz Matriz::operator*(Matriz m) const{
  if (columnas != m.renglones) {
    throw "Error: Operaci\162n fallida. Dimensiones distintas.";
  }

  Matriz matriz_mult(renglones, m.columnas);
  for(int i = 0; i < renglones; ++i){
    for(int j = 0; j < m.columnas; ++j){
      for(int k = 0; k < columnas; ++k){
          matriz_mult.entradas[i][j] += entradas[i][k] * m.entradas[k][j];
      }
    }
  }
  return matriz_mult;
}

/* -------------------------------------------------- */
Matriz Matriz::operator*(float escalar) const{
    Matriz matriz_escalar(renglones, columnas);
    for(int i = 0; i < matriz_escalar.renglones; ++i){
        for(int j = 0; j < matriz_escalar.columnas; ++j){
            matriz_escalar.entradas[i][j] = escalar * entradas[i][j];
        }
    }
    return matriz_escalar;
}

/* -------------------------------------------------- */
Matriz Matriz::Transpuesta() const{
    Matriz matriz_trans(columnas, renglones);
    for(int i = 0; i < renglones; ++i){
        for(int j = 0; j < columnas; ++j){
            matriz_trans.entradas[j][i] = entradas[i][j];
        }
    }
    return matriz_trans;
}

/* ----FUNCIONES AMIGAS--- */
Matriz operator*(float escalar, Matriz m){
    Matriz matriz_escalar(m.renglones, m.columnas);
    for(int i = 0; i < matriz_escalar.renglones; ++i){
        for(int j = 0; j < matriz_escalar.columnas; ++j){
            matriz_escalar.entradas[i][j] = escalar * m.entradas[i][j];
        }
    }
    return matriz_escalar;
}

/* ----FUNCIONES OPERADORAS AMIGAS--- */
std::ostream & operator<<(std::ostream & out, Matriz m){
    out << endl;
    for(int i = 0; i < m.renglones; ++i){
        for(int j = 0; j < m.columnas; ++j){
            out << m.entradas[i][j] << " ";
        }
        out << endl;
    }
    out << "\b";
    return out;
}

