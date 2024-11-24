#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t cpid1;
    pid_t cpid2;
    char buf;

    pipe(pipefd);
    cpid1 = fork();
    if (cpid1 == -1) {
        printf("fork failed!");
    } else if(cpid1 == 0) {
        close(pipefd[1]);

        while (read(pipefd[0], &buf, 1))
        {
            write(STDOUT_FILENO, &buf, 1);
        }

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
    }

    cpid2 = fork();
    if (cpid2 == -1) {
        printf("fork failed!");
    } else if(cpid2 == 0) {
        close(pipefd[0]);
        write(pipefd[1], "nitish", strlen("nitish"));
        close(pipefd[1]);
    } else {
        wait(NULL);
    }

    
}