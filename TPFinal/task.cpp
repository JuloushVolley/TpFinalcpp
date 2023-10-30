#include "task.h"

Task::Task(const std::string& n, const std::string& p, int i, int nc, int d, const std::string& r)
    : name(n), path(p), interval(i), numCycles(nc), duration(d), resolution(r) {}

std::string Task::getName() const {
    return name;
}

std::string Task::getPath() const {
    return path;
}

int Task::getInterval() const {
    return interval;
}

int Task::getNumCycles() const {
    return numCycles;
}

int Task::getDuration() const {
    return duration;
}

std::string Task::getResolution() const {
    return resolution;
}

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::removeTask(int index) {
    if (index >= 0 && static_cast<size_t>(index) < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

const Task& TaskManager::getTask(int index) const {
    if (index >= 0 && static_cast<size_t>(index) < tasks.size()) {
        return tasks[index];
    }
    else {
        // Vous pouvez retourner une tâche par défaut ou lever une exception en cas d'index invalide.
    }
}

size_t TaskManager::getTaskCount() const {
    return tasks.size();
}
