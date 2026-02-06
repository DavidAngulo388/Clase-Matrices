#include "Matriz.hpp"
#include <iostream>
#include <new>

using std::cout;
// using std::cin;
using std::endl;

/* ---- CONSTRUCTORES ---- */

// Constructor por default

// Constructor
Matriz::Matriz(int n, int m) {
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
      entradas[i][j] = 0;
    }
  }
}

// Constructor de copias
// TODO: Constructor de copias, pues Matriz A = B, será un caos.

// Destructor
Matriz::~Matriz() {
  for (int i = 0; i < renglones; ++i) {
    delete[] entradas[i];
  }
  delete[] entradas;
}

void Matriz::Imprimir() {
  for (int i = 0; i < renglones; ++i) {
    for (int j = 0; j < columnas; ++j) {
      cout << entradas[i][j] << " ";
    }
    cout << endl;
  }
}
