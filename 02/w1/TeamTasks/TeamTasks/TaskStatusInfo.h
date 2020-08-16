#include <map>
#include <string>
#include <tuple>

enum class TaskStatus {
	NEW,			//новая
	IN_PROGRESS,	//в разработке
	TESTING,		//на тестировании
	DONE			//завершена
};

using TasksInfo = std::map<TaskStatus, int>;