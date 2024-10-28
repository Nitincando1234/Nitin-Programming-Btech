#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t semaphore;
void semfunct(){
	sem_wait(&semaphore);
//	printf("%d", semaphore);
	printf("Hello s1\n");
}
void semfunct1(){
	printf("Hello s2\n");
//	printf("%d", semaphore);
	sem_post(&semaphore);
}
void thread1(){
	printf("Hello s3\n");
}
void thread2(){
	printf("Hello s4\n");
}
int main(){
	sem_init(&semaphore, 0, 0);
	pthread_t *mythread1, *mythread2, *mythread3, *mythread4;
	mythread1 = (pthread_t *) malloc (sizeof(pthread_t));
        mythread2 = (pthread_t *) malloc (sizeof(pthread_t));
        mythread3 = (pthread_t *) malloc (sizeof(pthread_t));
        mythread4 = (pthread_t *) malloc (sizeof(pthread_t));

	pthread_create(mythread1, NULL, (void *) semfunct, NULL);
        pthread_create(mythread1, NULL, (void *) semfunct1, NULL);
        pthread_create(mythread1, NULL, (void *) thread1, NULL);
        pthread_create(mythread1, NULL, (void *) thread2, NULL);

	(void) pthread_join(*mythread1, NULL);		// (void): to discard any value returned by the pthread_join()
        (void) pthread_join(*mythread2, NULL);
        (void) pthread_join(*mythread3, NULL);
        (void) pthread_join(*mythread4, NULL);

	return 0;
}
