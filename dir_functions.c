#include "main.h"

/**
 * change_directory - Change the current working directory.
 * @directory: The desired directory path.
 *
 * Return: (0) on success, (-1) on failure.
 */
int change_directory(const char *directory)
{
	char current_dir[1024];

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("cwd");
		return (-1);
	}

	if (chdir(directory) == 0)
	{
		setenv("OLDPWD", current_dir, 1); /* Update OLDPWD environment variable */
		setenv("PWD", directory, 1); /* Update PWD environment variable */
		return (0);
	}
	else
	{
		perror("dir");
		return (-1);
	}
}

/**
 * cd - Change the current working directory.
 * @directory: The desired directory path.
 *
 * Return: (0) on success, (-1) on failure.
 */
int cd(const char *directory)
{
	if (directory == NULL)
	{
		directory = getenv("HOME");
		if (directory == NULL)
			return (-1);

		change_directory(directory);
		return (0);
	}

	if (strcmp(directory, "-") == 0)
	{
		char *previous_dir = getenv("OLDPWD");

		if (previous_dir == NULL)
			return (-1);

		if (change_directory(previous_dir) == 0)
			return (0);
		else
			return (-1);

	}
	else
		return (change_directory(directory));

}
