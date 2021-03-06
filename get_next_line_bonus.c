/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:54:39 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/16 12:06:28 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

static int	ft_readbuffer(int fd, char *temp_read, char **string_static,
				int *n)
{
	char	*tmp_string;

	while (*n > 0)
	{
		*n = read(fd, temp_read, BUFFER_SIZE);
		if (*n < 0)
		{
			free(temp_read);
			return (0);
		}
		temp_read[*n] = '\0';
		if (*string_static == NULL)
			*string_static = ft_strdup_gnl(temp_read);
		else
		{
			tmp_string = ft_strjoin_gnl(*string_static, temp_read);
			free(*string_static);
			*string_static = tmp_string;
		}
		if (ft_strchr_gnl(temp_read, '\n'))
			break ;
	}
	free(temp_read);
	return (1);
}

static char	*str_joint(char *string_static, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (*(string_static + i) != '\n' && *(string_static + i) != '\0')
		i++;
	if ((string_static)[i] == '\n')
	{
		*line = ft_substr_gnl(string_static, 0, i);
		tmp = ft_strdup_gnl(&((string_static)[i + 1]));
		free(string_static);
	}
	else
	{
		*line = ft_strdup_gnl(string_static);
		free(string_static);
	}
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	char		*temp_read;
	static char	*string_static[OPEN_MAX];
	int			n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > RLIMIT_NOFILE)
		return (-1);
	temp_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(temp_read))
		return (-1);
	if (!(ft_readbuffer(fd, temp_read, &string_static[fd], &n)))
		return (-1);
	string_static[fd] = str_joint(string_static[fd], line);
	if (n == 0 && !string_static[fd])
		return (0);
	return (1);
}
