#include <stdio.h>
#include <pthread.h>

void *helper(void *arg) {
    printf("HELPER\n");
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, helper, NULL);  // start helper
    pthread_join(thread, NULL);                   // wait for helper to finish
    printf("MAIN\n");
    return 0;
}
