/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:01:41 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/14 14:42:00 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int			ft_strlen(const char *str);
char		*ft_subfstr(char *s, int start, int len, int fr);
char		*ft_strfjoin(char *s1, char const *s2);
char		*ft_strchr(char *s, int c);
void		*ft_calloc(size_t count, size_t size);
int			get_next_line(int fd, char **line);

#endif
