/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:54:22 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/16 12:00:31 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*jointstr;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	if (!(jointstr = (char*)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		jointstr[i] = s1[i];
		i++;
	}
	while (i < len2 + len1)
	{
		jointstr[i] = s2[i - len1];
		i++;
	}
	jointstr[i] = '\0';
	return (jointstr);
}

char		*ft_strdup_gnl(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = ft_strlen_gnl(s);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t		ft_strlen_gnl(const char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char		*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s = s + 1;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

char		*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)len <= 0 || (int)start < 0 ||
		(int)start > (int)ft_strlen_gnl((char *)s) - 1)
	{
		return (ft_strdup_gnl(""));
	}
	nstr = (char *)malloc((len + 1) * sizeof(char));
	if (!nstr)
	{
		return (0);
	}
	i = 0;
	while (i < len && *(s + start) != '\0')
	{
		*(nstr + i) = *(s + start);
		i = i + 1;
		start = start + 1;
	}
	*(nstr + i) = '\0';
	return (nstr);
}
