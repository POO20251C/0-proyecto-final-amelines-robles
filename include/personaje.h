#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
    int getHPMax() const;
protected:
    std::string nombre;
    int hp, atk, def, spd, lck;
    int hpMax;
public:
    Personaje(std::string n, int hp, int atk, int def, int spd, int lck);
    virtual ~Personaje() = default;

    virtual void atacar(Personaje* objetivo);
    virtual void recibirDano(int dano);
    virtual bool esquivar();
    virtual void mejorarEstadisticas();

    bool estaVivo() const;
    std::string getNombre() const;
    int getHP() const;
    int getDEF() const;
    int getSPD() const;
    int getATK() const;
    int getLCK() const;
    void curar(int cantidad);
};

#endif

