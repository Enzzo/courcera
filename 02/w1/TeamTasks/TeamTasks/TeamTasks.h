#pragma once
#include "TaskStatusInfo.h"

class TeamTasks{
public:
	//ѕолучить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const std::string&)const;

	//ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчика
	void AddNewTask(const std::string&);

	//ќбновить статусы по данному количеству задач конкретного разработчика
	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string&, int);

private:
	std::map<std::string, TasksInfo> team;
};

//ѕолучить статистику по статусам задач конкретного разработчика
const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person)const {
	return team.at(person);
}

//ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчика
void TeamTasks::AddNewTask(const std::string& person) {
	team[person][TaskStatus::NEW]++;
}

//ќбновить статусы по данному количеству задач конкретного разработчика
std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const std::string& person, int task_count) {
	TasksInfo upd;
	TasksInfo untch = team[person];
	int total_counts = 0;

	for (const std::pair<TaskStatus, int> p : team[person]) {
		if(p.first != TaskStatus::DONE)
			total_counts += p.second;
	}

	if (task_count > total_counts) task_count = total_counts;

	while (task_count-- > 0) {
		if (team[person][TaskStatus::NEW] > 0) {
			team[person][TaskStatus::NEW]--;
			team[person][TaskStatus::IN_PROGRESS]++;
			untch[TaskStatus::NEW]--;
			upd[TaskStatus::IN_PROGRESS]++;

		}
		else if (team[person][TaskStatus::IN_PROGRESS] > 0) {
			team[person][TaskStatus::IN_PROGRESS]--;
			team[person][TaskStatus::TESTING]++;
			untch[TaskStatus::IN_PROGRESS]--;
			upd[TaskStatus::TESTING]++;

		}
		else if (team[person][TaskStatus::TESTING] > 0) {
			team[person][TaskStatus::TESTING]--;
			team[person][TaskStatus::DONE]++;
			untch[TaskStatus::TESTING]--;
			upd[TaskStatus::DONE]++;

		}
		else break;
	}
	
	if (untch[TaskStatus::NEW] <= 0)
		untch.erase(TaskStatus::NEW);
	if (untch[TaskStatus::IN_PROGRESS] <= 0)
		untch.erase(TaskStatus::IN_PROGRESS);
	if (untch[TaskStatus::TESTING] <= 0)
		untch.erase(TaskStatus::TESTING);
	if (untch[TaskStatus::DONE] >= 0)
		untch.erase(TaskStatus::DONE);
	
	if (team[person][TaskStatus::NEW] == 0)
		team[person].erase(TaskStatus::NEW);		
	
	if (team[person][TaskStatus::IN_PROGRESS] == 0) {
		team[person].erase(TaskStatus::IN_PROGRESS);
		upd.erase(TaskStatus::IN_PROGRESS);
	}
	if (team[person][TaskStatus::TESTING] == 0) {
		team[person].erase(TaskStatus::TESTING);
		upd.erase(TaskStatus::TESTING);
	}

	return tie(upd, untch);
}		