#include "heroe.h"
#include <iostream>

Heroe::Heroe(std::string n, int hp, int atk, int def, int spd, int lck)
    : Personaje(n, hp, atk, def, spd, lck), armaEquip(nullptr), armaduraEquip(nullptr) {}

bool Heroe::usarPocion() {
    if (numPociones > 0) {
        curar(20);
        numPociones--;
        std::cout << nombre << " usó una poción y se curó. HP actual: " << hp << "\n";
        return true;
    }
    return false;
}

void Heroe::equiparArma(Item* arma) {
    armaEquip = arma;
    arma->aplicar(this);
}

void Heroe::equiparArmadura(Item* armadura) {
    armaduraEquip = armadura;
    armadura->aplicar(this);
}

Inventario& Heroe::getInventario() {
    return inventario;
}



