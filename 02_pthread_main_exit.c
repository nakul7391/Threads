/*
 * Random execution of two threads main and  thread
 * The thread will work for 1 second and then exit
 * because main will exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread(void *unused)
{
	while(1)
	{
		fputc('0', stderr);
	}

	return NULL;
}

int main()
{
	pthread_t thread_id;

	// create the thread
	pthread_create(&thread_id, NULL,thread, NULL);

	// Need to put a wait so that main thread is running
  sleep(1);

	return 0;

}
