#include <iostream>

using namespace std;

class Test{

public:
    Test();
    ~Test();

    int miembroPublico;

    // Setters (Asignan valores a los atributos)
    void setPublico(int m) { miembroPublico = m; }
    void setPrivado(int m) { miembroPrivado = m; }
    void setProtegido(int m) { miembroProtegido = m; }

    // Getters (Devuelven el valor de los atributos)
    int getPublico ()  { return miembroPublico; }
    int getPrivado ()  { return miembroPrivado; }
    int getProtegido ()  { return miembroProtegido; }

private:

    int miembroPrivado;

protected:

    int miembroProtegido;

};

Test::Test()
{
    miembroPublico = 10;
    miembroPrivado = 5;
    miembroProtegido = 1;
}

class TestHija: public Test
{
  public:
    TestHija();
    ~TestHija();
};

TestHija::TestHija()
{
    miembroPublico = 50;        // Tengo acceso
  // miembroPrivado = 60;        // ERROR! -> No tengo acceso a miembros privados de esta manera. DEBO usar un método! (setter)
    miembroProtegido = 70;      // Tengo acceso sólo desde aquí
}

int main()
{
    // Creamos un objeto ...
    Test *t = new Test();

    /*
     * Puedo modificar un atributo público DIRECTAMENTE desde:
     * 1. Dentro de la clase.
     * 2. Dentro de la clase hija.
     * 3. Desde fuera de la clase, es decir, desde un objeto que he creado en el cuerpo principal del programa.
     *
     * Aunque se puede hacer, esto NO ES ELEGANTE, pero se puede hacer porque es público.
     *
     */
    cout << "El miembro publico es: " << t->miembroPublico << endl;
    t->miembroPublico ++;
    cout << "El miembro publico es: " << t->miembroPublico << endl;

    /*
     * Puedo modificar un atributo privado DIRECTAMENTE desde:
     * 1. Dentro de la clase.
     *
     * Pero no puedo hacerlo DIRECTAMENTE desde:
     *
     * 1. Dentro de la clase hija.
     * 2. Desde fuera de la clase, es decir, desde un objeto que he creado en el cuerpo principal del programa.
     *
     * Para modificar un atributo privado desde la clase hija o desde un objeto ... ¿QUÉ NECESITO?
     *
     * ¡MÉTODOS PÚBLICOS! -> Que me permitan modificar su valor
     *
     */
    //t->miembroPrivado = 20;   // Así ... NO :(
    t->setPrivado(20);          // Así ... SÍ :)
    cout << "El miembro privado es: " <<  t->getPrivado() << endl;

    /*
     * Puedo modificar un atributo protegido DIRECTAMENTE desde:
     * 1. Dentro de la clase.
     * 2. Dentro de la clase hija.
     *
     * Pero no puedo hacerlo DIRECTAMENTE desde:
     *
     * 1. Desde fuera de la clase, es decir, desde un objeto que he creado en el cuerpo principal del programa.
     *
     * Para modificar un atributo protegido desd un objeto ... ¿QUÉ NECESITO?
     *
     * ¡MÉTODOS PÚBLICOS! -> Que me permitan modificar su valor
     *
     */
    TestHija *t2 = new TestHija();
    //t2->miembroProtegido = 100;  // Así ... NO :/
    t2->setProtegido(100);          // Así ... SÍ :)

    // Imprimimos los valores de los atributos en la clase hija
    cout << "El miembro público en la clase hija es   : " <<  t2->getPublico() << endl;     // Modificado en la clase hija
    cout << "El miembro privado en la clase hija es   : " <<  t2->getPrivado() << endl;     // No lo hemos modificado
    cout << "El miembro protegido en la clase hija es : " <<  t2->getProtegido() << endl;   // Modificado a través del setter

    return 0;
}

