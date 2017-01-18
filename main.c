#include "gnl.h"
# include <stdio.h>
# include <fcntl.h>

int main(int ac, char **av)
{
	char *line;
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while (get_next_line(fd, &line))
	{
		printf("line: %s\n", line);
		free(line);
	}
	return (0);
}
