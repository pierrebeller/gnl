#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		main()
{
	char 	*test = "bcdefghij\nklmnop";
	char	*dest = "a";
	char	*result;
	int		len;

	if (strchr(test, '\n') != NULL)
		len = strchr(test, '\n') - test;
	else 
		len = strlen(test);
	printf("%d\n", len);
	printf("%s\n", strchr(test, '\n'));
	result = (char *)malloc(sizeof(char) * (strlen(dest) + len + 1));
	strncat(strcpy(result, dest), test, len);
	dest = result;
	printf("%s\n", dest);
	return (0);
}
