#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	int i = 0, status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t child_pid;

	printf("Parent's pid is %u\n", getpid());

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Child %d's pid is %u\n", i + 1, getpid());

			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
		}
		i++;
	}

	return (0);
}
