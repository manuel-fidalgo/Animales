#include "animal.h"

Animal::Animal()
{
    cout << "SOY UN ANIMAL" << endl;
}

Animal::Animal(string suNombre, int numPatas)
{
    this->nombre = suNombre;
    this->patas = numPatas;
}

Animal::~Animal()
{

}

void Animal::EmiteSonido()
{
    cout << "HABLO A MI MANERA" << endl;
}

string Animal::escribeClasificacion(clasificacion suClasificacion)
{
    return textoClasificacion[suClasificacion];
}

int Animal::getPatas()
{
    return patas;
}

void Animal::setPatas(int value)
{
    patas = value;
}
string Animal::getNombre()
{
    return nombre;
}

void Animal::setNombre(string value)
{
    nombre = value;
}

clasificacion Animal::getAlimentacion()
{
    return alimentacion;
}

void Animal::setAlimentacion(clasificacion value)
{
    alimentacion = value;
}

int Animal::getRacionesRecibidas(int vez)
{
    return raciones[vez];
}

void Animal::setRacionesRecibidas(int racion)
{
    raciones.push_back(racion);
}

void Animal::DarDeComer(int desayuno)
{
    setRacionesRecibidas(desayuno); // Sólo la ración del desayuno
}

void Animal::DarDeComer(int desayuno, int comida)
{
    setRacionesRecibidas(desayuno); // Desayuno ...
    setRacionesRecibidas(comida);   // ... y comida
}

void Animal::DarDeComer(int desayuno, int comida, int cena)
{
    setRacionesRecibidas(desayuno); // Desayuno ...
    setRacionesRecibidas(comida);   // ... comida ...
    setRacionesRecibidas(cena);     // ... y cena
}

int Animal::CalcularRaciones()
{
    int racionesTotales = 0;

    for (int i = 0; i < (int)raciones.size(); i++ )
    {
        racionesTotales += raciones[i];
    }

    return racionesTotales;
}

/*
 * Otra forma de relacionar un enumerado con una cadena de texto.
 * Aunque menos elegante que la anterior...
 */

/*
string Animal::escribeClasificacion(int suClasificacion)
{
    string claseAnimal;

    switch(suClasificacion){
        case CARNIVORO:
            claseAnimal = "Carnívoro";
        break;
        case HERBIVORO:
            claseAnimal = "Herbívoro";
        break;
        case OMNIVORO :
            claseAnimal = "Omnívoro";
        break;
    }

    return claseAnimal;
}
*/
