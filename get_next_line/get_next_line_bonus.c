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

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c);
char	*extract_line(char **leftover);
char	*update_leftover(char	**leftover, char	**buffer);

char	*get_next_line_bonus(int fd)
{
	static char	*leftover[FD_MAX];
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(leftover[fd], '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		leftover[fd] = update_leftover(&leftover[fd], &buffer);
	}
	free(buffer);
	line = extract_line(&leftover[fd]);
	return (line);
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

	if (!*leftover)
		*leftover = ft_strdup("");
	if (!*leftover)
		return (NULL);
	tmp = ft_strjoin(*leftover, *buffer);
	if (!tmp)
		return (*leftover);
	free(*leftover);
	*leftover = tmp;
	return (*leftover);
}
