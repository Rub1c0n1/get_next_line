/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:33:56 by dgizzard          #+#    #+#             */
/*   Updated: 2021/11/26 17:40:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*rem_update(char **remainder)
{
	char	*line;
	char	*sec_rem;
	char	*n;

	n = NULL;
	if (*remainder)
	{
		n = ft_strchr(*remainder, '\n');
		if (n)
		{
			sec_rem = *remainder;
			*remainder = ft_strdup(++n);
			n = ft_memcpy(n, "\0", 1);
			line = ft_strdup(sec_rem);
			free(sec_rem);
		}
		else
		{
			line = *remainder;
			*remainder = NULL;
		}
	}
	else
		line = ft_strdup("");
	return (line);
}

static char	*read_line(int fd, char *n, char *line, char **remainder)
{
	char	*tmp;
	int		r;
	char	buf[BUFFER_SIZE + 1];

	r = 1;
	while (!n && r && line && !(*remainder))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0 && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		buf[r] = '\0';
		n = ft_strchr(buf, '\n');
		if (n)
		{
			*remainder = ft_strdup(++n);
			n = ft_memcpy(n, "\0", 1);
		}
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[12500];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = rem_update(&remainder[fd]);
	line = read_line(fd, NULL, line, &remainder[fd]);
	return (line);
}
