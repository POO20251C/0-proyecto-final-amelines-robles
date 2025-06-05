#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "heroe.h"
#include "mazmorra.h"
#include "score_manager.h"

class Juego {
    std::vector<std::unique_ptr<Heroe>> equipo;
    Mazmorra mazmorra;
    ScoreManager scoreManager;
private:
    std::string aliasJugador;


public:
    void iniciarPartida();
    void mostrarMenu();
    void procesarTurnos();
    void terminarPartida();
    Juego();
private:
    void seleccionarEquipo();
};

#endif