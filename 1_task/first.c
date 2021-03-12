/******************************************************************************
     * File: first.c
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
    printf("Current PID is: %d\nParent PID is: %d\n", getpid(), getppid());
    return 0; 
} 
