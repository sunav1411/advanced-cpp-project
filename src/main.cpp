#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class TaskManager {
private:
    vector<string> tasks;
public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "Task List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void saveTasksToFile() {
        ofstream file("tasks.txt");
        if (!file) {
            cout << "Error saving tasks.\n";
            return;
        }
        for (const auto& task : tasks) {
            file << task << endl;
        }
        file.close();
        cout << "Tasks saved to tasks.txt\n";
    }
};

int main() {
    TaskManager manager;
    manager.addTask("Complete GSoC Proposal");
    manager.addTask("Review Open Source Projects");
    manager.listTasks();
    manager.saveTasksToFile();
    return 0;
}
