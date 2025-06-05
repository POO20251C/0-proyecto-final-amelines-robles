#ifndef SALA_H
#define SALA_H

#include <vector>
#include <memory>
#include "enemigo.h"
#include "item.h"

class Sala {
    std::vector<std::unique_ptr<Enemigo>> enemigos;
    std::string tipoSala;
    std::unique_ptr<Item> item;

public:
    Sala(std::string tipo);

    // Función para agregar enemigos a la sala
    void agregarEnemigo(std::unique_ptr<Enemigo> e);

    std::vector<std::unique_ptr<Enemigo>>& getEnemigos();

    void resolverEncuentro(std::vector<Heroe*>& heroes);
    std::string getTipoSala() const;
};

#endif
