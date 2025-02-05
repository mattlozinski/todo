#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;
void showHelp(){
    cout << "Simple todo with saving to file\n";
    cout << "Usage: todo [command] [arguments]\n";
    cout << "\n";
    cout << "Available commands:\n";
    cout << "- list, l\n";
    cout << "   shows all tasks\n";
    cout << "   default, when no command given\n";
    cout << "- add, a\n";
    cout << "   adds tasks separated by space\n";
    cout << "- done, d\n";
    cout << "   marks tasks with given indexes as done\n";
    cout << "- undo, u\n";
    cout << "   unmarks tasks with given indexes as done\n";
    cout << "- rm, r\n";
    cout << "   removes tasks with given indexes\n";
    cout << "- sort, s\n";
    cout << "   sorts all task by status, uncompleted first\n";
    cout << "- help, h\n";
    cout << "   show this help message\n";
    cout << "\n";
    cout << "Examples:\n";
    cout << "   todo add \"clean the house\" milk oranges\n";
    cout << "   todo done 2 3\n";
    cout << "   todo rm 1\n";
    cout << "\n";
}
std::string path = getenv("HOME");
struct Task {
    bool status;
    std::string value;
    bool operator <(Task tmp){
        return status < tmp.status;
    }
};
std::vector<Task> tasks;

void readFile(){
    path += "/.todo";
    std::ifstream file(path);
    if (!file) return;
    std::string line;
    while (getline(file, line)){
        if (line.size() < 4) continue;
        if (line.substr(0, 4) == "[x] "){
            tasks.push_back({true, line.substr(4)});
        }
        else if (line.substr(0, 4) == "[ ] "){
            tasks.push_back({false, line.substr(4)});
        }
    }
    file.close();
}

std::string formatTask(Task task){
    if (task.status == true) return "[x] "+task.value;
    else return "[ ] "+task.value;
}

std::string strike(const std::string text){
    return "\e[3m"+text+"\e[0m";
}
void listTasks(){
    for (int i=0; i<tasks.size(); i++){
        cout << "\e[1m" << i+1 << "\e[0m ";
        if (tasks[i].status){
            cout << "\e[9m"+tasks[i].value+"\e[0m\n";
        } else {
            cout << tasks[i].value << endl;
        }
    }
}   
void rewriteTasks(const bool removed[], bool removing = false){
    std::ofstream file(path);
    if (removing){
        for (int i=0; i<tasks.size(); i++)
            if (!removed[i]) file << formatTask(tasks[i]) << endl;
    } else {
        for (auto t: tasks)
            file << formatTask(t) << endl;
    }
}

void sortTasks(){
    std::sort(tasks.begin(), tasks.end());
    rewriteTasks({});
}
void addTasks(const std::vector<std::string> todo){
    for (auto t: todo){
        tasks.push_back({false, t});
    }
    rewriteTasks({});
}
void markTasks(const std::vector<int> indexes){
    for (auto t: indexes){
        if (t > 0 && t <= tasks.size()){
            tasks[t-1].status = true;
        }
    }
    rewriteTasks({});
}
void unmarkTasks(const std::vector<int> indexes){
    for (auto t: indexes){
        if (t > 0 && t <= tasks.size()){
            tasks[t-1].status = false;
        }
    }
    rewriteTasks({});
}
void removeTasks(const std::vector<int> indexes){
    bool removed[tasks.size()]{};
    for (auto t: indexes){
        if (t > 0 && t <= tasks.size()){
            removed[t-1] = true;
        }
    }
    rewriteTasks(removed, true);
}

int main(int argc, char **argv){
    readFile();
    if (argc == 1) listTasks();
    if (argc == 2){
        std::string command = argv[1];
        if (command == "list" || command == "l") listTasks();
        else if (command == "sort" || command == "s") sortTasks();
        else showHelp();
    }
    if (argc > 2){
        std::string command = argv[1];
        if (command == "add" || command =="a"){
            std::vector<std::string> todo;
            for (int i=2; i<argc; i++){
                todo.push_back(argv[i]);
            }
            addTasks(todo);
        }
        else if (command == "done" || command =="d"){
            std::vector<int> indexes;
            for (int i=2; i<argc; i++){
                indexes.push_back(atoi(argv[i]));
            }
            markTasks(indexes);
        }
        else if (command == "undo" || command =="u"){
            std::vector<int> indexes;
            for (int i=2; i<argc; i++){
                indexes.push_back(atoi(argv[i]));
            }
            unmarkTasks(indexes);
        }
        else if (command == "rm" || command =="r"){
            std::vector<int> indexes;
            for (int i=2; i<argc; i++){
                indexes.push_back(atoi(argv[i]));
            }
            removeTasks(indexes);
        }
        else showHelp();
    }
}
