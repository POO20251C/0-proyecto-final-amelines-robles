#include "juego.h"
#include "mazmorra.h"
#include "heroe.h"
#include <iostream>
#include <memory>
#include <ctime>
#include <algorithm>  // ← para std::find

Juego::Juego() {
}

void Juego::seleccionarEquipo() {
    std::vector<std::unique_ptr<Heroe>> pool;
    pool.emplace_back(std::make_unique<Heroe>("Gojo", 60, 6, 3, 4, 1));
    pool.emplace_back(std::make_unique<Heroe>("Luz", 70, 5, 4, 5, 2));
    pool.emplace_back(std::make_unique<Heroe>("King", 50, 7, 2, 6, 4));
    pool.emplace_back(std::make_unique<Heroe>("Russo", 80, 4, 6, 3, 1));
    pool.emplace_back(std::make_unique<Heroe>("Okabe", 55, 6, 3, 6, 5));
    pool.emplace_back(std::make_unique<Heroe>("Frank", 90, 3, 6, 2, 0));

    std::cout << "\nElige 3 heroes para tu equipo:\n";
    for (size_t i = 0; i < pool.size(); ++i) {
        std::cout << i << ") " << pool[i]->getNombre()
                  << " - HP: " << pool[i]->getHP()
                  << ", ATK: " << pool[i]->getATK()
                  << ", DEF: " << pool[i]->getDEF()
                  << ", SPD: " << pool[i]->getSPD()
                  << ", LCK: " << pool[i]->getLCK()
                  << "\n";
    }

    std::vector<int> seleccionados;
    while (seleccionados.size() < 3) {
        int eleccion;
        std::cout << "Elige el numero del heroe #" << (seleccionados.size() + 1) << ": ";
        std::cin >> eleccion;

        if (eleccion >= 0 && eleccion < static_cast<int>(pool.size()) &&
            std::find(seleccionados.begin(), seleccionados.end(), eleccion) == seleccionados.end()) {
            equipo.emplace_back(std::move(pool[eleccion]));
            seleccionados.push_back(eleccion);
        } else {
            std::cout << "Seleccion invalida o repetida. Intenta de nuevo.\n";
        }
    }
}

void Juego::mostrarMenu() {
    std::cout << "\nBienvenido a Natal Combat\n";
    std::cout << "Ingresa tu nombre o alias: ";
    std::getline(std::cin, aliasJugador);

    if (aliasJugador.empty()) {
        aliasJugador = "Jugador";
    }

    seleccionarEquipo();
}


void Juego::iniciarPartida() {
    mostrarMenu();
    procesarTurnos();
    terminarPartida();
}

void Juego::procesarTurnos() {
    std::cout << "\nComienza la exploración de la mazmorra...\n";

    // Crear vector de punteros crudos para pasarlos a avanzarSala
    std::vector<Heroe*> heroesVivos;
    for (auto& h : equipo) {
        heroesVivos.push_back(h.get());
    }

    int sala = 1;
    while (mazmorra.avanzarSala(heroesVivos)) {
    std::cout << "\nHas completado la sala " << sala << " exitosamente.\n";

    // Mejora de estadísticas después de cada sala
    for (auto& h : heroesVivos) {
        h->mejorarEstadisticas();
    }

    ++sala;

    std::cout << "\nPresiona Enter para continuar a la siguiente sala...";
    std::cin.ignore(); // limpia el buffer
    std::cin.get();    // espera que el jugador presione Enter
}

    std::cout << "\nHas salido de la mazmorra (o has sido derrotado).\n";
}

void Juego::terminarPartida() {
    std::cout << "\nPartida finalizada.\n";
    int totalHP = 0;
    for (auto& h : equipo) {
        totalHP += h->getHP();
    }
    int saludPerdida = 180 - totalHP; // Asumiendo 3 héroes con 60 HP c/u como base
    scoreManager.registrarPuntaje(aliasJugador, 10, saludPerdida);
    scoreManager.mostrarTop5();
}
