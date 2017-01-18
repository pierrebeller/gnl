#ifndef GNL_H
# define GNL_H 

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define BUFF_SIZE 8

int		fill_buff(int fd);
char	*fill_line(char **line, int fd, char **array);
int		get_next_line(const int fd, char **line);
char	*fill_stock(int fd, char *temp, char **stock);

#endif
