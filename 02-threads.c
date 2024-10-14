#include<stdio.h>
#include<pthread.h>

int count=0;

void* incrementCount(void* arg) { 
    while (count<100000000) {
        count++;
    }
}

int main(void) {
    pthread_t thread;

    pthread_create(&thread, NULL, incrementCount, NULL);

    // pthread_join(thread, NULL);
    
    printf("Final: %i \n", count);

    return 0;
}