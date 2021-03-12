/******************************************************************************
     * File: reciever.c
     * Description: none
     * Created: 12 марта 2021
     * Copyright: (C) Daniil Cherednichenko
     * Author: syth0le
     * Email: chdan565@gmail.com
     * description: command for run reciever: gcc receiver.c -o r && ./r
******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

char str[40] = "Wait for signal...\n"; 

// обраотчик сигналов
void signalHandler(int signalCode)
{
  switch (signalCode)
  {
  case SIGUSR1:
    printf("SIGUSR1 Recieved\n");
    strcpy(str, "Last received signal is: SIGUSR1\n"); // redefinition of start string
    break;
  case SIGUSR2:
    printf("SIGUSR2 Recieved\n");
    strcpy(str, "Last received signal is: SIGUSR2\n"); // redefinition of start string
    break;
  }
}

int main()
{
  // registration of signals
  signal(SIGUSR1, signalHandler);
  signal(SIGUSR2, signalHandler);
  printf("[ PID: %d ]: Started...\n", getpid());
  while (1)
  {
    printf("%s", str);
    sleep(2);
  }
  return 0;
}