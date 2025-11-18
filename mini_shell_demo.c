#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char command[128];
	char *args[10];

	while (1) {
		printf("Enter command: ");
		fflush(stdout);

		// Read input
		if (!fgets(command, sizeof(command), stdin)) {
			break; // Exit on Ctrl+D
		}

		// Remove newline character
		command[strcspn(command, "\n")] = '\0';

		// Tokenize input (split into command + arguments)
		int i = 0;
		args[i] = strtok(command, " ");

		if (strcmp(args[i], "exit") == 0)
			exit(0);
		while (args[i] != NULL && i < 9) {
			args[++i] = strtok(NULL, " ");
		}

		// Fork a new process
		pid_t pid = fork();

		if (pid == 0) {
			// Child process: run the command
			execvp(args[0], args);
			perror("execvp failed");
			exit(1);
		} else if (pid > 0) {
			// Parent process: wait for the child
			wait(NULL);
		} else {
			perror("fork failed");
		}
	}

	return 0;
}
