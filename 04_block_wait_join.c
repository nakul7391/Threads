#include <stdio.h>
#include <pthread.h>

struct Variables
{
   char c;
   int times;
};

void *thread_func(void * args)
{
    int i;

    printf("Thread ID(IN THREAD): %ld\n",pthread_self());

    // Typecast structure
    struct Variables * var = (struct Variables *)args;

    for(i = 0; i < var->times; i++)
    fputc(var->c,stderr);

    return NULL;
}

int main()
{
    pthread_t th1,th2;
    struct Variables v1,v2;

    v1.times = 1000;
    v2.times = 2000;
    v1.c = 'X';
    v2.c = '0';

    pthread_create(&th1,NULL,thread_func,&v1);
    pthread_create(&th2,NULL,thread_func,&v2);

    printf("Main Thread\n");
    printf("Thread ID1: %ld\n",th1);
    printf("Thread ID2: %ld\n",th2);

    // blocking call wait for two threads
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    return 0;
}
