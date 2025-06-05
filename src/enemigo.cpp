#include "enemigo.h"
#include "heroe.h"
#include <iostream>
#include <cstdlib>

Enemigo::Enemigo(std::string n, int hp, int atk, int def, int spd, int lck)
    : Personaje(n, hp, atk, def, spd, lck) {}

Soldado::Soldado(std::string n, int hp, int atk, int def, int spd, int lck)
    : Enemigo(n, hp, atk, def, spd, lck) {}

MiniJefe::MiniJefe(std::string n, int hp, int atk, int def, int spd, int lck)
    : Enemigo(n, hp, atk, def, spd, lck) {}

GranJefe::GranJefe(std::string n, int hp, int atk, int def, int spd, int lck)
    : Enemigo(n, hp, atk, def, spd, lck) {}

void Soldado::ejecutarTurno(std::vector<Heroe*>& heroes) {
    if (!heroes.empty()) atacar(heroes[0]);
}

void MiniJefe::ejecutarTurno(std::vector<Heroe*>& heroes) {
    if (!heroes.empty()) atacar(heroes[0]);
}

void GranJefe::ejecutarTurno(std::vector<Heroe*>& heroes) {
    if (!heroes.empty()) atacar(heroes[0]);
}
