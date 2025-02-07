#include <algorithm>
struct Task {
    bool done = false, removed = false;
    std::string literal;
    bool show(int pos = 0){
        if (removed) return false;
        cout << "\e[1m" << pos << "\e[0m ";
        if (done) cout << "\e[9m"+literal+"\e[0m" << endl;
        else cout << literal << endl;
        return true;
    }
};
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
