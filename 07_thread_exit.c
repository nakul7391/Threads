/*
 * Exit the thread using pthread_exit()
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread(void *unused)
{
	int i;

  for(i = 0; i < 20000; i++)
  {
      if(i == 500)
      pthread_exit((void*)25);
      else
      fputc('X',stderr);
  }

	return NULL;
}

int main()
{
	pthread_t thread_id;

	// create the thread
	pthread_create(&thread_id, NULL,thread, NULL);

	// Need to put a wait so that main thread is running
  int ret;
	pthread_join(thread_id,(void **)&ret);

  printf("Return value: %d\n",ret);
  
	return 0;

}
