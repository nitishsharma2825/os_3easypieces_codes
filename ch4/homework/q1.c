#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int rc = fork();
    int x = 100;
    if (rc < 0) {
        printf("fork failed");
    } else if ( rc == 0)
    {
        printf("value of x in child process %d is %d \n", getpid(), x);
        x = 200;
        printf("value of x in child process after changed %d is %d \n", getpid(), x);
    } else {
        int rc_wait = wait(NULL);
        printf("value of x in parent process %d is %d \n", getpid(), x);
        x = 300;
        printf("value of x in parent process after changed %d is %d \n", getpid(), x);
    }
}