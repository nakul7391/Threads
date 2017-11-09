/*
 * Without mutex output can be 5 or 10 depends on the order of
 * execution of the threads
*/

#include <stdio.h>
#include <pthread.h>

int global;

// Initialize mutex
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void * func1(void * arg)
{
    // Critical section
    pthread_mutex_lock(&mut);
    global = 10;
    pthread_mutex_unlock(&mut);
}

void * func2(void * arg)
{
    // Critical section
    pthread_mutex_lock(&mut);
    global = global * 5;
    pthread_mutex_unlock(&mut);
}

int main()
{
	pthread_t tid1, tid2;

	pthread_create(&tid1,NULL,func1,NULL);
	pthread_create(&tid2,NULL,func2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

  printf("global: %d\n",global);
	return 0;
}
