#include<iostream>
#include<string>
using namespace std;

const int MAX_TASKS = 100;

class Task {
public:
    string description;
    bool completed;
    Task() : description(""), completed(false) {}
    Task(string desc) : description(desc), completed(false) {}
    void markCompleted() {
	 completed = true; 
	 }
    void display(int index) {
        cout << index + 1 << ". " << (completed ? "[?] " : "[ ] ") << description << endl;
    }
};

class ToDoList {
private:
    Task tasks[MAX_TASKS];
    int taskCount;
public:
    ToDoList() : taskCount(0) {}
    
    void addTask() {
        if (taskCount >= MAX_TASKS) {
            cout << "Task List Is Full! Cannot Add More Tasks.\n";
            return;
        }
        cout << "Enter Task Description: ";
        cin.ignore();
        getline(cin, tasks[taskCount].description);
        tasks[taskCount].completed = false;
        taskCount++;
        cout << "Task Added Successfully!\n";
    }
    
    void viewTasks() {
        if (taskCount == 0) {
            cout << "\nNo Tasks Available.\n";
            return;
        }
        cout << "\nTo-Do List:\n";
        for (int i = 0; i < taskCount; i++) {
            tasks[i].display(i);
        }
    }
    
    void completeTask() {
        if (taskCount == 0) {
            cout << "\nNo Tasks Available To Complete.\n";
            return;
        }
        viewTasks();
        int num;
        cout << "\nEnter Task Number To Complete: ";
        cin >> num;
        if (num > 0 && num <= taskCount) {
            tasks[num - 1].markCompleted();
            cout << "\nTask Marked As Completed!\n";
        } else {
            cout << "\nInvalid Task Number!\n";
        }
    }
    
    void removeTask() {
        if (taskCount == 0) {
            cout << "\nNo Tasks Available To Delete.\n";
            return;
        }
        viewTasks();
        int num;
        cout << "\nEnter Task Number To Delete: ";
        cin >> num;
        if (num > 0 && num <= taskCount) {
            for (int i = num - 1; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            cout << "\nTask Deleted Successfully!\n";
        } else {
            cout << "\nInvalid Task Number!\n";
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task As Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            todo.addTask();
            break;
        case 2:
            todo.viewTasks();
            break;
        case 3:
            todo.completeTask();
            break;
        case 4:
            todo.removeTask();
            break;
        case 5:
            cout << "Exiting The Program...\n";
            break;
        default:
            cout << "Invalid Choice! Try Again.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
