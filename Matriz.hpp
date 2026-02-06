#pragma once

class Matriz {
public:
  /* ---- CONSTRUCTORES ---- */

  // Constructor por default
  Matriz(int n = 2, int m = 2);

  // Constructor de copias

  // Destructor
  ~Matriz();

  /*-------------------------*/

  /* ---- MÉTODOS DE LA CLASE ---- */
  void Imprimir();

  /*-------------------------*/
private:
  // Una matriz se representa con dimensiónes n*m
  unsigned int renglones; // n (vertical)
  unsigned int columnas;  // m  (horizontal)
  float **entradas;
};
