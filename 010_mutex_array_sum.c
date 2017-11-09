#include <stdio.h>
#include <pthread.h>

// global sum and max min variables
int sum, max, min;
// Create array of 500 elements
int arr[500];

pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER, mut2 = PTHREAD_MUTEX_INITIALIZER, mut3 = PTHREAD_MUTEX_INITIALIZER;
// passing argument structure
typedef struct params
{
    int sindex;
    int eindex;
}params_t;

// thread function to calculate sum of array and max and min
void *func(void * args)
{
    // typecast arguments
    params_t *p = (params_t *)args;

    int i, localSum = 0,localMax = 0,localMin = 0;

    for(i = p->sindex; i <= p->eindex; i++)
    {
        localSum = localSum + arr[i];

        if(arr[i] > localMax)
        localMax = arr[i];

        if(arr[i] < localMin)
        localMin = arr[i];
    }

    // access global variables
    pthread_mutex_lock(&mut1);
    sum = sum + localSum;
    pthread_mutex_unlock(&mut1);

    pthread_mutex_lock(&mut2);
    if(localMin < min)
    min = localMin;
    pthread_mutex_unlock(&mut2);

    pthread_mutex_lock(&mut3);
    if(localMax > max)
    max = localMax;
    pthread_mutex_unlock(&mut3);

}

int main()
{
    int i;
    pthread_t tid[5];

    params_t p[5];

    int t1 = 0;

    // fill array
    for(i = 0; i < 500; i++)
    {
        if(i == 203)
        arr[i] = 1000;
        else if(i == 440)
        arr[i] = -1;
        else
        arr[i] = i;
    }

    // Set parameter arguments
    for(i = 0; i < 5; i++)
    {
        p[i].sindex = t1;
        p[i].eindex = t1 + 99;
        t1 = t1 + 1 + 99;
    }

    // create threads
    for(i = 0; i < 5; i++)
    {
        pthread_create(&tid[i],NULL,func,&p[i]);
    }

    // join threads
    for(i = 0; i < 5; i++)
    {
        pthread_join(tid[i],NULL);
    }

    printf("Sum of all array elements: %d\n",sum);
    printf("Greatest number of all: %d\n",max);
    printf("Lowest number of all: %d\n",min);

    return 0;
}
