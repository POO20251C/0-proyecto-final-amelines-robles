#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <vector>
#include <memory>
#include "sala.h"
#include "heroe.h"  

class Mazmorra {
    std::vector<std::unique_ptr<Enemigo>> enemigosDisponibles;
    std::vector<Sala> salas;
    int salaActual = 0;

public:
    Mazmorra();

    bool avanzarSala(std::vector<Heroe*>& heroes);
};

#endif
