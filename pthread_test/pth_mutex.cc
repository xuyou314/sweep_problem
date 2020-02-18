#include <pthread.h>
#include <stdio.h>
int global_counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
void* increment_func(void* args){
	for(int i=0; i<10000; i++){
		//printf("before lock %ld\n", pthread_self());
		pthread_mutex_lock(&mutex1);
		global_counter++;
		pthread_mutex_unlock(&mutex1);
		//printf("end lock %ld\n", pthread_self());
	}
	return NULL;
}
int main(){
	pthread_t t[10];
	for(int i=0; i<10; i++)
		pthread_create(&t[i], NULL, increment_func, NULL);
	for(int i=0; i<10; i++)
		pthread_join(t[i], NULL);
	
	//pthread_join(t2, NULL);
	printf("counter = %d\n", global_counter);
	return 0;
}
