#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;

	pid = fork();

	if (pid == 0) {
		// Child process
		printf("I am the child process.\n");
		sleep(3);
		printf("Child wakes up after 3 seconds. \n");
	} else if (pid > 0) {
		// Parent process
		printf("I am the parent process. \n");
		sleep(1);
		printf("Parent wakes up after 1 second.\n");
	} else {
		printf("Fork failed!\n");
	}

	return 0;
}
