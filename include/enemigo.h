#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"
#include <vector>

class Heroe;

class Enemigo : public Personaje {
public:
    Enemigo(std::string n, int hp, int atk, int def, int spd, int lck);
    virtual void ejecutarTurno(std::vector<Heroe*>& heroes) = 0;
};

class Soldado : public Enemigo {
public:
    Soldado(std::string n, int hp, int atk, int def, int spd, int lck);
    void ejecutarTurno(std::vector<Heroe*>& heroes); 
};

class MiniJefe : public Enemigo {
public:
    MiniJefe(std::string n, int hp, int atk, int def, int spd, int lck);
    void ejecutarTurno(std::vector<Heroe*>& heroes); 
};

class GranJefe : public Enemigo {
public:
    GranJefe(std::string n, int hp, int atk, int def, int spd, int lck);
    void ejecutarTurno(std::vector<Heroe*>& heroes); 
};

#endif