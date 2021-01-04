/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:30:58 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/15 12:31:12 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_subfstr(char *s, int start, int len, int fr)
{
	char		*ret;
	int			i;

	i = 0;
	if (len < 0 || len > ft_strlen(s))
		len = ft_strlen(s);
	if (((!s || len == 0) && fr == 0) || (start > ft_strlen(s) || start < 0))
		ret = ft_calloc(1, 1);
	else
	{
		if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		while (s[start] && i < len)
			ret[i++] = s[start++];
	}
	ret[i] = '\0';
	if (fr)
		free(s);
	if (fr && i == 0)
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}

char			*ft_strfjoin(char *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		y;
	int		len;

	i = 0;
	y = 0;
	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	if (s2)
		while (s2[y])
			ret[i++] = s2[y++];
	free(s1);
	ret[i] = '\0';
	return (ret);
}

char			*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
		{
			if (s[i] == c)
				return (s + i);
			i++;
		}
	return (NULL);
}
