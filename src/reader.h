#include <fstream>
bool formatOut(const Task task, std::string *line){
    if (task.removed) return false;
    if (task.done){
        *line = "[x] "+task.literal+"\n";
    } else {
        *line = "[ ] "+task.literal+"\n";
    }
    return true;
}
bool formatIn(const std::string line, Task *task){
    if (line.size() < 5) return false;
    if (line.substr(0, 4) == "[x] ") task -> done = true;
    else if (line.substr(0, 4) == "[ ] ") task -> done = false;
    else return false;
    task -> literal = line.substr(4);
    return true;
}
void loadTodo(const std::string path, std::vector<Task> *todo){
    std::ifstream file(path);
    std::string line;
    while (getline(file, line)){
        Task task;
        if (formatIn(line, &task)){
            todo -> push_back(task);
        }
    }
    file.close();
}
void flushTodo(const std::vector<Task> &todo, const std::string path){
    std::ofstream file(path);
    std::string line;
    for (auto task: todo){
        if (formatOut(task, &line)){
            file << line;
        }
    }
}
