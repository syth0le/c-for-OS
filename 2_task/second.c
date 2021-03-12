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
