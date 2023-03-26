#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char str[] = "raymondwarden";
	char **array;
	char **tokenize(char *str);

	array = tokenize(str);
	for (int i = 0; array[i]; i++)
	{
		puts(array[i]);
		free(array[i]);
	}
	return 0;
}
