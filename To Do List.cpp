/* 

A simple console-based to-do list
manager that allows users to add, view, and
delete tasks

*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class Codsofttodolist {
private:
    vector<Task> tasks;

public:
    void addtheTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewtheTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i+1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }

    void marktheTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removetheTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    Codsofttodolist Codsofttodolist;
    char choice;

    do {
        cout << "\n Hi Welcome To The CodSoft To Do List Program By Aditya   \n";
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string task;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, task);
                Codsofttodolist.addtheTask(task);
                break;
            }
            case '2':
                Codsofttodolist.viewtheTasks();
                break;
            case '3': {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                Codsofttodolist.marktheTaskAsCompleted(index);
                break;
            }
            case '4': {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                Codsofttodolist.removetheTask(index);
                break;
            }
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
