/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:04:48 by                   #+#    #+#             */
/*   Updated: 2021/11/26 17:34:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*prestr;
	char	*poststr;
	char	*joinedstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	prestr = (char *)s1;
	poststr = (char *)s2;
	joinedstr = malloc(sizeof (char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joinedstr == NULL)
		return (NULL);
	while (prestr[i])
	{
		joinedstr[i] = prestr[i];
		i++;
	}
	while (poststr[j])
		joinedstr[i++] = poststr[j++];
	joinedstr[i] = '\0';
	return (joinedstr);
}

char	*ft_strdup(const char *str)
{
	char	*cpstr;
	char	*str1;
	int		i;

	i = 0;
	str1 = (char *)str;
	cpstr = malloc(sizeof (char) * ft_strlen(str) + 1);
	if (cpstr == NULL)
		return (0);
	while (str1[i])
	{
		cpstr[i] = str1[i];
		i++;
	}
	cpstr[i] = '\0';
	return (cpstr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char					*csrc;
	char					*cdest;
	unsigned long int		i;

	if (dest == 0 && src == 0 && n != 0)
		return (0);
	i = 0;
	csrc = (char *)src;
	cdest = (char *)dest;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(char *str, int c)
{
	int			i;
	char		*str1;

	if (c == '\0')
	{
		str1 = &str[ft_strlen(str)];
		return (str1);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			return (0);
		else if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}