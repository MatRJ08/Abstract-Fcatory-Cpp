#include <iostream>
#include <stdlib.h>
#define clear() printf("\033[H\033[J")

using namespace std;

/**
 * Producto abstracto base para el Abstract Factory
 */
class Disco {
public:
    virtual void imprimir() = 0;
};

/**
 * Productos Concretos tipo DVD
 */
class DvdSimple : public Disco {
public:
    void imprimir() { cout << "Disco DVD de capa Simple\n"; }
};

class DvdDoble : public Disco {
public:
    void imprimir() { cout << "Disco DVD de capa Doble\n"; }
};


/**
 * Productos concretos tipo BluRay
 */
class BluRaySimple : public Disco {
public:
    void imprimir() { cout << "Disco BluRay de capa Simple\n"; }
};
class BluRayDoble : public Disco {
public:
    void imprimir() { cout << "Disco BluRay de capa Doble\n"; }
};

/**
 * Definicion de metodos del Abstract Factory
 */
class Factory {
public:
    virtual Disco *crear_simple() = 0;
    virtual Disco *crear_doble() = 0;
};

/**
 * Definicion de metodos para la fabrica DVD
 */
class FactoryDvd : public Factory {
public:
    Disco *crear_simple() {
        return new DvdSimple;
    }
    Disco *crear_doble() {
        return new DvdDoble;
    }
};

/**
 * Definicion de metodos para la Fabrica BlueRay
 */
class FactoryBluRay : public Factory {
public:
    Disco *crear_simple() {
        return new BluRaySimple;
    }
    Disco *crear_doble() {
        return new BluRayDoble;
    }
};

/**
 * Clase cliente. Se le proveen metodos para poder solicitar discos simples o dobles
 */
class Cliente {
private:
    Factory *factory;

public:
    Cliente(Factory *f) {
        factory = f;
    }


    void crear_disco_simple() {
        Disco *w = factory->crear_simple();
        w->imprimir();
    }
    void crear_disco_doble() {
        Disco *w = factory->crear_doble();
        w->imprimir();
    }
};

/**Interfaz de usuario*/
int main() {
    bool menu = true;
    while(menu) {
        Factory *factory;
        int opc;
        cout << "--------------------------Menu--------------------------\n";
        cout << "--------Seleccione que tipo de Disco desea crear--------\n";
        cout << "1. DVD capa simple\n";
        cout << "2. DVD capa doble\n";
        cout << "3. BluRay capa simple\n";
        cout << "4. BluRay capa doble\n";
        cout << "5. Salir\n";
        cin >> opc;
        switch (opc) {
            case 1: {

                factory = new FactoryDvd;
                Cliente *c = new Cliente(factory);
                c->crear_disco_simple();
                break;


            }

            case 2: {

                factory = new FactoryDvd;
                Cliente *c = new Cliente(factory);
                c->crear_disco_doble();
                break;
            }

            case 3: {

                factory = new FactoryBluRay;
                Cliente *c = new Cliente(factory);
                c->crear_disco_simple();
                break;


            }

            case 4: {

                factory = new FactoryBluRay;
                Cliente *c = new Cliente(factory);
                c->crear_disco_doble();
                break;
            }

            case 5:{
                menu = false;
            }

        }
    }
    return 0;
}

