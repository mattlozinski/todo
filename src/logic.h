#include "colorizer.h"
#pragma once
struct Task {
    bool done = false, removed = false;
    std::string literal;
    bool show(int pos = 0){
        if (removed) return false;
        cout << style::bold(std::to_string(pos)) << " ";
        if (done) cout << style::strike(literal) << endl;
        else cout << literal << endl;
        return true;
    }
};
void sortTodo(std::vector<Task> *todo);
void listTodo(const std::vector<Task> &todo);
void addTasks(const std::vector<std::string> &tasks, std::vector<Task> *todo);
void markDone(const std::vector<int> &indexes, std::vector<Task> *todo);
void unmarkDone(const std::vector<int> &indexes, std::vector<Task> *todo);
void removeTasks(const std::vector<int> &indexes, std::vector<Task> *todo);
