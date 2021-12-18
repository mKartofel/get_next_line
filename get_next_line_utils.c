/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:49:40 by vfiszbin          #+#    #+#             */
/*   Updated: 2021/12/18 19:36:18 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	clean_buffer(char *buffer)
{
	int i = 0;
	while (buffer[i])
	{
		buffer[i] = '\0';
		i++;
	}
}

#include <stdio.h>
char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret_str;

	if (!s1 || !s2)
		return (NULL);
	
	i = ft_strlen(s1) + ft_strlen(s2);
	ret_str = malloc(sizeof(char) * (i + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
	{
		ret_str[i] = s1[j];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		ret_str[i] = s2[j];
		i++;
	}
	ret_str[i] = '\0';
	free(s1);
	return (ret_str);
}

int contains_eol(const char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}