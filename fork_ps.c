#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();

	if (pid == 0) {
		printf("[Child] PID = %d: Running 'ps' command...\n", getpid());
		execlp("ps", "ps", NULL);
		perror("execlp failed");
		return 1;
	}
	else if (pid > 0) {
		printf("[Parent] PID = %d: Waiting for child (PID %d)...\n", getpid(), pid);
		wait(NULL);
		printf("[Parent] Child completed!\n");
	}
	else {
		perror("fork failed");
	}

	return 0;
}
