#ifndef GNL_H
# define GNL_H 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define BUFF_SIZE 1024

char	*fill_buff(int fd);
char	*fill_line(char *line, int fd, char *buff, char **array);
int		get_next_line(const int fd, char **line);

#endif
