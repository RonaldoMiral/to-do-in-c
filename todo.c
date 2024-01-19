#include <stdio.h>
#include <stdlib.h>

#include "todo.h"

int main()
{
  /*
  println("*** TO DO LIST ***");
  println("1 - Add task");
  println("2 - Remove Task");
  println("3 - Edit Task");*/
  
  // char buffer[100]; // buffer para armazenar a linha lida

  // printf("Digite várias linhas (Ctrl+D para encerrar no Linux ou Ctrl+Z no Windows):\n");
  
  displayTasks();
  // addTask();
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

void displayTasks() {
  // alocating memory for the given task
  char** tasks = (char**) malloc(sizeof(char*) * 10);
  
  // Opening a our tasks database
  FILE *pFile = fopen("tasks.txt", "r");
  // Verifying if the database was opened successfully
  if(pFile == NULL) {
    perror("Error while trying to open the file\n");
  }
  
  while(fgets(task, TASK_SIZE, pFile) != NULL);
  println(task);
  
  fclose(pFile);
  free(task);
}