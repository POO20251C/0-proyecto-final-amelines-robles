#include "inventario.h"
#include <iostream>

void Inventario::agregarItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

void Inventario::mostrarItems() const {
    std::cout << "Inventario: " << items.size() << " items\n";
}