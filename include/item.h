#ifndef ITEM_H
#define ITEM_H

#include <string>

class Heroe;

class Item {
protected:
    std::string nombre, tipo;
    int modAtk, modDef;
    float modLck;

public:
    Item(std::string n, std::string t, int a, int d, float l);
    virtual void aplicar(Heroe* h) = 0;
    virtual ~Item() {}
};

class Arma : public Item {
public:
    Arma(std::string n, int a, float l);
    void aplicar(Heroe* h) override;
};

class Armadura : public Item {
public:
    Armadura(std::string n, int d);
    void aplicar(Heroe* h) override;
};

class Pocion : public Item {
    int curacion;
public:
    Pocion(std::string n, int c);
    void aplicar(Heroe* h) override;
};

class Accesorio : public Item {
public:
    Accesorio(std::string n, float l);
    void aplicar(Heroe* h) override;
};

#endif