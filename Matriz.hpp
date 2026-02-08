#pragma once
#include <iostream>

class Matriz
{
    friend std::ostream &operator<<(std::ostream &out, Matriz m);
    friend Matriz operator*(float escalar, Matriz m);
    friend std::istream &operator>>(std::istream &entrada, Matriz &m);

  public:
    /* ---- CONSTRUCTORES ---- */
    explicit Matriz(int n = 2, int m = 2,
                    float valor = 0); // Constructor por default
    ~Matriz();                        // Destructor
    Matriz(const Matriz &m);          // Constructor de Copias
    /*-------------------------*/

    /* ---- MÉTODOS DE LA CLASE ---- */
    void Imprimir() const;
    Matriz operator+(Matriz m) const;
    Matriz operator-(Matriz m) const;
    Matriz operator*(Matriz m) const;
    Matriz operator*(float escalar) const;
    Matriz &operator=(const Matriz &m);
    Matriz Transpuesta() const;

    // TODO: Evitar que se salga de rango en COLUMNAS
    float *operator[](int i);             // Para cambiar un dato
    const float *operator[](int i) const; // Para leer un dato

  private:
    // Una matriz se representa con dimensiónes n*m
    unsigned int renglones; // n (vertical)
    unsigned int columnas;  // m  (horizontal)
    float **entrada;

    // Métodos de utilidad para escalonar
    Matriz mat_aumentada() const;
    void intercambiar_renglones(int a, int b);
    void renglon_escalar();
    void sumar_renglones();
};
