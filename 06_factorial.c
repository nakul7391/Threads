/*
 * Find factorial using thread
*/

#include <stdio.h>
#include <pthread.h>

void * fact(void *args)
{
    long int output = 1, i;
    // Typecast the structure
    int *num = (int *)args;

    if(*num == 0)
    output = 1;
    else
    {
        for(i = 1; i <= *num; i++)
        output = output * i;
    }

    return (void*)output;
}

int main()
{
    pthread_t th;
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    // Create the thread
    pthread_create(&th,NULL,fact,&num);

    pthread_join(th,(void**)&num);

    printf("Factorial is %d\n",num);

    return 0;
}
