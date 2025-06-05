#include "score_manager.h"
#include <fstream>
#include <iostream>
#include <ctime>

void ScoreManager::registrarPuntaje(std::string alias, int salaMax, int saludPerdida) {
    std::ofstream file(scoresFile, std::ios::app);
    time_t now = time(0);
    file << alias << "," << salaMax << "," << saludPerdida << "," << ctime(&now);
    file.close();
}

void ScoreManager::mostrarTop5() {
    std::ifstream file(scoresFile);
    std::string line;
    int count = 0;
    std::cout << "Top 5 puntuaciones:\n";
    while (getline(file, line) && count++ < 5) {
        std::cout << line;
    }
    file.close();
}