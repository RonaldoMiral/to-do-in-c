#define TASK_SIZE 300
#define TRUE  1
#define FALSE 0

void println(char *str);
void addTask();
void printTasks();
void handleEndOfTaskOnPrint(char *task, int* is_end_of_task);
void checkingTaskBeforeAdding(char* task);