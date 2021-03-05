/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:44:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/05 00:49:46 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		**buf_gtr_t_line(char **return_string, char *bufferline,
			size_t linesize, char **line)
{
	char	*str_tmp = "";

	ft_memset(str_tmp, 0, linesize);
	str_tmp = ft_substr(bufferline, 0, linesize);
	*return_string = str_tmp;
	return_string[linesize + 1] = (char *)'\0';
	*line = *return_string;
//	free (bufferline);
	free ((size_t *)linesize);
	return (line);
}

char		**buf_less_eq_t_line(char **return_string, char *bufferline,
			size_t linesize, char **line)
{
	bufferline[sizeof(bufferline) + 1] = '\0';
	*return_string = bufferline;
	*line = bufferline;
//	free (bufferline);
	linesize = linesize + 1;//isso é pra tapear o gcc
	return (line);
}

size_t		len_to_nl(char *bufferline, bool nl_found)
{
	int i;
	i = 0;
	while (bufferline[i] != 0)
	{
		if (bufferline[i] == '\n')
			{
			bufferline[i] = '\0';
			nl_found = true;
			printf("achoooou\n");
			return (i);
			}
		i++;
	}
	return (i); // qualquer \n indevido, incluir i + 1
}

int		get_next_line(int fd, char **line)
{
	static char readbuffer[BUFFER_SIZE];
	static int	readout;
	char *bufferline;
	static char **return_string;
	//static int	*last_read_char;
	bool nl_found;
	size_t linesize;

	return_string = 0;
	nl_found = false;
	linesize = 0;

	if (readout < BUFFER_SIZE)
	{
		readout = read(fd, readbuffer, BUFFER_SIZE);
	}
	else if (readout >= BUFFER_SIZE)
	{
		readout = readout + (read(fd, readbuffer, BUFFER_SIZE));
	}
	if (readout <= 0)
		return(readout == 0) ? (0):(-1);
	printf("Readbuffer:|%s|\n", readbuffer);
	printf("Readout :%i\n", readout);
	bufferline = ft_strdup(readbuffer);
	printf("bufferline |%s| \n", bufferline);
	linesize = len_to_nl(bufferline, nl_found);
	printf("Linesize é:%ld\n", linesize);
	printf("tem nl? %d\n", nl_found);
	if (linesize <= 0)
	{
	//	free(bufferline);
		return (0);
	}
	if (BUFFER_SIZE > linesize)
		buf_gtr_t_line(return_string, bufferline, linesize, line);// << VAZANDO MEMÓRIA OLHAR memset
	buf_less_eq_t_line(return_string, bufferline, linesize, line);
	//free (readbuffer);
	return (1);
}
