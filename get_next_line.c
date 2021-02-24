/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:44:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/02/23 23:14:20 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int[] readbuffer;
	size_t bufsize;

	bufsize = read(fd, readbuffer, BUFFER_SIZE);
	readbuffer = malloc(bufsize);

	if (BUFFER_SIZE <= 0)
	{
		free(readbuffer);
		return (-1);
	}

}
