#include "Matriz.hpp"
#include <iostream>

using namespace std;

int main() {
  // TODO: Menusito bonito perronson aca.

  try {
    Matriz m(2, 3, 34);
    Matriz m_2(2, 3, 33);

    Matriz suma = m + m_2;
    cout << "SUMA: " << m << "+" << m_2 << "=" << suma << endl;
    cout << "RESTA: " << m << "-" << m_2 << "=" << m-m_2 << endl;
    Matriz m_3(3,2,5);
    cout << "MULTIPLICACION DE MATRICES: " << m << "*" << m_3 << "=" << m*m_3 << endl;
    float c = 3.58f;
    cout << "MULTIPLICACION ESCALAR (c*m): " << c << endl << "*" << m << "=" << c*m << endl;
    cout << "MULTIPLICACION ESCALAR (m_2*c): " << m_2 << "*" << c << endl << "=" << m_2*c << endl;
  } catch (const char *mensaje) {
    cerr << mensaje << endl;
  }

  return 0;
}
