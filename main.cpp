#include <iostream>

using namespace std;

/**
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
 */
class Disco {
public:
    virtual void imprimir() = 0;
};

/**
 * Concrete product family 1.
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
 * Concrete product family 2.
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
 * Abstract factory defines methods to create all
 * related products.
 */
class Factory {
public:
    virtual Disco *crear_simple() = 0;
    virtual Disco *crear_doble() = 0;
};

/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
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
 * Concrete factory creates concrete products, but
 * returns them as abstract.
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
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
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

/**
 * Now the nasty switch statement is needed only once to
 * pick and create a proper factory. Usually that's
 * happening somewhere in program initialization code.
 */
int main() {
    Factory *factory;
    factory = new FactoryDvd;

    Cliente *c = new Cliente(factory);
    c->crear_disco_simple();
    c->crear_disco_doble();
}

