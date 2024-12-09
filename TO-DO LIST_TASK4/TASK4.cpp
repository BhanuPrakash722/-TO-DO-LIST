#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};


void displayMenu() {
    cout << "\n=== To-Do List Manager ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}


void addTask(vector<Task>& tasks) {
    cout << "Enter task description: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    tasks.emplace_back(desc);
    cout << "Task added successfully!\n";
}


void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n=== Task List ===\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}


void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }

    cout << "Enter the task number to mark as completed: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    }
}


void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }

    cout << "Enter the task number to remove: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager.😊!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}