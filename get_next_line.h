/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:11:42 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/03 21:30:13 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#     define GET_NEXT_LINE_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //inclui read, open...
# include <stdbool.h> // inclui o bool

int			get_next_line(int fd, char **line);
void		*ft_memset(void *s, int c, size_t len);
size_t		ft_strlen(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

# endif