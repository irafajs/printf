#include "umutwe.h"

/**
 * main - entry point
 * @argc: passed args as a counter
 * @argv: passed arg as a vector of inputted command
 *
 * Return: o at success
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	ssize_t check_er;
	size_t storesize = 0;
	char *i_line = NULL;

	do {
		printf("shellpro~");
		check_er = getline(&i_line, &storesize, stdin);
		if (check_er == -1)
		{
			perror("failed to read inputted line\n");
			break;
		}
		i_line[strcspn(i_line, "\n")] = '\0';
		if (i_line[0] == '\0')
		{
			continue;
		}
		if (strcmp(i_line, "exit") == 0)
		{
			break;
		}
		if (strcmp(i_line, "/bin/ls") == 0)
		{
			system("ls");
		}
		else
		{
			i_line[strcspn(i_line, "\n")] = '\0';
			execve(i_line, argv, NULL);
			printf("No such file or directory\n");
		}
		free(i_line);
		i_line = NULL;
	} while (1);
	free(i_line);
	return (0);
}