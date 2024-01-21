#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

int main()
{
  println("*** TO DO LIST ***");
  println("1 - Add task");
  println("2 - Remove Task");
  println("3 - Edit Task");
  
  int option;
  // char buffer[100]; // buffer para armazenar a linha lida

  // printf("Digite várias linhas (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):\n");
  
  printTasks();
  /*
  printf(">> ");
  scanf("%d", &option);
  
  if(option == 1) {
    addTask();
    displayTasks();
  }*/
  
  return 0;
}


void println(char *str) { printf("%s\n", str); }

void addTask() {
  // alocating memory for the given task
  char *task = (char *) malloc(TASK_SIZE);
  
  // Opening a our tasks database
  FILE *pFile = fopen("tasks.txt", "a");
  // Verifying if the database was opened successfully
  if(pFile == NULL) {
    perror("Error while trying to open the file\n");
  }
  
  println("Type in (ctrl D to exit writin mode):");
  // Reading line by line the user entry.
  while (fgets(task, sizeof(TASK_SIZE), stdin) != NULL) {
    fprintf(pFile, "%s", task);
  }
  // Represent the end of a task
  fprintf(pFile, ";");
  
  fclose(pFile);
  free(task);
}

void printTasks() {
  // Allocating space for a line of a task
  char* task = malloc(TASK_SIZE);
  
  // Opening a our tasks database
  FILE *pFile = fopen("tasks.txt", "r");
  // Verifying if the database was opened successfully
  if(pFile == NULL) {
    perror("Error while trying to open the file\n");
  }
  
  // Read and handles each line from task.txt file
  while(fgets(task, TASK_SIZE, pFile) != NULL) {
    int is_end_of_task = FALSE;
    
    handleEndOfTask(task, &is_end_of_task);
    
    printf("%s", task);
    
    if(is_end_of_task) printf("\n\n");
  }
  
  fclose(pFile);
  free(task);
}

void handleEndOfTask(char *task, int* is_end_of_task)
{
  int line_length = strlen(task);
  
  if(task[line_length - 2] == ';') {
    task[line_length - 2] = 0;
    *is_end_of_task = TRUE;
  }
}