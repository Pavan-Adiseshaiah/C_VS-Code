#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("Pipe create failed\n");
        exit(EXIT_FAILURE);
    }

    switch (fork()) {
        default:
            close(pipefd[0]);               //Close read end in parent. Here or before wait()
            break;
        case -1:
            perror("fork wc failed\n");
            exit(EXIT_FAILURE);
        case 0:
            close(pipefd[1]);              //Close write end in child
            if (dup2(pipefd[0], STDIN_FILENO) == -1) {
                perror("Dup read end descriptor failed\n");
                exit(EXIT_FAILURE);
            }
            execl("/usr/bin/wc", "wc", NULL);
            perror("execl wc failed\n");
            exit(EXIT_FAILURE);
    }

    switch (fork()) {
        default:
            close(pipefd[1]);           //Close write end in parent. Here or before wait(). Write end must be closed!
            break;
        case -1:
            perror("fork ls failed\n");
            exit(EXIT_FAILURE);
        case 0:
            close(pipefd[0]);           //Close read end in child
            if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
                perror("Dup write end descriptor failed\n");
                exit(EXIT_FAILURE);
            }
            execl("/bin/ls", "ls", "-l", NULL);
            perror("execl ls failed\n");
            exit(EXIT_FAILURE);
    }

    //close(pipefd[0]);             //Close both ends in parent. Must be before wait()
    //close(pipefd[1]);

    wait(NULL);
    wait(NULL);

    exit(EXIT_SUCCESS);
}
