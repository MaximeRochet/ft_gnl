/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:30:38 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/18 13:38:34 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	if (!(ret = malloc(size * count)))
		return (0);
	ret[0] = 0;
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stock[10240];
	int				read_value;

	buff[0] = '@';
	read_value = -1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock[fd])
		if (!(stock[fd] = ft_calloc((sizeof(char)), 1)))
			return (-1);
	while (!(ft_strchr(stock[fd], '\n')) && read_value != 0)
	{
		if ((read_value = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[read_value] = '\0';
		stock[fd] = ft_strfjoin(stock[fd], buff);
	}
	*line = stock[fd] ? ft_subfstr(stock[fd], 0, ft_strchr(stock[fd], '\n') \
			- stock[fd], 0) : ft_calloc(1, 1);
	stock[fd] = ft_subfstr(stock[fd], (ft_strchr(stock[fd], '\n') \
				- stock[fd]) + 1,\
			ft_strlen(ft_strchr(stock[fd], '\n')), 1);
	return (!stock[fd] && !buff[0] ? 0 : 1);
}
