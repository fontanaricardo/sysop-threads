#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int delayInt = 2;

void signalTermHandler(int signal) {
    printf("Signal %d...\n", signal);
    printf("Finishing...\n");
    exit(0);
}

void signalTermStopHandler(int signal) {
    printf("Signal %d...\n", signal);
    printf("Terminal stop (Ctrl+Z)...\n");
}

void signalContinuepHandler(int signal) {
    printf("Signal %d...\n", signal);
    printf("Continue...\n");
}

int main(void) {
    signal(SIGTERM, signalTermHandler);
    signal(SIGTSTP, signalTermStopHandler);
    signal(SIGCONT, signalContinuepHandler);
    
    signalHungUpHandler(SIGHUP);
 
    printf("Started (PID %d)...\n", getpid());

    while (1) {
        sleep(delayInt);
    }

    return 0;
}