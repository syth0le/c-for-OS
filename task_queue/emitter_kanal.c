/******************************************************************************
     * File: emitter_kanal.c
     * Description: program realisation PIPE
     * Created: 09 апреля 2021
     * Copyright: (C) Daniil Cherednichenko
     * Author: syth0le
     * Email: chdan565@gmail.com 
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


double calculate(double x, double y, char operation)
{
  double res;
  switch (operation) 
  {
  case '+':
  {
    res = x + y;
    break;
  }
  case '-':
  {
    res = x - y;
    break;
  }
  case '/': 
  {
    if (y != 0)
      res = x / y; 
    else
      res = 0;
    break;
  }
  case '*':
  {
    res = x * y;
    break;
  }
  case '^': 
  {
    res = 1;
    for (int i = 0; i < y; i++)
      res = res * x; 
    break;
  }
  case '!':
  {
    res = 1;
    if (y >= 0)
      for (int i = y; i != 1; i--)
        res = res * i;
    else
      res = 0;
    break;
  }
  }
  return res;
}

int main(int argc, char *argv[])
{
  int fd[2]; // file descriptors init

  if (pipe(fd) == -1)
  {
    printf("An error occured with opening the pipe\n");
    return 1;
  }

  int pid = fork();
  if (pid == -1)
  {
    printf("An error occured with fork\n");
    return 2;
  }
  if (pid == 0)
  {
    close(fd[0]);
    double a, b;
    char operation;

    printf("Input a first number: ");
    scanf("%lf", &a);

    printf("Input a second number: ");
    scanf("%lf", &b);

    printf("Input an operation: ");
    scanf(" %c", &operation);

    if (write(fd[1], &a, sizeof(double)) == -1)
    {
      printf("An error occured with writing to the pipe\n");
      return 3;
    }

    if (write(fd[1], &b, sizeof(double)) == -1)
    {
      printf("An error occured with writing to the pipe\n");
      return 4;
    }

    if (write(fd[1], &operation, sizeof(char)) == -1)
    {
      printf("An error occured with writing to the pipe\n");
      return 5;
    }

    close(fd[1]);
  }
  else
  {

    close(fd[1]);

    double x, y;
    char recieved_operation;

    if (read(fd[0], &x, sizeof(double)) == -1)
    {
      printf("An error occured with reading from the pipe\n");
      return 6;
    }

    if (read(fd[0], &y, sizeof(double)) == -1)
    {
      printf("An error occured with reading from the pipe\n");
      return 6;
    }

    if (read(fd[0], &recieved_operation, sizeof(char)) == -1)
    {
      printf("An error occured with reading from the pipe\n");
      return 6;
    }

    close(fd[0]);
    printf("%.2lf %c %.2lf = %.2lf\n", x, recieved_operation, y, calculate(x, y, recieved_operation));
  }
}
