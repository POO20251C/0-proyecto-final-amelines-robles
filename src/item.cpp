#include "item.h"
#include "heroe.h"

Item::Item(std::string n, std::string t, int a, int d, float l)
    : nombre(n), tipo(t), modAtk(a), modDef(d), modLck(l) {}

Arma::Arma(std::string n, int a, float l) : Item(n, "arma", a, 0, l) {}
void Arma::aplicar(Heroe* h) { /* lógica de aplicar arma */ }

Armadura::Armadura(std::string n, int d) : Item(n, "armadura", 0, d, 0) {}
void Armadura::aplicar(Heroe* h) { /* lógica de aplicar armadura */ }

Pocion::Pocion(std::string n, int c) : Item(n, "pocion", 0, 0, 0), curacion(c) {}
void Pocion::aplicar(Heroe* h) { h->curar(curacion); }

Accesorio::Accesorio(std::string n, float l) : Item(n, "accesorio", 0, 0, l) {}
void Accesorio::aplicar(Heroe* h) { /* lógica de aplicar accesorio */ }
