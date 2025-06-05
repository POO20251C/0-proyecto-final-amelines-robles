#ifndef HEROE_H
#define HEROE_H

#include "personaje.h"
#include "inventario.h"
#include "item.h"

class Heroe : public Personaje {
    Item* armaEquip;
    Item* armaduraEquip;
    Inventario inventario;

public:
    Heroe(std::string n, int hp, int atk, int def, int spd, int lck);
    bool usarPocion();
    void equiparArma(Item* arma);
    void equiparArmadura(Item* armadura);
    Inventario& getInventario();
private:
    int numPociones = 3;

};

#endif