#include <stdio.h>
#include <pthread.h>

#define NUM_INCREMENTS 100000

int shared_counter = 0;

//volatile int lock = 0;

// Função que será executada pela primeira thread
void* thread_function1(void* arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        //while (__atomic_test_and_set(&lock, __ATOMIC_ACQUIRE));
        shared_counter++;
        //lock = 0;
    }
    return NULL;
}

void* thread_function2(void* arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        //while (__atomic_test_and_set(&lock, __ATOMIC_ACQUIRE));
        shared_counter++;
        //lock = 0;
    }
    return NULL;
}

int main() {
    pthread_t threads[2];

    // Criar as threads
    pthread_create(&threads[0], NULL, thread_function1, NULL);
    pthread_create(&threads[1], NULL, thread_function2, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Final: %d\n", shared_counter);

    return 0;
}
