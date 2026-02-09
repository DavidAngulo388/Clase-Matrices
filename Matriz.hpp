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

    // TODO: De quedar tiempo, mejorar la impresión (en general, muy fea :( )
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
    Matriz Inversa() const;
    float Determinante() const;

    void EstablecerRenglones(int n);
    void EstablecerColumnas(int n);
    void Redimensionar(int n, int m);

  private:
    // Una matriz se representa con dimensiónes n*m
    unsigned int renglones; // n (vertical)
    unsigned int columnas;  // m  (horizontal)
    float **entrada;

    // Métodos de utilidad para escalonar
    void intercambiar_renglones(int a, int b);
    void renglon_escalar(int ren, float n);
    void sumar_renglones(int ren1, int ren2, float n = 1);
};
