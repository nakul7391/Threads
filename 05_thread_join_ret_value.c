#include <stdio.h>
#include <pthread.h>

struct Variables
{
   char c;
   int times;
   int retval;
};

void *thread_func(void * args)
{
    int i;

    printf("Thread ID(IN THREAD): %ld\n",pthread_self());

    // Typecast structure
    struct Variables * var = (struct Variables *)args;

    for(i = 0; i < var->times; i++)
    fputc(var->c,stderr);

    return (void *)(var->retval);
}

int main()
{
    pthread_t th1,th2;
    struct Variables v1,v2;

    v1.times = 1000;
    v2.times = 2000;
    v1.c = 'X';
    v2.c = '0';
    v1.retval = 1;
    v2.retval = 2;

    pthread_create(&th1,NULL,thread_func,&v1);
    pthread_create(&th2,NULL,thread_func,&v2);

    printf("Main Thread\n");
    printf("Thread ID1: %ld\n",th1);
    printf("Thread ID2: %ld\n",th2);

    int r1,r2;
    // Blocking call wait for two threads
    pthread_join(th1,(void **)&r1);
    pthread_join(th2,(void **)&r2);

    printf("Thread 1 retval: %d\n",r1);
    printf("Thread 2 retval: %d\n",r2);
    return 0;
}
