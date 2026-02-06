#include "Matriz.hpp"
#include <iostream>

using namespace std;

int main() {
  // TODO: Menusito bonito perronson aca.

  try {
    Matriz m(4, 10);
    Matriz m_2(4, 10);

    Matriz suma = m + m_2;

  } catch (const char *mensaje) {
    cerr << mensaje << endl;
  }

  return 0;
}
