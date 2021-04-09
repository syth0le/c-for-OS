#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <string.h>
#include <pthread.h>

int result = 0;
pthread_mutex_t lock;

void *threadHandler(void *ptr) {
    pthread_mutex_lock(&lock);
    for (int k = 0; k < 10; k++) {
	printf("%li ", *((long*)ptr));
    	for (int j = 0; j < 1000000; ++j) {	
	    result++;
	}
    }
    pthread_mutex_unlock(&lock);
    pthread_exit(0);
    return NULL;
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(1);
    }

    int THREADS = atoi(argv[1]);
    pthread_t threads[THREADS];

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
	printf("\n mutex init failed\n");
	return 1;
    }

   // int THREADS = atoi(argv[1]);
   // pthread_t threads[THREADS];

    for (int i = 0; i < THREADS; ++i) {
        long *s = malloc(sizeof(s));
	*s = i;
	pthread_create(&threads[i], NULL, threadHandler, s);
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);

    printf("Result is %d\n", result);
    return 0;
}
