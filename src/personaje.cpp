#include "personaje.h"
#include <iostream>
#include <cstdlib>

Personaje::Personaje(std::string n, int hp, int atk, int def, int spd, int lck)
    : nombre(n), hp(hp), hpMax(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void Personaje::atacar(Personaje* objetivo) {
    if (objetivo->esquivar()) {
        std::cout << nombre << " fallo su ataque a " << objetivo->getNombre() << "!\n";
        return;
    }
    int dano = atk - objetivo->getDEF();
    if (dano < 0) dano = 0;
    objetivo->recibirDano(dano);
}

void Personaje::recibirDano(int dano) {
    hp -= dano;
    if (hp < 0) hp = 0;
    std::cout << nombre << " recibio " << dano << " de dano. HP restante: " << hp << "\n";
}

bool Personaje::esquivar() {
    return (rand() % 100) < (lck * 2);
}

void Personaje::mejorarEstadisticas() {
    atk += atk * 0.02;
    def += def * 0.02;
}

void Personaje::curar(int cantidad) {
    hp += cantidad;
    if (hp > hpMax) hp = hpMax;
}

bool Personaje::estaVivo() const {
    return hp > 0;
}

int Personaje::getHPMax() const {
return hpMax;
}

std::string Personaje::getNombre() const { return nombre; }
int Personaje::getHP() const { return hp; }
int Personaje::getDEF() const { return def; }
int Personaje::getSPD() const { return spd; }
int Personaje::getATK() const { return atk; }
int Personaje::getLCK() const { return lck; }


