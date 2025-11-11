#include <stdio.h>
#include <pthread.h>

void* say_hello(void* arg) {
	long id = (long)arg;
	printf("Jambo from Thread %ld! PID: %d\n", id, getpid());
	return NULL;
}

int main() {
	pthread_t t1, t2;

	printf("Karibu! Main Thread PID: %d\n", getpid());

	pthread_create(&t1, NULL, say_hello, (void*)1);
	pthread_create(&t2, NULL, say_hello, (void*)2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Asante! All threads done.\n");
	return 0;
}
