/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:44:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/05 21:12:16 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;

	len = ft_strlen(s);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(dest, s, (len + 1));
	return (dest);
}
char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(len + 1);
	if (!s || ptr == NULL)
		return (NULL);
	while (i < len && ((start + i) < ft_strlen(s)) && (s[start + i] != '\0'))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
int		len_to_char(char *final_line, char *tmp)
{
	int i;

	i = 0;
	while (final_line[i] != tmp[0])
	{
		i++;
	}
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static ssize_t		ret;
	char		bf[BUFFER_SIZE + (ret + 1)];
	static char	*final_line = NULL;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	final_line == NULL ? final_line = ft_strnew(0) : NULL;
	while (!ft_strchr(final_line, '\n') && (ret = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[ret] = '\0';
		printf("ret=%zd \n", ret);
		printf("loop tmp=%s \n", tmp);
		printf("loop final=%s \n", final_line);
		tmp = ft_strjoin(final_line, bf);
		final_line = tmp;
	}
	printf("ret=%zd \n", ret);
	printf("bf=%s \n", bf);
	printf("tmp=%s \n", tmp);
	printf("final=%s \n", final_line);
	if (ret == 0)
		*line = ft_strdup(final_line);
	else if (ret > 0)
	{
		*line = ft_substr(final_line, 0, (ft_strchr(final_line, '\n') - final_line));
	}
	else
		return (-1);
	tmp = (ft_strchr(final_line, '\n') + 1);
	ret = len_to_char(final_line, tmp);
	printf("tmp=%s \n", tmp);
	return (1);

	
}
