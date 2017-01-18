#include "gnl.h"


char	*fill_buff(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE];

	while ((ret = read(fd, buff, BUFF_SIZE - 1)))
		buff[ret] = 0;
	return (strdup(buff));
}

/*char	*fille_line(char **line, int fd, char *buff, char **array)
{
	char *result;
	int len;

	*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (strchr(buff, '\n') != NULL)
		len = strchr(buff, '\n') - buff;
	else 
		len = strlen(buff);
	result = (char *)malloc(sizeof(char) * (strlen(*line) + len + 1));
	strncat(strcpy(result, *line), buff, len);
	*line = result;
	array[fd] = buff + len + 1;
	return (*line);
}

char	*fill_line(char **line, int fd, char **array)
{
	char *temp;

	if (strchr(buff, '\n') == NULL)
	{
		temp = (char *)malloc(sizeof(char) * (strlen(*line) + BUFF_SIZE + 1));
		strncat(temp, buff, BUFF_SIZE);
		buff = fill_buff(fd);

	}
	return (*line);
}*/

int		get_next_line(const int fd, char **line)
{
	static 	char	*array[255];
			char	*temp;
	
	if (array[fd] == 0)
		temp = fill_buff(fd);
	printf("%s\n", temp);
	//if (*buff)
		//fill_line((line), fd, &array[fd]);
	//printf("%s\n", *line);
	//if (buff == '\n')
		//array[fd] = stock(buff, fd)
	return (0);
}
