#include <stdio.h>      // for printf
#include <stdlib.h>     // for malloc, free
#include <string.h>     // for strcpy
#include <pthread.h>    // for pthread_t, pthread_create, pthread_join

void *helper(void *arg) {
    char *message = (char *) arg;
    strcpy(message, "I am the child");
    return NULL;
}

int main() {
    char *message = (char *)malloc(100);
    strcpy(message, "I am the parent");
    pthread_t thread;
    pthread_create(&thread, NULL, &helper, message);
    pthread_join(thread, NULL);
    printf("%s\n", message);
    free(message);   // free heap memory
    return 0;
}
