#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

// ========================= TaskNode (Linked List Node) =========================
struct TaskNode
{
    string taskName; // Task description
    string priority; // Task priority (High, Medium, Low)
    TaskNode *next;  // Pointer to the next task

    // Constructor to initialize a task
    TaskNode(string name, string pri) : taskName(name), priority(pri), next(nullptr) {}
};

// ========================= Linked List for Pending Tasks =========================
class TaskLinkedList
{
private:
    TaskNode *head;

public:
    // Constructor
    TaskLinkedList() : head(nullptr) {}

    // Add a new task
    void addTask(string taskName, string priority)
    {
        TaskNode *newNode = new TaskNode(taskName, priority);
        newNode->next = head;
        head = newNode;
    }

    // Complete a task and return its name
    string completeTask()
    {
        if (!head)
        {
            cout << "No tasks to complete!" << endl;
            return "";
        }
        TaskNode *temp = head;
        string taskName = temp->taskName;
        head = head->next;
        delete temp;
        return taskName;
    }

    // Display all tasks
    void displayTasks()
    {
        if (!head)
        {
            cout << "No pending tasks!" << endl;
            return;
        }
        cout << "Pending Tasks (Sorted by Priority):" << endl;
        for (TaskNode *current = head; current; current = current->next)
        {
            cout << "- " << current->taskName << " [" << current->priority << "]" << endl;
        }
    }

    // Sort tasks by priority (High > Medium > Low)
    void sortTasksByPriority()
    {
        if (!head || !head->next)
            return;

        for (TaskNode *i = head; i; i = i->next)
        {
            for (TaskNode *j = i->next; j; j = j->next)
            {
                if ((i->priority == "Medium" && j->priority == "High") ||
                    (i->priority == "Low" && j->priority != "Low"))
                {
                    swap(i->taskName, j->taskName);
                    swap(i->priority, j->priority);
                }
            }
        }
    }

    // Edit a task
    void editTask(string oldName, string newName)
    {
        for (TaskNode *current = head; current; current = current->next)
        {
            if (current->taskName == oldName)
            {
                current->taskName = newName;
                cout << "Task updated successfully!" << endl;
                return;
            }
        }
        cout << "Task not found!" << endl;
    }

    // Delete a task
    void deleteTask(string taskName)
    {
        if (!head)
        {
            cout << "No tasks to delete!" << endl;
            return;
        }

        if (head->taskName == taskName)
        {
            TaskNode *temp = head;
            head = head->next;
            delete temp;
            cout << "Task deleted successfully!" << endl;
            return;
        }

        TaskNode *current = head;
        while (current->next && current->next->taskName != taskName)
        {
            current = current->next;
        }

        if (current->next)
        {
            TaskNode *temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Task deleted successfully!" << endl;
        }
        else
        {
            cout << "Task not found!" << endl;
        }
    }

    // Get the head of the linked list (for saving tasks)
    TaskNode *getHead() const
    {
        return head;
    }
};

// ========================= Completed Tasks (STL List) =========================
class CompletedTaskList
{
private:
    list<string> completedTasks;

public:
    // Add a completed task
    void addCompletedTask(string taskName)
    {
        completedTasks.push_back(taskName);
    }

    // Display all completed tasks
    void displayCompletedTasks()
    {
        if (completedTasks.empty())
        {
            cout << "No completed tasks!" << endl;
            return;
        }
        cout << "Completed Tasks:" << endl;
        for (const string &task : completedTasks)
        {
            cout << "- " << task << endl;
        }
    }

    // Get the list of completed tasks (for saving tasks)
    const list<string> &getCompletedTasks() const
    {
        return completedTasks;
    }
};

// ========================= Task History (STL Vector) =========================
class TaskHistory
{
private:
    vector<string> taskHistory;

public:
    // Add a task to history
    void addTaskToHistory(string taskDescription)
    {
        taskHistory.push_back(taskDescription);
    }

    // Display task history
    void displayTaskHistory()
    {
        if (taskHistory.empty())
        {
            cout << "No task history available!" << endl;
            return;
        }
        cout << "Task History:" << endl;
        for (const string &task : taskHistory)
        {
            cout << "- " << task << endl;
        }
    }

    // Sort task history alphabetically
    void sortTaskHistory()
    {
        sort(taskHistory.begin(), taskHistory.end());
        cout << "Task history sorted alphabetically!" << endl;
    }
};

// ========================= File Operations =========================
// Save tasks to file
void saveTasksToFile(TaskNode *head, const list<string> &completedTasks, const string &filename)
{
    ofstream file(filename);
    if (!file)
    {
        cout << "Error saving tasks to file!" << endl;
        return;
    }

    // Save pending tasks
    file << "Pending Tasks:\n";
    for (TaskNode *current = head; current; current = current->next)
    {
        file << current->taskName << "," << current->priority << "\n";
    }

    // Save completed tasks
    file << "Completed Tasks:\n";
    for (const string &task : completedTasks)
    {
        file << task << "\n";
    }

    file.close();
    cout << "Tasks saved successfully!" << endl;
}

// Load tasks from file
void loadTasksFromFile(TaskLinkedList &pendingTasks, CompletedTaskList &completedTasks, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "No saved tasks found!" << endl;
        return;
    }

    string line;
    bool isCompleted = false;

    while (getline(file, line))
    {
        if (line == "Pending Tasks:")
        {
            isCompleted = false;
        }
        else if (line == "Completed Tasks:")
        {
            isCompleted = true;
        }
        else if (!line.empty())
        {
            if (!isCompleted)
            {
                size_t commaPos = line.find(',');
                string taskName = line.substr(0, commaPos);
                string priority = line.substr(commaPos + 1);
                pendingTasks.addTask(taskName, priority);
            }
            else
            {
                completedTasks.addCompletedTask(line);
            }
        }
    }

    file.close();
    cout << "Tasks loaded successfully!" << endl;
}

// ========================= Main Function =========================
int main()
{
    TaskLinkedList pendingTasks;
    CompletedTaskList completedTasks;
    TaskHistory taskHistory;
    string filename = "tasks.txt";

    // Load tasks from file
    loadTasksFromFile(pendingTasks, completedTasks, filename);

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Complete Task" << endl;
        cout << "3. Display Pending Tasks" << endl;
        cout << "4. Display Completed Tasks" << endl;
        cout << "5. Display Task History" << endl;
        cout << "6. Sort Tasks by Priority" << endl;
        cout << "7. Sort Task History Alphabetically" << endl;
        cout << "8. Save Tasks to File" << endl;
        cout << "9. Edit Task" << endl;
        cout << "10. Delete Task" << endl;
        cout << "11. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string taskName, priority;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, taskName);
            cout << "Enter priority (High/Medium/Low): ";
            cin >> priority;
            pendingTasks.addTask(taskName, priority);
            taskHistory.addTaskToHistory("Added: " + taskName);
            cout << "Task added successfully!" << endl;
        }
        else if (choice == 2)
        {
            string completedTask = pendingTasks.completeTask();
            if (!completedTask.empty())
            {
                completedTasks.addCompletedTask(completedTask);
                taskHistory.addTaskToHistory("Completed: " + completedTask);
                cout << "Task completed successfully!" << endl;
            }
        }
        else if (choice == 3)
        {
            pendingTasks.displayTasks();
        }
        else if (choice == 4)
        {
            completedTasks.displayCompletedTasks();
        }
        else if (choice == 5)
        {
            taskHistory.displayTaskHistory();
        }
        else if (choice == 6)
        {
            pendingTasks.sortTasksByPriority();
            cout << "Tasks sorted by priority!" << endl;
        }
        else if (choice == 7)
        {
            taskHistory.sortTaskHistory();
        }
        else if (choice == 8)
        {
            saveTasksToFile(pendingTasks.getHead(), completedTasks.getCompletedTasks(), filename);
        }
        else if (choice == 9)
        {
            string oldName, newName;
            cout << "Enter the current task name: ";
            cin.ignore();
            getline(cin, oldName);
            cout << "Enter the new task name: ";
            getline(cin, newName);
            pendingTasks.editTask(oldName, newName);
        }
        else if (choice == 10)
        {
            string taskName;
            cout << "Enter task name to delete: ";
            cin.ignore();
            getline(cin, taskName);
            pendingTasks.deleteTask(taskName);
        }
        else if (choice == 11)
        {
            saveTasksToFile(pendingTasks.getHead(), completedTasks.getCompletedTasks(), filename);
            cout << "Exiting program. Tasks saved!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
