#include "main.h"

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;

	printf("Address of environ is %p and that of env is %p", (void *)environ, (void *)env);


	return (0);
}
