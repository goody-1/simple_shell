#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(void)
{
	pid_t my_ppid, my_pid;

	my_ppid = getppid();
	my_pid = getpid();

	printf("My pid is %u and my parent's pid is %u\n", my_pid, my_ppid);
	return (0);
}
