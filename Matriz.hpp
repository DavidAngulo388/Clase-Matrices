#pragma once

class Matriz {
public:
  /* ---- CONSTRUCTORES ---- */

  // Constructor por default
  Matriz();

  // Constructor de copias

  // Destructor
  ~Matriz();

private:
  // Una matriz se representa con dimensiónes n*m
  unsigned int n; // Cantidad de renglones (vertical)
  unsigned int m; // Cantidad de columnas (horizontal)
  float **entradas[];
};
