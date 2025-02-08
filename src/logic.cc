#include <algorithm>
#include "logic.h"
void sortTodo(std::vector<Task> *todo){
    std::sort(todo->begin(), todo->end(), [](const Task &a, const Task &b){
        return a.done < b.done;
    });
}
void listTodo(const std::vector<Task> &todo){
    int pos = 1;
    for (auto task: todo){
        if (task.show(pos)) pos++;
    }
}
void addTasks(const std::vector<std::string> &tasks, std::vector<Task> *todo){
    for (const auto &task: tasks){
        Task curr; curr.literal = task;
        todo -> push_back(curr);
    }
}
void markDone(const std::vector<int> &indexes, std::vector<Task> *todo){
    for (auto i: indexes){
        if (i > 0 && i <= todo -> size()){
            (*todo)[i-1].done = true;
        }
    }
}
void unmarkDone(const std::vector<int> &indexes, std::vector<Task> *todo){
    for (auto i: indexes){
        if (i > 0 && i <= todo -> size()){
            (*todo)[i-1].done = false;
        }
    }
}
void removeTasks(const std::vector<int> &indexes, std::vector<Task> *todo){
    for (auto i: indexes){
        if (i > 0 && i <= todo -> size()){
            (*todo)[i-1].removed = true;
        }
    }
}
