/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:48:45 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/28 17:22:11 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*get_line(int fd, char *buffer, char *line)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		if (!line)
			line = ft_strdup("");
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*trim_line(char **dest)
{
	int		i;
	char	*temp;
	char	*line;

	i = 0;
	if (!*dest)
		return (NULL);
	while ((*dest)[i] != '\n' && (*dest)[i])
		i++;
	if ((*dest)[i] == '\n')
		i++;
	temp = *dest;
	*dest = ft_substr(temp, 0, i);
	line = ft_substr(temp, i, ft_strlen(temp) - i);
	free(temp);
	if (!line)
	{
		free(dest);
		free(line);
		dest = NULL;
		return (NULL);
	}
	return (line);
}

void	*free_all(char **line, char **buffer)
{
	free(*line);
	free(*buffer);
	*line = NULL;
	*buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *line;
	char		*buffer;
	char		*dest;

	buffer = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		free_all(&line, &buffer);
	if (!buffer)
		return (NULL);
	dest = get_line(fd, buffer, line);
	free(buffer);
	buffer = NULL;
	if (!dest)
		return (NULL);
	line = trim_line(&dest);
	if (dest[0] == 0)
		free_all(&line, &dest);
	return (dest);
}
