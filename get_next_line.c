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

#include "get_next_line.h"
#include "libft/libft.h"

int		ft_end(char **line, char *buff)
{
	*line = ft_strjoinfree(*line, buff, 'l');
	return (1);
}

int	ft_stock_gestion(int fd, char **stock, char **line)
{
	int		len;

	*line = ft_strdup("");
	if (ft_strchr(stock[fd], '\n') == NULL)
	{
		*line = ft_strjoinfree(*line, stock[fd], 'a');
		return (ft_fill_buff(fd, stock, line));
	}
	else
	{
		len = ft_strchr(stock[fd], '\n') - stock[fd];
		*line = ft_strjoinfree(*line, ft_strsub(stock[fd], 0, len), 'a');
		stock[fd] = ft_strsub(stock[fd], len + 1,\
		ft_strlen(stock[fd]) - len - 1);
		return (1);
	}
}

int	ft_fill_buff(int fd, char **stock, char **line)
{
	int		ret;
	int		len;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = 0;
		if (ft_strchr(buff, '\n') == NULL)
			*line = ft_strjoinfree(*line, buff, 'l');
		else if (ft_strchr(buff, '\n'))
		{
			len = ft_strchr(buff, '\n') - buff;
			*line = ft_strjoinfree(*line, ft_strsub(buff, 0, len), 'b');
			stock[fd] = ft_strsub(buff, len + 1, ft_strlen(buff) - len - 1);
			return (1);
		}
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static	char	*stock[MAX_FD];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!stock[fd])
	{
		*line = ft_strdup("");
		ret = ft_fill_buff(fd, stock, line);
		return (ret != 0 ? ret : 0);
	}
	else
	{
		ret = ft_stock_gestion(fd, stock, line);
		return (ret != 0 ? ret : 0);
	}
	return (ret);
}
