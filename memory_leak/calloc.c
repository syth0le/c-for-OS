#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char * memory_for_eaten;
    size_t bytes = (1024*1024*100);
    int used = 0;
    for (;;) {
        memory_for_eaten = (char * )calloc(1, bytes);
        if (memory_for_eaten == NULL) {
            printf("\nTotal eaten memory: %i MB\n", used / 1024);
            exit(-1);
        }
        used += 100;
        printf("USED: %d MB\n", used / 1024);
    }
    return 0;
}