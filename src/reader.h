#pragma once
#include <fstream>
bool formatOut(const Task task, std::string *line);
bool formatIn(const std::string line, Task *task);
void loadTodo(const std::string path, std::vector<Task> *todo);
void flushTodo(const std::vector<Task> &todo, const std::string path);
