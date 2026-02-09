#include "Matriz.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

using std::abs;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;

/* ---- CONSTRUCTORES ---- */

// Constructor
// TODO: Posible fallo en asigación de memoria y que se pierda todo.
Matriz::Matriz(int n, int m, float valor)
{
    if (n <= 0 || m <= 0) {
        throw "Dimensi\162n inv\160lida";
    }

    renglones = n;
    columnas = m;

    // El puntero que apunta a punteros, esta apuntando a un bloque de memoria
    // de longitud 'renglones' tipo float
    try {

        entrada = new float *[renglones];
        for (int i = 0; i < renglones; ++i) {
            // A cada entrada, le asiga un bloque de memoria de longitud
            // 'columnas'
            entrada[i] = new float[columnas];
        }

    } catch (std::bad_alloc &) {
        throw "Error en la asigaci\162n de memoria";
    }

    // Llenamos la matriz de puros ceros (menos batalla que dar la identidad).
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            entrada[i][j] = valor;
        }
    }
}

// Constructor de copias
Matriz::Matriz(const Matriz &v) : renglones(0), columnas(0), entrada(nullptr)
{
    *this = v;
}
// Destructor
Matriz::~Matriz()
{
    for (int i = 0; i < renglones; ++i) {
        delete[] entrada[i];
    }
    delete[] entrada;
}
// Operador de asigación
Matriz &Matriz::operator=(const Matriz &m)
{
    if (this == &m)
        return *this;

    // Primero borramos todo el objeto
    for (int i = 0; i < renglones; ++i) {
        delete[] entrada[i];
    }
    delete[] entrada;

    // Empezamos a copiar todo el objeto:
    renglones = m.renglones;
    columnas = m.columnas;

    // Volvemos a pedir memoria
    try {
        entrada = new float *[renglones];
        for (int i = 0; i < renglones; ++i) {
            entrada[i] = new float[columnas];
        }

        for (int i = 0; i < renglones; ++i) {
            for (int j = 0; j < columnas; ++j) {
                entrada[i][j] = m.entrada[i][j];
            }
        }

    } catch (std::bad_alloc &) {
        throw "Error en la asignaci\242n de memoria.";
    }

    return *this;
}

/* -------------------------------------------------- */
Matriz Matriz::operator+(Matriz m) const
{
    if (renglones != m.renglones || columnas != m.columnas) {
        throw "Error: Operaci\162n fallida. Dimensiones distintas.";
    }

    Matriz matriz_suma(renglones, columnas);
    for (int i = 0; i < matriz_suma.renglones; ++i) {
        for (int j = 0; j < matriz_suma.columnas; ++j) {
            matriz_suma.entrada[i][j] = entrada[i][j] + m.entrada[i][j];
        }
    }

    return matriz_suma;
}

/* -------------------------------------------------- */
Matriz Matriz::operator-(Matriz m) const
{
    if (renglones != m.renglones || columnas != m.columnas) {
        throw "Error: Operaci\162n fallida. Dimensiones distintas.";
    }

    Matriz matriz_resta(renglones, columnas);
    for (int i = 0; i < matriz_resta.renglones; ++i) {
        for (int j = 0; j < matriz_resta.columnas; ++j) {
            matriz_resta.entrada[i][j] = entrada[i][j] - m.entrada[i][j];
        }
    }

    return matriz_resta;
}

/* -------------------------------------------------- */
Matriz Matriz::operator*(Matriz m) const
{
    if (columnas != m.renglones) {
        throw "Error: Operaci\162n fallida. Dimensiones distintas.";
    }

    Matriz matriz_mult(renglones, m.columnas);
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            for (int k = 0; k < columnas; ++k) {
                matriz_mult.entrada[i][j] += entrada[i][k] * m.entrada[k][j];
            }
        }
    }
    return matriz_mult;
}

/* -------------------------------------------------- */
Matriz Matriz::operator*(float escalar) const
{
    Matriz matriz_escalar(renglones, columnas);
    for (int i = 0; i < matriz_escalar.renglones; ++i) {
        for (int j = 0; j < matriz_escalar.columnas; ++j) {
            matriz_escalar.entrada[i][j] = escalar * entrada[i][j];
        }
    }
    return matriz_escalar;
}

/* -------------------------------------------------- */
Matriz Matriz::Transpuesta() const
{
    Matriz matriz_trans(columnas, renglones);
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz_trans.entrada[j][i] = entrada[i][j];
        }
    }
    return matriz_trans;
}

/* -------------------------------------------------- */
float *Matriz::operator[](int i)
{
    if (i < 0 || i > renglones) {
        throw "Indice de rengln fuera de rango.";
    }
    return entrada[i];
}

/* -------------------------------------------------- */
const float *Matriz::operator[](int i) const
{
    if (i < 0 || i > renglones) {
        throw "Indice de rengln fuera de rango.";
    }
    return entrada[i];
}

/* ---- MÉTODOS PARA ESCALONAR (para det/inversa)---- */
Matriz Matriz::Inversa() const
{
    if (abs(Determinante()) < 1e-5) {
        throw "Error: Determinante = 0. No tiene inversa.";
    }
    int renglones = this->renglones;
    int columnas = this->columnas;
    Matriz m(renglones, 2 * columnas, 0);

    /* -- Matriz aumentada -- */
    // Copiar valores de la matriz origianl
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            m.entrada[i][j] = entrada[i][j];
        }
    }
    // Colocar la identidad al lado
    for (int i = 0; i < renglones; ++i) {
        m.entrada[i][columnas + i] = 1;
    }

    /* Calculamos la inversa sobre 'm' (matriz aumentada) --*/
    // Llevamos el índice mayor hasta arriba:
    for (int i = 0; i < renglones; ++i) {
        int indice_mayor = i;
        for (int j = i + 1; j < renglones; ++j) {
            if (abs(m.entrada[indice_mayor][i]) < abs(m.entrada[j][i])) {
                indice_mayor = j;
            }
        }
        m.intercambiar_renglones(i, indice_mayor);
        for (int k = i + 1; k < renglones; ++k) {

            float escalar = -m.entrada[k][i] / m.entrada[i][i];
            m.sumar_renglones(k, i, escalar);
        }
    }

    for (int i = renglones - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            float escalar = -m.entrada[j][i] / m.entrada[i][i];
            m.sumar_renglones(j, i, escalar);
        }
    }

    for (int i = 0; i < renglones; ++i) {
        m.renglon_escalar(i, 1 / m.entrada[i][i]);
    }
    Matriz inversa(renglones, columnas, 0);

    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            inversa.entrada[i][j] = m.entrada[i][j + columnas];
        }
    }

    return inversa;
}

float Matriz::Determinante() const
{
    if (renglones != columnas) {
        throw "Error: La matriz no es cuadrada. No tiene determinante";
    }

    Matriz m(renglones, columnas, 0);

    /* -- Matriz aumentada -- */
    // Copiar valores de la matriz origianl
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            m.entrada[i][j] = entrada[i][j];
        }
    }

    /* -- Escalonamos UNICAMENTE abajo (Gauss)*/
    // Llevamos el índice mayor hasta arriba:
    int contador_intercambios = 0;
    for (int i = 0; i < renglones; ++i) {
        int indice_mayor = i;
        for (int j = i + 1; j < renglones; ++j) {
            if (abs(m.entrada[indice_mayor][i]) < abs(m.entrada[j][i])) {
                indice_mayor = j;
            }
        }
        if (i != indice_mayor) {
            m.intercambiar_renglones(i, indice_mayor);
            ++contador_intercambios;
        }

        if (abs(m.entrada[i][i]) < 1e-4) {
            return 0;
        }
        for (int k = i + 1; k < renglones; ++k) {

            float escalar = -m.entrada[k][i] / m.entrada[i][i];
            m.sumar_renglones(k, i, escalar);
        }
    }
    float det = 1;
    for (int i = 0; i < renglones; ++i) {
        det *= m.entrada[i][i];
    }
    return det * std::pow(-1, contador_intercambios);
}

/* -------------------------------------------------- */
void Matriz::intercambiar_renglones(int a, int b)
{
    float aux = 0;

    for (int i = 0; i < columnas; ++i) {
        aux = entrada[a][i];
        entrada[a][i] = entrada[b][i];
        entrada[b][i] = aux;
    }
}

/* -------------------------------------------------- */
void Matriz::renglon_escalar(int ren, float n)
{
    for (int i = 0; i < columnas; ++i) {
        entrada[ren][i] *= n;
    }
}

/* -------------------------------------------------- */

void Matriz::sumar_renglones(int ren1, int ren2, float n)
{
    for (int i = 0; i < columnas; ++i) {
        entrada[ren1][i] += n * entrada[ren2][i];
    }
}

/* ----FUNCIONES AMIGAS--- */
Matriz operator*(float escalar, Matriz m)
{
    Matriz matriz_escalar(m.renglones, m.columnas);
    for (int i = 0; i < matriz_escalar.renglones; ++i) {
        for (int j = 0; j < matriz_escalar.columnas; ++j) {
            matriz_escalar.entrada[i][j] = escalar * m.entrada[i][j];
        }
    }
    return matriz_escalar;
}

/* ----FUNCIONES OPERADORAS AMIGAS--- */
// TODO: Descomentar esta cosa
/*
iostreamd::ostream &operator<<(std::ostream &out, Matriz m)
{
    out << endl;
    for (int i = 0; i < m.renglones; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            out << m.entrada[i][j] << " ";
        }
        out << endl;
    }
    out << "\b";
    return out;
}
*/

/* -------------------------------------------------- */
std::istream &operator>>(std::istream &in, Matriz &m)
{
    for (int i = 0; i < m.renglones; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            cout << "Introduzca la entrada (" << i << ", " << j << "): ";
            in >> m.entrada[i][j];
        }
    }
    return in;
}

/* ---------- MÉTODO DE REDIMENSIONAMIENTO ---------- */
void Matriz::EstablecerRenglones(int n)
{
    if (n <= 0)
        throw "Error: Val\242r inv\240lida.";
    renglones = n;
}

void Matriz::EstablecerColumnas(int n)
{
    if (n <= 0)
        throw "Error: Val\242r inv\240lida.";
    columnas = n;
}

void Matriz::Redimensionar(int nuevoRenglon, int nuevaColumna)
{
    if (nuevoRenglon <= 0 || nuevaColumna <= 0)
        throw "Error: Dimensi\162n inv\240lida";
    if (nuevoRenglon == renglones && nuevaColumna == columnas)
        return;

    Matriz MatrizRedim(nuevoRenglon, nuevaColumna, 0);
    int filas_minimo = (renglones < nuevoRenglon) ? renglones : nuevoRenglon;
    int columnas_minimo = (columnas < nuevaColumna) ? columnas : nuevaColumna;
    for (int i = 0; i < filas_minimo; ++i) {
        for (int j = 0; j < columnas_minimo; ++j) {
            MatrizRedim[i][j] = entrada[i][j];
        }
    }

    // Borramos la origianl
    for (int i = 0; i < renglones; ++i) {
        delete[] entrada[i];
    }
    delete[] entrada;

    renglones = MatrizRedim.renglones;
    columnas = MatrizRedim.columnas;
    entrada = MatrizRedim.entrada;

    // Hacemos esto para evitar que el destructor se vuelva maniaquito
    MatrizRedim.entrada = nullptr;
    MatrizRedim.renglones = 0;
    MatrizRedim.columnas = 0;
}

//******************************//
std::ostream &operator<<(std::ostream &out, const Matriz &mat)
{
    // 1. Alias para facilitar la lectura del código original
    // Usamos 'const' para asegurar que no modificamos la matriz al imprimirla
    float **arreglo = mat.entrada;
    int m = mat.renglones;
    int n = mat.columnas;

    int max_ancho = 1; // Mínimo 1 dígito

    // 2. Calcular ancho máximo de columnas
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            double valor = arreglo[i][j];
            bool es_entero = (floor(valor) == valor);

            int parte_entera = static_cast<int>(valor);
            int digitos;

            if (parte_entera == 0) {
                digitos = 1;
            } else if (parte_entera < 0) {
                // Cuenta el signo y usa valor absoluto para log10
                digitos = static_cast<int>(floor(log10(abs(parte_entera)))) + 2;
            } else {
                digitos = static_cast<int>(floor(log10(parte_entera))) + 1;
            }

            // Ajustar ancho
            int ancho_actual = digitos;
            if (!es_entero) {
                ancho_actual += 3; // +1 punto, +2 decimales
            }
            if (ancho_actual > max_ancho) {
                max_ancho = ancho_actual;
            }
        }
    }

    // Asegurar ancho mínimo
    if (max_ancho < 5) {
        max_ancho = 5;
    }

    // 3. Calcular ancho total para los bordes
    // (Asumimos impresión estándar sin barra intermedia de matriz aumentada)
    int espacios_entre_nums = n - 1;
    int ancho_contenido = (n * max_ancho) + espacios_entre_nums;

    // --- IMPRESIÓN ---

    // 4. Borde Superior
    out << ESI;
    for (int i = 0; i < ancho_contenido; ++i)
        out << " ";
    out << ESD << endl;

    // 5. Contenido
    for (int i = 0; i < m; ++i) {
        out << BARRA_V; // Borde izquierdo

        for (int j = 0; j < n; ++j) {
            double valor = arreglo[i][j];
            bool es_entero = (floor(valor) == valor);

            if (es_entero) {
                out << setw(max_ancho) << static_cast<int>(valor);
            } else {
                out << fixed << setprecision(2) << setw(max_ancho) << valor;
            }

            // Espacio entre columnas (si no es la última)
            if (j < n - 1) {
                out << " ";
            }
        }
        out << BARRA_V << endl; // Borde derecho y salto de línea
    }

    // 6. Borde Inferior
    out << EII;
    for (int i = 0; i < ancho_contenido; ++i)
        out << " ";
    out << EID << endl;

    // IMPORTANTE: Retornar el stream para permitir encadenamiento (cout << m <<
    // endl;)
    return out;
}
