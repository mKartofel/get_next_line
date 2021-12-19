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
char	*pop_line(char *s)
{
	int i;
	char *line;
	//char *new_s;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(s);
		return NULL;
	}
	ft_strlcpy(line, s, i + 2);
	free(s);
	return line;
}

char *retrieve_unused_buffer(char *s, char *buffer)
{
	int buffer_len;

	buffer = ft_strchr(buffer, '\n') + 1;
	if (!buffer)
		return s;
	free(s);
	buffer_len = ft_strlen(buffer);
	s = malloc(sizeof(char) * buffer_len + 1);
	if (!s)
		return NULL;
		
	//printf("buffer_len=%d\n", buffer_len);
	ft_strlcpy(s, buffer, buffer_len + 1);
	return s;

}



char	*get_next_line(int fd)
{
	char		*s;
	char		*tmp;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		ret;

	s = malloc(sizeof(char));
	s[0] = '\0';
	
	
	if (contains_eol(buffer))
	{
		s = retrieve_unused_buffer(s, buffer);
		if (!s)
			return NULL;
	}
	//printf("s=%s\n", s);

	ret = 1;
	while (!contains_eol(s) && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(s);
			return NULL;
		}
		buffer[ret] = '\0';
		tmp = s;
		s = ft_strjoin(tmp, buffer);
		free(tmp);
	}

	if (ret == 0 && ft_strlen(s) == 0)
	{
		free(s);
		return NULL;
	}
	s = pop_line(s);
	if (!s)
		return NULL;
	return s;
	
}


#include <stdio.h>
#include <fcntl.h>
int main()
{
	char *s;
	int fd = open("multiple_nlx5", O_RDONLY);

	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	// while (s != NULL)
	// {
	// 	free(s);
	// 	s = get_next_line(fd);
	// 	printf("%s", s);
	// }
	close(fd);

	return 0;
}

