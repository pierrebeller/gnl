#include "gnl.h"


char	*fill_buff(int fd)
{
	char	buff[BUFF_SIZE];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE - 1)))
		buff[ret] = 0;
	return (strdup(buff));
}

char	*fill_line(char *line, int fd, char *buff, char **array)
{
	char *result;
	int len;

	if (strchr(buff, '\n') != NULL)
		len = strchr(buff, '\n') - buff;
	else 
		len = strlen(buff);

	result = (char *)malloc(sizeof(char) * (strlen(line) + len + 1));
	strncat(strcpy(result, line), buff, len);
	line = result;
	printf("%s\n", line);
	printf("%s\n", array[fd]);
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static 	char	*array[255];
			char	buff[BUFF_SIZE];

	strncpy(buff, array[fd], BUFF_SIZE);
	printf("%s\n", buff);
	//if (buff == 0)
		//buff = fill_buff(fd);
	printf("%s\n", *line);
	printf("%d\n", fd);
	printf("%s\n", *array);
	printf("%s\n", buff);
	//if (buff != 0)
		//fill_line(*line, fd, buff, &array[fd]);
	//if (buff == '\n')
		//array[fd] = stock(buff, fd)
	return (0);
}
