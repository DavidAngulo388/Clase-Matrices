#pragma once
#include <iostream>

class Matriz {
    friend std::ostream & operator<<(std::ostream & out, Matriz m);
    friend Matriz operator*(float escalar, Matriz m);

public:
  /* ---- CONSTRUCTORES ---- */
  explicit Matriz(int n = 2, int m = 2, float valor = 0); // Constructor por default
  ~Matriz();                    // Destructor
  Matriz(const Matriz &m);      // Constructor de Copias
  /*-------------------------*/

  /* ---- MÉTODOS DE LA CLASE ---- */
  void Imprimir() const;
  Matriz operator+(Matriz m) const;
  Matriz operator-(Matriz m) const;
  Matriz operator*(Matriz m) const;
  Matriz operator*(float escalar) const;
  Matriz &operator=(const Matriz &m);
  Matriz Transpuesta() const;

private:
  // Una matriz se representa con dimensiónes n*m
  unsigned int renglones; // n (vertical)
  unsigned int columnas;  // m  (horizontal)
  float **entradas;
};
