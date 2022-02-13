// use -pthread flag to run
// sem_wait is same as down, decrement
// sem_post is same as up, increment

/*
Algo philosopher:
    thinking()
    wait(take nth chopstick)
    wait(take (n+1)th chopstick)
    eat()
    signal(put chopstick n+1 th)
    signal(put chopstick n th)

*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t room;
sem_t chopstick[5];

void *philosopher(void *);

int main()
{
    int i, arr[5] = {0, 1, 2, 3, 4};
    pthread_t thread_id[5];

    sem_init(&room, 0, 4);

    for (i = 0; i < 5; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_create(&thread_id[i], NULL, philosopher, (void *)&arr[i]);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
    return 0;
}

void *philosopher(void *num)
{
    int phil = *(int *)num;

    sem_wait(&room);
    printf("Philosopher %d has entered room\n", phil);
    sem_wait(&chopstick[phil]);
    sem_wait(&chopstick[(phil + 1) % 5]);

    printf("Philosopher %d is eating\n", phil);

    printf("Philosopher %d has finished eating\n", phil);

    sem_post(&chopstick[(phil + 1) % 5]);
    sem_post(&chopstick[phil]);
    sem_post(&room);
}
