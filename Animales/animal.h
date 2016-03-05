#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>

using namespace std;

// Clasificación según su alimentación.
enum clasificacion {
    CARNIVORO,
    HERBIVORO,
    OMNIVORO
};

// Array de string
static string textoClasificacion[] = { "Carnívoro", "Herbívoro", "Omnívoro" };

// Definición de la clase Animal
class Animal
{
public:
    // Constructor de la clase
    Animal();

    // Constructor sobrecargado
    Animal(string suNombre, int numPatas);

    // Destructor de la clase
    ~Animal(void);

    // Relaciona el valor enumerado con el texto equivalente (string)
    string escribeClasificacion(clasificacion suClasificacion);

    //
    // "Getters" & "Setters" (Devuelven & Establecen valores a los atributos)
    //
    int getPatas();
    void setPatas(int value);

    string getNombre();
    void setNombre(string value);

    clasificacion getAlimentacion();
    void setAlimentacion(clasificacion value);

    // Ojo, que estos dos son algo diferentes ... trabajan con una lista
    int getRacionesRecibidas(int vez);
    void setRacionesRecibidas(int racion);

    /*
     * Métodos de la clase
     *
     * Si quisiéramos OBLIGAR a utilizar el método de las clases derivadas,
     * en la definición de este método añadimos la palabra "virtual" delante:
     *
     * virtual void EmiteSonido();
     *
     */
    // Método de la clase base con funcionalidad
    void EmiteSonido();
    // Método de la clase definido como virtual => Obliga a usar el equivalente en las clases derivadas.
    //virtual void EmiteSonido();

    // Métodos sobrecargados
    // desayuno, comida y cena son valores enteros que representan las raciones que le damos al animal
    void DarDeComer(int desayuno);
    void DarDeComer(int desayuno, int comida);
    void DarDeComer(int desayuno, int comida, int cena);

    // Método para obtener las raciones de comida totales ...
    int CalcularRaciones();

private:

    int patas;
    string nombre;
    clasificacion alimentacion;
    vector<int> raciones;

};

#endif // ANIMAL_H
