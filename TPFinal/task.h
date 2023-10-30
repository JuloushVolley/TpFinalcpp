#include <string>
#include <vector>

class Task {
public:
    Task(const std::string& name, const std::string& path, int interval, int numCycles, int duration, const std::string& resolution);

    std::string getName() const;
    std::string getPath() const;
    int getInterval() const;
    int getNumCycles() const;
    int getDuration() const;
    std::string getResolution() const;

private:
    std::string name;
    std::string path;
    int interval;
    int numCycles;
    int duration;
    std::string resolution;
};

class TaskManager {
public:
    void addTask(const Task& task);
    void removeTask(int index);
    const Task& getTask(int index) const;
    size_t getTaskCount() const;

private:
    std::vector<Task> tasks;
};