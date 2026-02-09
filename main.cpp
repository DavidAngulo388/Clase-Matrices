#include "Matriz.hpp"
#include <iostream>

using namespace std;

int main()
{
    // TODO: Menusito bonito perronson aca.

    try {
        Matriz m(2, 3, 34);
        Matriz m_2(2, 3, 33);

        // Suma
        Matriz suma = m + m_2;
        cout << "SUMA: " << m << "+" << m_2 << "=" << suma << endl;
        cout << "RESTA: " << m << "-" << m_2 << "=" << m - m_2 << endl;
        Matriz m_3(3, 2, 5);

        // Matriz x Matriz
        cout << "MULTIPLICACION DE MATRICES: " << m << "*" << m_3 << "="
             << m * m_3 << endl;
        float c = 3.58f;

        // Multiplicación por escalar
        cout << "MULTIPLICACION ESCALAR (c*m): " << c << endl
             << "*" << m << "=" << c * m << endl;
        cout << "MULTIPLICACION ESCALAR (m_2*c): " << m_2 << "*" << c << endl
             << "=" << m_2 * c << endl;

        // ----------- otras pruebas ----------- //
        cout << "\n\n" << m << endl;
        cout << "(prueba asignación de entrada) Cambiando entrada (2,1) por "
                "100..."
             << endl;
        m[1][0] = 100;

        cout << "\n\n" << m << endl;

        cout << "(prueba lectura de entrada) La entrada (1,2) es: " << m[0][1]
             << endl;

        // Leer una matriz:
        Matriz m4(3, 3);
        cin >> m4;
        cout << endl << m4 << endl;

        Matriz m4_inversa = m4.Inversa();

        cout << "\n\nREDIMENSIONAMIENTO\n\n";

        Matriz mat_prueba_redim(10, 10, 3);
        cout << mat_prueba_redim;
        mat_prueba_redim.Redimensionar(5, 5);
        cout << mat_prueba_redim;
        mat_prueba_redim.Redimensionar(10, 10);
        cout << mat_prueba_redim;
        mat_prueba_redim.Redimensionar(5, 2);
        cout << mat_prueba_redim;
        mat_prueba_redim.Redimensionar(15, 6);
        cout << mat_prueba_redim;

    } catch (const char *mensaje) {
        cerr << mensaje << endl;
    }

    return 0;
}
