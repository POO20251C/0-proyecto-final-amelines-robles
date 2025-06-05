#include "enemigo.h"
#include "mazmorra.h"
#include "sala.h"
#include "heroe.h"         
#include <iostream>        
#include <memory>
#include <algorithm>       
#include <iostream>
#include <vector>
#include <algorithm> 

bool Mazmorra::avanzarSala(std::vector<Heroe*>& heroes) {
    if (salaActual >= salas.size()) return false;

    Sala& sala = salas[salaActual];
std::cout << "Comienza la batalla en la sala " << (salaActual + 1)
          << " tipo: " << sala.getTipoSala() << std::endl;

auto& enemigos = sala.getEnemigos();

std::cout << "Cantidad de enemigos en esta sala: " << enemigos.size() << std::endl;

while (!enemigos.empty() && std::count_if(heroes.begin(), heroes.end(), [](Heroe* h) { return h->estaVivo(); }) >= 2) {

    struct Participante {
        enum Tipo { HEROE, ENEMIGO } tipo;
        Heroe* heroe = nullptr;
        Enemigo* enemigo = nullptr;
        int spd;
    };

    std::vector<Participante> turnos;

    for (Heroe* h : heroes) {
        if (h->estaVivo()) {
            turnos.push_back({ Participante::HEROE, h, nullptr, h->getSPD() });
        }
    }

    for (auto& e : enemigos) {
        if (e->estaVivo()) {
            turnos.push_back({ Participante::ENEMIGO, nullptr, e.get(), e->getSPD() });
        }
    }

    std::sort(turnos.begin(), turnos.end(), [](const Participante& a, const Participante& b) {
        return a.spd > b.spd;
    });

    for (auto& p : turnos) {
        if (p.tipo == Participante::HEROE && p.heroe->estaVivo()) {
            Heroe* h = p.heroe;
            std::cout << "\nTurno de " << h->getNombre() << " (HP: " << h->getHP() << ")\n";
            std::cout << "Elige acción:\n";
            std::cout << "1) Atacar enemigo\n";
            std::cout << "2) Usar poción\n";
            std::cout << "3) Pasar turno\n";
            int opcion;
            std::cin >> opcion;

            if (opcion == 1) {
                std::vector<Enemigo*> enemigosVivos;
                for (auto& e : enemigos) {
                    if (e->estaVivo()) enemigosVivos.push_back(e.get());
                }

                std::cout << "Enemigos vivos:\n";
                for (size_t i = 0; i < enemigosVivos.size(); ++i) {
                    std::cout << i << ") " << enemigosVivos[i]->getNombre()
                              << " HP: " << enemigosVivos[i]->getHP() << "\n";
                }

                std::cout << "Elige enemigo a atacar: ";
                int indice;
                std::cin >> indice;

                if (indice >= 0 && indice < static_cast<int>(enemigosVivos.size())) {
                    h->atacar(enemigosVivos[indice]);
                    if (!enemigosVivos[indice]->estaVivo()) {
                        std::cout << enemigosVivos[indice]->getNombre() << " ha sido derrotado!\n";
                    }
                } else {
                    std::cout << "Índice inválido. Turno perdido.\n";
                }
            } else if (opcion == 2) {
                if (h->usarPocion()) {
                    std::cout << h->getNombre() << " usó una poción y recuperó vida.\n";
                } else {
                    std::cout << "No tienes pociones disponibles.\n";
                }
            } else {
                std::cout << h->getNombre() << " pasa el turno.\n";
            }

        } else if (p.tipo == Participante::ENEMIGO && p.enemigo->estaVivo()) {
            Enemigo* e = p.enemigo;
            std::vector<Heroe*> vivos;
            for (Heroe* h : heroes) {
                if (h->estaVivo()) vivos.push_back(h);
            }

            if (!vivos.empty()) {
                Heroe* objetivo = vivos[rand() % vivos.size()];
                e->atacar(objetivo);
                std::cout << e->getNombre() << " atacó a " << objetivo->getNombre() << ".\n";
                if (!objetivo->estaVivo()) {
                    std::cout << objetivo->getNombre() << " ha caído!\n";
                }
            }
        }
    }

    enemigos.erase(std::remove_if(enemigos.begin(), enemigos.end(),
        [](const std::unique_ptr<Enemigo>& e) { return !e->estaVivo(); }),
        enemigos.end());
}

if (enemigos.empty()) {
    std::cout << "¡Sala " << (salaActual + 1) << " completada con éxito!\n";
    salaActual++;
    return true;
} else {
    std::cout << "¡Todos los héroes han caído!\n";
    return false;
}
}

Mazmorra::Mazmorra() {
    for (int i = 0; i < 10; ++i) {
        std::string tipo = (i == 7) ? "MiniJefe" : (i == 9) ? "GranJefe" : "Normal";
        salas.emplace_back(tipo);

        if (tipo == "MiniJefe") {
            salas[i].agregarEnemigo(std::make_unique<MiniJefe>("Sombra Oscura", 90, 10, 6, 4, 5));
        } else if (tipo == "GranJefe") {
            salas[i].agregarEnemigo(std::make_unique<GranJefe>("Rey Zombi", 120, 12, 8, 5, 4));
        } else {
            // Elegir enemigos diferentes por sala (puedes variar más si querés)
            switch (i) {
                case 0:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Orco", 50, 7, 3, 2, 1));
                    break;
                case 1:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Duende", 40, 6, 2, 5, 3));
                    break;
                case 2:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Lich", 45, 8, 2, 3, 2));
                    break;
                case 3:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Bandido", 55, 6, 4, 4, 1));
                    break;
                case 4:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Esqueleto", 43, 7, 2, 4, 3));
                    break;
                case 5:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Murcielago", 38, 6, 1, 6, 4));
                    break;
                case 6:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Sombra", 52, 7, 4, 2, 1));
                    break;
                case 8:
                    salas[i].agregarEnemigo(std::make_unique<Soldado>("Zombi", 58, 6, 4, 2, 0));
                    break;
            }
        }
    }
}
