/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:29:59 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/15 12:30:26 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
