/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:49:17 by pbeller           #+#    #+#             */
/*   Updated: 2017/01/18 10:49:34 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "gnl.h"
#include "../projets/libft/libft.h"


int		fill_buffer(int fd, char **stock, char **line)
{
	int		ret;
	int		len;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	temp = *line;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (ft_strchr(buff, '\n') == NULL)
			temp = ft_strjoin(temp, buff);
		else if (ft_strchr(buff, '\n'))
		{
			len =ft_strchr(buff, '\n') - buff;
			temp = ft_strjoin(temp, ft_strsub(buff, 0, len));
			stock[fd] = ft_strsub(buff, len + 1, ft_strlen(buff) - len - 1);
			*line = temp;
			return (ret);
		}
	}
	return(0);
}


int		get_next_line(int fd, char **line)
{
	char	*stock[255];
	int		ret;
	
	*line = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0)
		return (-1);
	if (stock[fd] == 0)
	{
		ret = fill_buffer(fd, stock, line);
		return (ret);
	}
	else if (stock[fd])
	{
		ft_strcpy(*line, stock[fd]);
		printf("Stock: %s\n", stock[fd]);
		ret = fill_buffer(fd, stock, line);
		return (ret);
	}
	return (0);
}

int		main(int ac, char **av)
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

