#pragma once

class Matriz {
public:
  /* ---- CONSTRUCTORES ---- */
  Matriz(int n = 2, int m = 2); // Constructor por default
  ~Matriz();                    // Destructor
  Matriz(const Matriz &m);
  /*-------------------------*/

  /* ---- MÉTODOS DE LA CLASE ---- */
  void Imprimir() const;
  Matriz operator+(Matriz m);
  Matriz &operator=(const Matriz &m);

private:
  // Una matriz se representa con dimensiónes n*m
  unsigned int renglones; // n (vertical)
  unsigned int columnas;  // m  (horizontal)
  float **entradas;
};
