/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GET_NEXT_LINE.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <dgizzard>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:24:40 by  dgizzard         #+#    #+#             */
/*   Updated: 2021/11/26 17:34:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*ft_strdup(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlen(const char *string);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strchr(char *str, int c);

#endif