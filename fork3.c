#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {  // Error occurred
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }

    if (pid == 0) {  // Child process
        printf("Child process started, will sleep for 5 seconds.\n");
        sleep(5);
        printf("Child process ending.\n");
    } else {  // Parent process
        printf("Parent process waiting for child to finish...\n");
        wait(NULL);  // Wait for child process to finish
        printf("Child process finished. Parent process resuming.\n");
    }

    return 0;
}

