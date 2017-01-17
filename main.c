#include "gnl.h"

int		main(int argc, char **argv)
{
	int fd;
	
	if (argc < 2)
		write(2, "Not enough argument.\n", 21);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line((const int)fd, argv);
	}
	return(0);
}
