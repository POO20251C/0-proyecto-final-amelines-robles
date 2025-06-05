#include "sala.h"
#include "heroe.h"
#include <iostream>
#include <algorithm>

Sala::Sala(std::string tipo) : tipoSala(std::move(tipo)) {}

void Sala::agregarEnemigo(std::unique_ptr<Enemigo> e) {
    enemigos.push_back(std::move(e));
}

std::vector<std::unique_ptr<Enemigo>>& Sala::getEnemigos() {
    return enemigos;
}

void Sala::resolverEncuentro(std::vector<Heroe*>& heroes) {
    std::cout << "Resolviendo sala tipo: " << tipoSala << "\n";

    for (auto& enemigo : enemigos) {
        std::cout << "Luchando contra " << enemigo->getNombre() << "\n";
    }
}

std::string Sala::getTipoSala() const {
    return tipoSala;
}
