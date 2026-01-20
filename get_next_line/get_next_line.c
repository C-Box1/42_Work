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

char	*ft_strchr(const char *s, int c);
char	*extract_line(char **leftover);
char	*update_leftover(char	**leftover, char	**buffer);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(leftover, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		leftover = update_leftover(&leftover, &buffer);
	}
	free(buffer);
	line = extract_line(&leftover);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c == 0)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*extract_line(char **leftover)
{
	char	*line;
	char	*tmp;
	size_t	len;

	if (*leftover == NULL || **leftover == '\0')
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
		return (line);
	free(*leftover);
	*leftover = tmp;
	return (line);
}

char	*update_leftover(char	**leftover, char	**buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*leftover, *buffer);
	if (!tmp)
		return (NULL);
	free(*leftover);
	*leftover = tmp;
	return (*leftover);
}
