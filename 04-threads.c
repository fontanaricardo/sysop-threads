#include<stdio.h>
#include<pthread.h>

#define NUM_THREADS 10
#define INCREMENTS 100000

int count=0;
pthread_mutex_t mutex;

void* incrementCount(void* arg) { 
    for (int i = 0; i < INCREMENTS; i++) {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

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

    pthread_mutex_destroy(&mutex);
    return 0;
}