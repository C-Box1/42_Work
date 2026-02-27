/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csahyoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:25:24 by csahyoun          #+#    #+#             */
/*   Updated: 2025/07/21 01:25:27 by csahyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **leftover);
char	*update_leftover(char **leftover, char **buffer);

static char	*read_and_store(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((!leftover || !ft_strchr(leftover, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (bytes > 0)
			leftover = update_leftover(&leftover, &buffer);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_and_store(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(&leftover);
	if (!line)
	{
		free(leftover);
		leftover = NULL;
	}
	return (line);
}

char	*extract_line(char **leftover)
{
	char	*line;
	char	*tmp;
	size_t	len;

	if (!*leftover || !**leftover)
		return (NULL);
	len = 0;
	while ((*leftover)[len] && (*leftover)[len] != '\n')
		len++;
	if ((*leftover)[len] == '\n')
		len++;
	line = ft_substr(*leftover, 0, len);
	if (!line)
		return (NULL);
	tmp = ft_strdup(*leftover + len);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	free(*leftover);
	*leftover = tmp;
	return (line);
}

char	*update_leftover(char **leftover, char **buffer)
{
	char	*tmp;

	if (!*leftover)
		*leftover = ft_strdup("");
	if (!*leftover)
		return (NULL);
	tmp = ft_strjoin(*leftover, *buffer);
	if (!tmp)
	{
		free(*leftover);
		*leftover = NULL;
		return (NULL);
	}
	free(*leftover);
	*leftover = tmp;
	return (*leftover);
}
