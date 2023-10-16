#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;

	// Create child process using fork
	pid = fork();

	if (pid < 0) {
		// Error occurred
		fprintf(stderr, "Fork failed");
		return 1;
	} else if (pid == 0) {
		// Child process
		printf("This is the child process, with id %d\n", getpid());
	} else {
		// Parent process
		printf("This is the parent process, with id %d\n", getpid());
	}

	return 0;
}

