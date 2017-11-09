/*
 * Make use of function pthread_equal()
 * Return non zero value when both the threads are equal
 * 0 when threads are not equal
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread(void *arg)
{
	pthread_t *tid = (pthread_t *)arg;

  int cmp = pthread_equal(*tid,pthread_self());

  printf("Comparison output: %d\n",cmp);

	return NULL;
}


int main()
{
	pthread_t thread_id;

	// create the thread
	pthread_create(&thread_id, NULL,thread,&thread_id);

	// Need to put a wait so that main thread is running
  pthread_join(thread_id,NULL);


	return 0;
}
