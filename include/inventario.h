#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <memory>
#include "item.h"

class Inventario {
    std::vector<std::unique_ptr<Item>> items;

public:
    void agregarItem(std::unique_ptr<Item> item);
    void mostrarItems() const;
};

#endif