#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "gnl.h"

void	get_next_line(int fd, char **array)
{
	char	buff[BUFF_SIZE];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE - 1)))
		buff[ret] = 0;
	ret = 0;
	while (buff[ret])
	{
		while(buff[ret] != '\n')
		{
			printf("%c", buff[ret]);
			ret++;
		}
		if(buff[ret] == '\n')
		{
			ret++;
			array[fd] = strdup((const char *)(buff + ret));
			break;
		}
	}
}

int		main(int argc, char **argv)
{
	char *array[255];
	int fd;
	
	if (argc < 2)
		write(2, "Not enough argument.\n", 21);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, array);
	}
	return(0);
}
