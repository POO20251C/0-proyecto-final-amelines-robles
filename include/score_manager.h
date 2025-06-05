#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

#include <string>

class ScoreManager {
    std::string scoresFile = "scores.txt";

public:
    void registrarPuntaje(std::string alias, int salaMax, int saludPerdida);
    void mostrarTop5();
};

#endif