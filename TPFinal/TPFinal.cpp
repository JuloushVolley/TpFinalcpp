#include <iostream>
#include "task.h"
#include <windows.h>

void simulateMouseClick(int x, int y) {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dx = (x * 65536) / GetSystemMetrics(SM_CXSCREEN);
    input.mi.dy = (y * 65536) / GetSystemMetrics(SM_CYSCREEN);
    input.mi.mouseData = 0;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN; // Clic gauche enfoncé
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dx = (x * 65536) / GetSystemMetrics(SM_CXSCREEN);
    input.mi.dy = (y * 65536) / GetSystemMetrics(SM_CYSCREEN);
    input.mi.mouseData = 0;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP; // Relâcher le clic gauche
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "Options:\n";
        std::cout << "1. Ajouter une tache\n";
        std::cout << "2. Supprimer une tache\n";
        std::cout << "3. Lister les taches\n";
        std::cout << "4. Executer les taches\n"; // Ajout d'une option pour exécuter les taches
        std::cout << "5. Quitter\n";
        std::cout << "Choisissez une option : ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string name, path, resolution;
            int interval, numCycles, duration;

            std::cout << "Nom de la tache : ";
            std::cin >> name;
            std::cout << "Chemin de la tache : ";
            std::cin >> path;
            std::cout << "Intervalle : ";
            std::cin >> interval;
            std::cout << "Nombre de cycles : ";
            std::cin >> numCycles;
            std::cout << "Duree : ";
            std::cin >> duration;
            std::cout << "Resolution d'origine : ";
            std::cin >> resolution;

            Task task(name, path, interval, numCycles, duration, resolution);
            taskManager.addTask(task);
            std::cout << "Tache ajoutee avec succes.\n";
        }
        else if (choice == 2) {
            int index;
            std::cout << "Indice de la tache à supprimer : ";
            std::cin >> index;

            if (index >= 0 && static_cast<size_t>(index) < taskManager.getTaskCount()) {
                taskManager.removeTask(index);
                std::cout << "Tache supprimee avec succes.\n";
            }
            else {
                std::cout << "Indice de tache invalide.\n";
            }
        }
        else if (choice == 3) {
            size_t taskCount = taskManager.getTaskCount();

            if (taskCount > 0) {
                std::cout << "Liste des taches :\n";
                for (size_t i = 0; i < taskCount; ++i) {
                    const Task& task = taskManager.getTask(i);
                    std::cout << "Tache " << i << " - Nom : " << task.getName() << ", Chemin : " << task.getPath() << ", Intervalle : " << task.getInterval()
                        << ", Cycles : " << task.getNumCycles() << ", Duree : " << task.getDuration() << ", Resolution : " << task.getResolution() << "\n";
                }
            }
            else {
                std::cout << "Aucune tache enregistrée.\n";
            }
        }
        else if (choice == 4) {
            size_t taskCount = taskManager.getTaskCount();
            int i;
            std::cout << "Indice de la tache : ";
            std::cin >> i ;
           
            const Task& task = taskManager.getTask(i);
                for (int cycle = 0; cycle < task.getNumCycles(); ++cycle) {
                    simulateMouseClick(500, 500);
                    Sleep(task.getInterval());
                }
            std::cout << "la tache a ete executee avec succes.\n";
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Option invalide. Réessayez.\n";
        }
    }

    return 0;
}
