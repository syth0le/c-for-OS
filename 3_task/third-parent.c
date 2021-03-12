/******************************************************************************
     * File: third-parent.c
     * Description: none
     * Created: 12 марта 2021
     * Copyright: (C) Daniil Cherednichenko
     * Author: syth0le
     * Email: chdan565@gmail.com
******************************************************************************/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    printf("MESSAGE FROM third-parent.c\n");
    printf("PID of old process is: %d\n", getpid());
    char *args[] = {"Hello", "Man", NULL};
    execv("./third-daughter.c", args);
    return 0; 
}
