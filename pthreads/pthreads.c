/******************************************************************************
     * File: pthreads.c
     * Description: none
     * Created: 09 апреля 2021
     * Copyright: (C) Daniil Cherednichenko
     * Author: syth0le
     * Email: chdan565@gmail.com
     * description: 
******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <string.h>
#include <pthread.h>


void *threadHandler(void *ptr) {
    for (int j = 0; j < 10; ++j) {
        printf("привет, я процесс №%d\n", (int)syscall(SYS_gettid));
}
    printf("\n\n");
    pthread_exit(NULL);
    return NULL;
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(1);
    }

    int CHILDREN_AMOUNT = atoi(argv[1]);
    pid_t pids[CHILDREN_AMOUNT];

    for (int i = 0; i < CHILDREN_AMOUNT; ++i) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, threadHandler, NULL);
        pthread_join(thread_id, NULL);
    }
    return 0;
}
