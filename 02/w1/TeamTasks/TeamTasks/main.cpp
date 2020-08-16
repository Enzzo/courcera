#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "TeamTasks.h"
using namespace std;

void PrintTasksInfo(TasksInfo tasks_info) {
	std::cout << tasks_info[TaskStatus::NEW] << " new tasks, "
		<< tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress, "
		<< tasks_info[TaskStatus::TESTING] << " tasks are beginning tested, "
		<< tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}
ostream& operator <<(ostream& out, const TaskStatus& status) {
    string statusName;
    switch (status) {
    case TaskStatus::NEW:
        statusName = "\"NEW\"";
        break;
    case TaskStatus::IN_PROGRESS:
        statusName = "\"IN_PROGRESS\"";
        break;
    case TaskStatus::TESTING:
        statusName = "\"TESTING\"";
        break;
    case TaskStatus::DONE:
        statusName = "\"DONE\"";
        break;
    }
    return out << statusName;
}

template <typename Collection>
string Join(const Collection& c, const string& d) {
    stringstream ss;
    bool isFirst = true;
    for (const auto& i : c) {
        if (!isFirst) {
            ss << d;
        }
        isFirst = false;
        ss << i;
    }
    return ss.str();
}
template <typename F, typename S>
ostream& operator <<(ostream& out, const pair<F, S>& p) {
    return out << p.first << ": " << p.second;
}
template <typename K, typename V>
ostream& operator <<(ostream& out, const map<K, V>& m) {
    return out << '{' << Join(m, ", ") << '}';
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    return out << '[' << Join(v, ", ") << ']';
}

int main() {
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    istream &is = ifs;
    ostream& os = ofs;
    TeamTasks tasks;
    while (is) {
        string command, person;
        int num;
        is >> command >> person;
        if (command == "AddNewTasks") {
            is >> num;
            while (num--)
                tasks.AddNewTask(person);
            ofs << "[]" << endl;
        }
        else if (command == "PerformPersonTasks") {
            is >> num;
            TasksInfo updated_tasks, untouched_tasks;
            tie(updated_tasks, untouched_tasks) =
                tasks.PerformPersonTasks(person, num);
            ofs << vector<TasksInfo>{updated_tasks, untouched_tasks } << endl;
        }
        else if (command == "GetPersonTasksInfo") {
            ofs << tasks.GetPersonTasksInfo(person) << endl;
        }
        else if (command.size() && command[0] != '#') {
            throw invalid_argument("wrong command: " + command);
        }
    }
    
    return 0;
}