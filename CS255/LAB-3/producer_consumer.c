// use -pthread flag to run
// sem_wait is same as down, decrement
// sem_post is same as up, increment

/*
Algo producer:
    down(empty)
    down(s)
    buffer[in] = item
    in = (in+1) mod N
    up(s)
    up(full)

Algo consumer:
    down(full)
    down(s)
    item = buffer[out]
    out = (out+1) mod N
    up(s)
    up(empty)
    
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define MaxItems 5
#define BufferSize 5

sem_t full;
sem_t empty;
pthread_mutex_t mutex;
int in = 0;
int out = 0;
int buffer[BufferSize];
int i;

void *producer(void *num)
{
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[in] = *((int *)num) + 10;
    printf("Producer %d: Produced %d at %d\n", *((int *)num), buffer[in], in);
    in = (in + 1) % BufferSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void *consumer(void *num)
{
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    printf("Cousumer %d: Consumed %d from %d\n", *((int *)num), buffer[out], out);
    out = (out + 1) % BufferSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main()
{
    pthread_t produce[5], consume[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BufferSize);
    sem_init(&full, 0, 0);

    int arr[5] = {1, 2, 3, 4, 5};

    for (i = 0; i < 5; i++)
    {
        pthread_create(&produce[i], NULL, (void *)producer, (void *)&arr[i]);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_create(&consume[i], NULL, (void *)consumer, (void *)&arr[i]);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_join(produce[i], NULL);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(consume[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}