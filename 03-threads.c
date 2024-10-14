#include<stdio.h>
#include<pthread.h>

#define NUM_THREADS 10
#define INCREMENTS 100000

int count=0;

void* incrementCount(void* arg) { 
    for (int i = 0; i < INCREMENTS; i++) {
        count++;
    }

    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, incrementCount, NULL) != 0) {
            perror("Erro ao criar thread");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Final: %i \n", count);

    return 0;
}