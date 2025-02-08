#include <unordered_map>
#include <iostream>
using std::cout, std::cerr, std::endl;
#include <vector>
#include "logic.cc"
#include "reader.cc"
#include "error.cc"

int main(int argc, char **argv){
    std::string path = getenv("HOME");
    path += "/.todo";
    std::vector<Task> todo;
    loadTodo(path, &todo);

    if (argc < 2){
        listTodo(todo);
        return 0;
    }
    
    std::string command = argv[1];
    std::unordered_map<std::string,std::string> aliases = {
        {"l", "list"}, {"a", "add"}, {"d", "done"},
        {"u", "undo"}, {"r", "rm"}, {"s", "sort"}, {"h", "help"}
    };
    if (aliases.count(command)){
        command = aliases[command];
    }
    
    std::vector<std::string> tasks;
    std::vector<int> indexes;
    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        try {
            indexes.push_back(std::stoi(arg));
        } catch (...) {
            tasks.push_back(arg);
        }
    }
    
    if (command == "list"){
        if (indexes.size() || tasks.size()){
            error(command, ErrorType::TOO_MANY_ARGS);
            return 1;
        }
        listTodo(todo);
        return 0;
    } else if (command == "add"){
        if (tasks.empty()){
            error(command, ErrorType::NO_ARGS);
            return 1;
        }
        addTasks(tasks, &todo);
    } else if (command == "done"){
        if (indexes.empty()) {
            error(command, ErrorType::NO_ARGS);
            return 1;
        }
        markDone(indexes, &todo);
    } else if (command == "undo"){
        if (indexes.empty()) {
            error(command, ErrorType::NO_ARGS);
            return 1;
        }
        unmarkDone(indexes, &todo);
    } else if (command == "rm"){
        if (indexes.empty()) {
            error(command, ErrorType::NO_ARGS);
            return 1;
        }
        removeTasks(indexes, &todo);
    } else if (command == "sort"){
        if (indexes.size() || tasks.size()){
            error(command, ErrorType::TOO_MANY_ARGS);
            return 1;
        }
        sortTodo(&todo);
    } else if (command == "help"){
        cout << "refer to README (man page in production)\n";
        return 0;
    } else {
        error(command, ErrorType::UNKNOWN_COMMAND);
        return 1;
    }
    flushTodo(todo, path);
}
