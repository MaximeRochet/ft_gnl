/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:00:03 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/17 16:46:49 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*stock = NULL;
	int				read_value;

	buff[0] = '@';
	read_value = -1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock)
		if (!(stock = ft_calloc((sizeof(char)), 1)))
			return (-1);
	while (!(ft_strchr(stock, '\n')) && read_value != 0)
	{
		if ((read_value = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[read_value] = '\0';
		stock = ft_strfjoin(stock, buff);
		if (stock == NULL)
			return (-1);
	}
	*line = stock ? ft_subfstr(stock, 0, ft_strchr(stock, '\n') - stock, 0) : \
			ft_calloc(1, 1);
	stock = ft_subfstr(stock, (ft_strchr(stock, '\n') - stock) + 1,\
			ft_strlen(ft_strchr(stock, '\n')), 1);
	return (!stock && !buff[0] ? 0 : 1);
}
