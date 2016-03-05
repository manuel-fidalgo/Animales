#include <iostream>
#include "animal.h"
#include "perro.h"
#include "gato.h"
#include <string>

using namespace std;

//
// Función que imprime por pantalla los datos de un animal
//
void ImprimirDatosAnimal(Animal *a)
{
    cout << "Nombre        : " << a->getNombre() << endl;
    cout << "Patas         : " << a->getPatas() << endl;
    cout << "Clasificación : " << a->escribeClasificacion(a->getAlimentacion()) << endl;
}

int main()
{
    cout << "CASO 1: Creo un perro con la CLASE BASE Animal " << endl;

    Animal *perro1 = new Perro();
    perro1->EmiteSonido();              // Se ejecuta el método "EmiteSonido" de la clase Animal
                                        /*
                                         * Observa el resultado ahora y luego prueba a definir "EmiteSonido" como virtual
                                         * en la clase Animal (virtual void EmiteSonido())
                                         *
                                         * Ahora    : perro1->EmiteSonido() = "HABLO A MI MANERA"
                                         * Después  : perro1->EmiteSonido() = "LADRO COMO UN PERRO"
                                         *
                                         * Método virtual en clase base => obliga a ejecutar el método de la clase derivada
                                         *
                                         */
    perro1->setNombre("Tobby");
    perro1->setPatas(4);
    perro1->setAlimentacion(CARNIVORO);

    // Muestro su información
    ImprimirDatosAnimal(perro1);

    cout << "-------------------------------------------------" << endl;

    cout << "CASO 2: Creo un perro con la CLASE DERIVADA Perro " << endl;

    Perro *perro2 = new Perro();
    perro2->EmiteSonido();              // Se ejecuta el método "EmiteSonido" de la clase Perro
    perro2->setNombre("Pancho");
    perro2->setPatas(4);
    perro2->setAlimentacion(OMNIVORO);  // Pancho come lo que le eches ...

    // Muestro su información
    ImprimirDatosAnimal(perro2);

    cout << "-------------------------------------------------" << endl;

    cout << "CASO 3: Creo un perro con la CLASE DERIVADA Gato " << endl;

    Animal *gato = new Gato();
    ((Gato*)gato)->EmiteSonido();  // FORZAMOS, mediante una conversión (type-casting), la ejecución de "EmiteSonido" de la clase Gato
    gato->setNombre("Michu");
    gato->setPatas(4);
    gato->setAlimentacion(HERBIVORO); // No lo son, pero este gato es así de especial

    gato->DarDeComer(5, 6, 7);
    cout << "El gato " << gato->getNombre() << " ha comido " << gato->CalcularRaciones() << " raciones " << endl;

    // Muestro su información
    ImprimirDatosAnimal(gato);

    cout << "-------------------------------------------------" << endl;

    // SIEMPRE debemos eliminar los objetos para liberar memoria !!
    delete perro1;
    delete perro2;
    delete gato;

    return 0;
}

