/******************************************************************************
     * File: second.c
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
	switch(fork())
	{
	case 0:
		printf("Daughter process, my PID is: %d\n", getpid());
		break;
	default:
		printf("Parent process, my PID is %d\n", getpid());
		break;
	}
	return 0;
}
