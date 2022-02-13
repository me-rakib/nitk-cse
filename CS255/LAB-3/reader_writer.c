// use -pthread flag to run
// sem_wait is same as down, decrement
// sem_post is same as up, increment
// pthread_mutex_lock == sem-wait
// pthread_mutex_unlock == sem-post

/*
Algo reader:
    down(mutex)
    re++
    if(re == 1) then down(db)
    up(mutex)
    DATABASE
    down(mutex)
    re--
    if(re==0) then up(db)
    up(mutex)

Algo writer:
    down(db)
    DATABASE
    up(db)
    
*/

#include<stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t db;
pthread_mutex_t mutex;
int rc = 0; // read count
int count = 1;

void *writer(void *num)
{
    sem_wait(&db);   
    count = count + 10;
    printf("Writer %d rewrite count to %d\n", *((int *)num), count);
    sem_post(&db);
}

void *reader(void *num)
{
    pthread_mutex_lock(&mutex);  // locing mutual exclusion
    rc++;
    if (rc == 1)
    {
        sem_wait(&db);
    }
    pthread_mutex_unlock(&mutex);  // unlocking mutual exclusion

    printf("Reader %d: read count as %d\n", *((int *)num), count);

    pthread_mutex_lock(&mutex);
    rc--;
    if (rc == 0)
    {
        sem_post(&db);
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{
    int i;
    pthread_t read[10], write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&db,0,1);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&arr[i]);   // creating thread
    }

    for(i=0; i<5; i++) 
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&arr[i]);
    }

    for(i=0; i<10; i++)
    {
        pthread_join(read[i], NULL);      // joint is used to wait for the termination of a thread
    }

    for(i=0; i<5; i++)
    {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&db);
    return 0;
}