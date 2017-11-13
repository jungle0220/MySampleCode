#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *thread_D() {
    // pthread_t thread_D_num;
    long log_time;

    // pthread_create(&thread_D_num, NULL, thread_D, NULL);
    while(1) {
        log_time = time(NULL);
        // fprintf(stderr,"[Ken] %s %d time = %ld \n", __FUNCTION__, __LINE__,log_time);
        fprintf(stderr,"                     DDDD\n");
    }
}

void *thread_C() {
    pthread_t thread_D_num;
    long log_time;

    pthread_create(&thread_D_num, NULL, thread_D, NULL);
    while(1) {
        log_time = time(NULL);
        // fprintf(stderr,"[Ken] %s %d time = %ld \n", __FUNCTION__, __LINE__,log_time);
        fprintf(stderr,"                CCCC\n");
    }
}

void *thread_B() {
    pthread_t thread_C_num;
    long log_time;

    pthread_create(&thread_C_num, NULL, thread_C, NULL);
    while(1) {
        log_time = time(NULL);
        // fprintf(stderr,"[Ken] %s %d time = %ld \n", __FUNCTION__, __LINE__,log_time);
        fprintf(stderr,"           BBBB\n");
    }
}

void *thread_A() {
    pthread_t thread_B_num;
    long log_time;

    pthread_create(&thread_B_num, NULL, thread_B, NULL);
    while(1) {
        log_time = time(NULL);
        // fprintf(stderr,"[Ken] %s %d time = %ld \n", __FUNCTION__, __LINE__,log_time);
        fprintf(stderr,"      AAAA\n");
    }
}

int main() {
    pthread_t thread_A_num;
    long log_time;

    pthread_create(&thread_A_num, NULL, thread_A, NULL);
    while(1) {
        log_time = time(NULL);
        // fprintf(stderr,"[Ken] %s %d time = %ld \n", __FUNCTION__, __LINE__,log_time);
        fprintf(stderr,"MMMM\n");
    }

    return 0;
}
