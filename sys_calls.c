#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();

	if (pid == 0) {
		printf("[Child] Hello from child! PID = %d\n", getpid());
	}
	else if (pid > 0) {
		printf("[Parent] Hello from parent! My PID = %d, Child PID = %d\n", getpid(), pid);
		wait(NULL);
		printf("[Parent] Child finished. Parent exiting.\n");
	}
	else {
		perror("fork failed");
	}

	return 0;
}
