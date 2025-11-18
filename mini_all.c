#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

// Function prototypes
char *read_input();
char **parse_input(char *input);
void execute_command(char **args);
int handle_builtin(char **args); // returns 1 if a builtin command ran

int main() {
	while (1) {
		char *input = read_input();
		if (input == NULL) break; // Ctrl+D exits

		char **args = parse_input(input);
		if (args[0] == NULL) {
			free(input);
			free(args);
			continue; // empty input
		}

		// Handle built-in commands first
		if (!handle_builtin(args)) {
			execute_command(args); // external commands
		}

		free(input);
		free(args);
	}
	return 0;
}

// --------------------------
// Function Definitions
// --------------------------

// Read user input
char *read_input() {
	char *buffer = malloc(MAX_INPUT);
	if (!buffer) { perror("malloc failed"); exit(1); }

	printf("mini-shell> ");
	fflush(stdout);

	if (!fgets(buffer, MAX_INPUT, stdin)) {
		free(buffer);
		return NULL;
	}

	buffer[strcspn(buffer, "\n")] = '\0';
	return buffer;
}

// Parse input into tokens
char **parse_input(char *input) {
	char **args = malloc(sizeof(char*) * MAX_ARGS);
	if (!args) { perror("malloc failed"); exit(1); }

	int i = 0;
	args[i] = strtok(input, " ");
	while (args[i] != NULL && i < MAX_ARGS - 1) {
		args[++i] = strtok(NULL, " ");
	}
	args[i] = NULL;
	return args;
}

// Execute external commands
void execute_command(char **args) {
	pid_t pid = fork();

	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("execvp failed");
		}
		exit(1);
	} else if (pid > 0) {
		wait(NULL);
	} else {
		perror("fork failed");
	}
}

// Handle built-in commands
int handle_builtin(char **args) {
	if (strcmp(args[0], "cd") == 0) {
		if (args[1] == NULL) {
			fprintf(stderr, "cd: missing argument\n");
		} else if (chdir(args[1]) != 0) {
			perror("cd failed");
		}
		return 1; // built-in handled
	}

	if (strcmp(args[0], "exit") == 0) {
		exit(0); // quit shell
	}

	if (strcmp(args[0], "help") == 0) {
		printf("Mini Shell Help:\n");
		printf("cd <dir>    - Change directory\n");
		printf("exit       - Quit the shell\n");
		printf("help       - Show this message\n");
		printf("Other commands are executed normally.\n");
		return 1;
	}

	return 0; // not a built-in command
}
