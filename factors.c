#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * factorizer - factorize a number.
 * @buf: pointer to the int.
 *
 * Return: Always (0).
 */
int factorizer(char *buf)
{
	u_int32_t pop;
	u_int32_t mo;

	pop = atoi(buf);

	for (mo = 2; mo < pop; mo++)
	{
		if (pop % mo == 0)
		{
			printf("%d=%d*%d\n",pop,pop/mo,mo);
			break;
		}
	}
	return (0);
}

/**
 * main - start of function.
 * @argc: numbers of arguments.
 * @argv: a pointer.
 *
 * Return: always (0)
 */
int main(int argc, char *argv[])
{
	size_t lenght;
	ssize_t pop;
	char *buf = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor factors\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((pop = getline(&buf, &lenght, file)) != -1)
	{
		factorizer(buf);
	}
	return (0);
}
