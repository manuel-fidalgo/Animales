#include <iostream>

using namespace std;

void suma (int *a)
{
    *a += 1;
}

void comparaPunteros()
{
    int a, b;
    int *punt1, *punt2;

    a = 5; b = 5;
    punt1 = &a; punt2 = &b;

    if ( *punt1 == *punt2 )
    printf( "Son iguales\n" );
}

int main()
{
    // Los punteros almacenan direcciones de memoria

    // (*) - Operador de indirección
    // (&) - Operador de referencia
    //  p1 - Devuelve la dirección de memoria almacenada
    // *p1 - Devuelve el valor ubicado en esa dirección de memoria

    int entero = 125;
    int *p;
    int x;

    // 01. Hacemos que el puntero apunte a la dirección de memoria de la variable "entero"
    p = &entero;

    // 02. Hacemos que la variable x almacene el valor que contiene el puntero
    x = *p;

    //-------------------------------------------------
    // Imprimimos para aclararnos ...
    //-------------------------------------------------

    // Variable "entero"
    cout << "Valor almacenado en 'entero': "     << entero << endl;
    cout << "Dirección de memoria de 'entero': " << &entero << endl;
    cout << "-------------------------------------------------------" << endl;

    // Variable puntero "p"
    cout << "Valor que almacena 'p': " << p << endl;
    cout << "Valor que contiene la dirección de memoria apuntada: " << *p << endl;
    cout << "-------------------------------------------------------" << endl;

    // Variable "x"
    cout << "Valor que almacena 'x': "      << x << endl;
    cout << "Dirección de memoria de 'x': " << &x << endl;
    cout << "-------------------------------------------------------" << endl;

    // Mis conclusiones ...
    cout << &entero << " = " << p << endl;
    cout << "1. " << entero  << " = " << *p << " = " << x << endl;

    //-------------------------------------------------
    // Operamos
    //-------------------------------------------------

    // 02. Modificamos el valor de la variable 'entero'
    entero++;
    cout << "2. " << entero  << " = " << *p << " != " << x << endl;

    // 03. Modificamos el valor desde el puntero
    (*p)++;
    cout << "3. " << entero  << " = " << *p << " != " << x << endl;

    // 04. Modificamos el valor desde una función
    suma(p);
    cout << "4. " << entero  << " = " << *p << " != " << x << endl;

    comparaPunteros();

    return 0;
}

