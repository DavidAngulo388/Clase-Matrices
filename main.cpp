/**
 * \file  main.cpp
 * En este archivo se encuentra el menu interactivo con el que el usuario podra realizar operaci&oacute;nes un-arias, binarias o hacer
 * cambios en las entradas de matrices.
 * \author Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 10/02/2026
 \code {.cpp}

 switch(opcion){

                case 1: // Leer A
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "Leyendo entradas de A..." << endl;
                    cin >> A;

                    system("pause");
                    break;
                case 2:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int entrada_A_i,entrada_A_j, nuevo_valor_ij_A;
                    cout << "Introduzca la entrada que desea cambiar de A" << endl;
                    cout << "(i,j) = ?" << endl;
                    do{
                        CapturaSegura(entrada_A_i,"i = ");
                    }while(entrada_A_i-1 >= A.ObtenerRenglones() || entrada_A_i-1 < 0);

                    do{
                        CapturaSegura(entrada_A_j,"j = ");
                    }while(entrada_A_j-1 >= A.ObtenerColumnas() || entrada_A_j-1 < 0);
                    if(entrada_A_j > A.ObtenerColumnas()) throw "Indice de columna fuera de rango.";
                    CapturaSegura(nuevo_valor_ij_A,"Introduzca el valor por sustituir: ");
                    A[entrada_A_i-1][entrada_A_j-1] = nuevo_valor_ij_A;


                    system("pause");
                    break;
                case 3:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int leer_i_a, leer_j_a;
                    cout << "(i,j) = ?" << endl;
                    do{
                        CapturaSegura(leer_i_a, "i = ");
                    }while(leer_i_a-1 < 0 || leer_i_a-1 >= A.ObtenerRenglones());

                    do{
                        CapturaSegura(leer_j_a, "j = ");
                    }while(leer_j_a-1 < 0 || leer_j_a-1 >= A.ObtenerColumnas());

                    cout << "La entrada (" << leer_i_a << ", " << leer_j_a << ") de la matriz A es: " << A[leer_i_a-1][leer_j_a-1] << endl;
                    system("pause");
                    break;
 \endcode

 */
#include "Matriz.hpp"
#include "CapturaSegura.hpp"
#include <iostream>
#include <cstdlib>
#include "utileria.hpp"

using namespace std;

// ó : \242
int main()
{
    int opcion = -1;
    bool salir = false;
    cout << " ======================================" << endl;
    cout << "   Programa para operar con matrices " << endl;
    cout << " ======================================" << endl;
    Matriz A(3,3,1), B(3,3,0);
        //ImprimirMatrices(A,B);
    do{
        ImprimirMatrices(A,B);
        // Para tener siempre hasta arriba la visualización de las matrices.

        cout << "======= Configurar matrices y memoria =======" << endl;
        cout <<  "1.  Capturar entradas de la matriz A" << endl;
        cout <<  "2.  Cambiar una entrada de A" << endl;
        cout <<  "3.  Leer una entrada de A" << endl;
        cout <<  "4.  Capturar entradas de la matriz B" << endl;
        cout <<  "5.  Cambiar una entrada de B" << endl;
        cout <<  "6.  Leer una entrada de B" << endl;
        cout <<  "7.  Redimensionar matriz A" << endl;
        cout <<  "8.  Redimensionar matriz B" << endl;
        cout <<  "9.  Clonar A en B (B = A)" << endl;

        cout << "\n======= Operaciones entre matrices =======" << endl;
        cout <<  "10.  A + B" << endl;
        cout <<  "11. A - B" << endl;
        cout <<  "12. B - A" << endl;
        cout <<  "13. A * Escalar" << endl;
        cout <<  "14. A * B" << endl;

        cout << "\n======= Operaciones unarias sobre A =======" << endl;
        cout <<  "15. Transpuesta " << endl;
        cout <<  "16. Inversa" << endl;
        cout <<  "17. Determinante" << endl;

        cout << endl << "0. Salir" << endl;
        CapturaSegura(opcion,"Introduzca una opci\242n: ");

        try {
            system("cls");
            switch(opcion){

                case 1: // Leer A
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "Leyendo entradas de A..." << endl;
                    cin >> A;

                    system("pause");
                    break;
                case 2:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int entrada_A_i,entrada_A_j, nuevo_valor_ij_A;
                    cout << "Introduzca la entrada que desea cambiar de A" << endl;
                    cout << "(i,j) = ?" << endl;
                    do{
                        CapturaSegura(entrada_A_i,"i = ");
                    }while(entrada_A_i-1 >= A.ObtenerRenglones() || entrada_A_i-1 < 0);

                    do{
                        CapturaSegura(entrada_A_j,"j = ");
                    }while(entrada_A_j-1 >= A.ObtenerColumnas() || entrada_A_j-1 < 0);
                    if(entrada_A_j > A.ObtenerColumnas()) throw "Indice de columna fuera de rango.";
                    CapturaSegura(nuevo_valor_ij_A,"Introduzca el valor por sustituir: ");
                    A[entrada_A_i-1][entrada_A_j-1] = nuevo_valor_ij_A;


                    system("pause");
                    break;
                case 3:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int leer_i_a, leer_j_a;
                    cout << "(i,j) = ?" << endl;
                    do{
                        CapturaSegura(leer_i_a, "i = ");
                    }while(leer_i_a-1 < 0 || leer_i_a-1 >= A.ObtenerRenglones());

                    do{
                        CapturaSegura(leer_j_a, "j = ");
                    }while(leer_j_a-1 < 0 || leer_j_a-1 >= A.ObtenerColumnas());

                    cout << "La entrada (" << leer_i_a << ", " << leer_j_a << ") de la matriz A es: " << A[leer_i_a-1][leer_j_a-1] << endl;
                    system("pause");
                    break;



                    system("pause");
                    break;
                case 4:
                    system("cls");
                    ImprimirMatrices(A,B);
                    cout << "Leyendo entradas de B..." << endl;
                    cin >> B;

                    system("pause");
                    break;
                case 5:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int entrada_B_i,entrada_B_j, nuevo_valor_ij_B;
                    cout << "Introduzca la entrada que desea cambiar de B" << endl;
                    cout << "(i,j) = ?" << endl;
                    do{
                        CapturaSegura(entrada_B_i,"i = ");
                    }while(entrada_B_i-1 >= B.ObtenerRenglones() || entrada_B_i-1 < 0);

                    do{
                        CapturaSegura(entrada_B_j,"j = ");
                    }while(entrada_B_j-1 >= B.ObtenerColumnas() || entrada_B_j-1 < 0);

                    CapturaSegura(nuevo_valor_ij_B,"Introduzca el valor por sustituir: ");
                    B[entrada_B_i-1][entrada_B_j-1] = nuevo_valor_ij_B;

                    system("pause");
                    break;
                case 6:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int leer_i_b, leer_j_b;
                    cout << "(i,j) = ?" << endl;
                    do{
                        CapturaSegura(leer_i_b, "i = ");
                    }while(leer_i_b-1 < 0 || leer_i_b-1 >= B.ObtenerRenglones());

                    do{
                        CapturaSegura(leer_j_b, "j = ");
                    }while(leer_j_b-1 < 0 || leer_j_b-1 >= B.ObtenerColumnas());

                    cout << "La entrada (" << leer_i_b << ", " << leer_j_b << ") de la matriz B es: " << B[leer_i_b-1][leer_j_b-1] << endl;
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int reng_A, col_A;
                    cout << "Redimensionando Matriz A con valores > 0." << endl << endl;
                    do{
                        CapturaSegura(reng_A,"Cantidad de renglones: ");
                    }while(reng_A <= 0);
                    do{
                        CapturaSegura(col_A,"Cantidad de columnas: ");
                    }while(col_A <= 0);

                    A.Redimensionar(reng_A,col_A);
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    ImprimirMatrices(A,B);
                    int reng_B, col_B;
                    cout << "Redimensionando Matriz B con valores > 0." << endl << endl;
                    do{
                        CapturaSegura(reng_B,"Cantidad de renglones: ");
                    }while(reng_B <= 0);
                    do{
                        CapturaSegura(col_B,"Cantidad de columnas: ");
                    }while(col_B <= 0);

                    B.Redimensionar(reng_B,col_B);
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    ImprimirMatrices(A,B);
                    system("cls");
                    B = A;
                    cout << "Clonaci\242n terminada!" << endl << endl;
                    cout << "[ Matriz A] : ";
                    cout << endl << A << endl;

                    cout << "[ Matriz B ]: ";
                    cout << endl << B << endl;

                    system("pause");
                    break;
                case 10:
                    system("cls");
                    ImprimirMatrices(A,B);
                    cout << "A + B = " << endl << A+B << endl;

                    system("pause");
                    break;
                case 11:
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "A - B = " << endl << A - B << endl;

                    system("pause");
                    break;
                case 12:
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "B - A = " << endl << B - A << endl;
                    system("pause");
                    break;
                case 13:
                    system("cls");
                    ImprimirMatrices(A,B);
                    float escalar;
                    CapturaSegura(escalar, "Introduce un escalar: ");

                    cout << endl << escalar << " * A = " << endl << escalar * A << endl;
                    system("pause");
                    break;
                case 14:

                    system("cls");
                    ImprimirMatrices(A,B);
                    cout << "Intentando calcular el producto..." << endl << endl ;
                    try{
                        cout << A*B << endl;
                    }catch(const char*mensaje){
                    cerr << mensaje << endl;
                    }

                    system("pause");
                    break;
                case 15:
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "Transpuesta de A:" << endl << endl;

                    cout << A.Transpuesta();

                    system("pause");
                    break;
                case 16:
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "Intentando calcular la inversa..." << endl << endl;

                    try{
                        cout << "A^-1: " << endl;
                        cout << A.Inversa();

                    }catch(const char* mensaje){
                        cerr << mensaje << endl;
                    }

                    system("pause");
                    break;
                case 17:
                    system("cls");
                    ImprimirMatrices(A,B);

                    cout << "\nEl determinante de A es: " << A.Determinante() << endl << endl;
                    system("pause");
                    break;
                default:
                    system("cls");
                    cout << "Opcion no valida." << endl;
                    system("pause");
                    break;
                case 0:
                    break;
            }

            //system("cls");

            if(opcion == 0) salir = true;

        } catch (const char *mensaje) {
            cerr << mensaje << endl;
            system("pause");
        }

    }while(!salir);

    system("cls"); cout << "Nos vemos!" << endl << endl;
    system("pause");

    return 0;
}
