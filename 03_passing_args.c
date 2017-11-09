/*
 * Program to show passing of Variables
 * between main function and thread
 * at the time of create
*/

#include <stdio.h>
#include <pthread.h>

struct Variables
{
    char c;
    int times;
};

// Thread function

/*
 * Make it void * here so that function pointer will be as per declaration
 * typecast in the function
*/

void * thread_func(void * arg)
{
    // Print ID of the thread
    struct Variables * var = (struct Variables *)arg;

    printf("Thread ID(IN THREAD): %ld\n",pthread_self());
    int i;
    // print something times times
    for(i = 0; i < var->times; i++)
    {
        fputc(var->c,stderr);
    }

    return NULL;
}

int main()
{
    pthread_t th1, th2;
    // Set values
    struct Variables v1,v2;

    v1.c = 'X';
    v1.times = 1000;

    v2.c = '0';
    v2.times = 3000;


    // Create threads
    pthread_create(&th1,NULL,thread_func,&v1);
    pthread_create(&th2,NULL,thread_func,&v2);

    printf("Main Thread\n");
    printf("Thread ID1: %ld\n",th1);
    printf("Thread ID2: %ld\n",th2);

    while(1);
}
