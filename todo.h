#define TASK_SIZE 300
#define TRUE  1
#define FALSE 0

void println(char *str);
void addTask();
void printTasks();
void handleEndOfTask(char *task, int* is_end_of_task);