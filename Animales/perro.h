#ifndef PERRO_H
#define PERRO_H

#include "animal.h"

class Perro : public Animal
{
public:
    Perro();
    ~Perro();

    void EmiteSonido();
};

#endif // PERRO_H
