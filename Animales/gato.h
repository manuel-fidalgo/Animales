#ifndef GATO_H
#define GATO_H

#include "animal.h"

class Gato : public Animal
{
public:
    Gato();
    ~Gato();

    void EmiteSonido();
};

#endif // GATO_H
