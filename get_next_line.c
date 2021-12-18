/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:49:35 by vfiszbin          #+#    #+#             */
/*   Updated: 2021/12/18 19:50:56 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include<stdio.h>
char	*get_next_line(int fd)
{
	char *s;
	char *buffer;
	ssize_t ret;

	s = malloc(sizeof(char));
	if (!s)
		return NULL;
	s[0] = '\0';
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return NULL;

	ret = 1;
	while (!contains_eol(s) && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(s);
			free(buffer);
			return NULL;
		}
		buffer[ret] = '\0';
		s = ft_strjoin(s, buffer);
		clean_buffer(buffer);
		//printf("ret=%zd\n", ret);
	}
	free(buffer);

	if (ret == 0 && ft_strlen(s) == 0)
		return NULL;
	return s;
	
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	char *s;
	int fd = open("test", O_RDONLY);

	s = get_next_line(fd);
	printf("%s", s);
	while (s != NULL)
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
	close(fd);

	return 0;
}
  