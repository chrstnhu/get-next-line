/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:15:42 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/12 15:40:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_fd(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = (char *)malloc(ft_strlen(save) - i + 1);
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (save[i + j])
	{
		line[j] = save[i + j];
		j++;
	}
	line[j] = '\0';
	free(save);
	return (line);
}

char	*line_fd(char *save)
{
	char	*line;
	int		i;

	if (!save || !save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_fd(int fd, char *save)
{
	char	*buffer;
	int		nbytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	if (nbytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	while (nbytes > 0)
	{
		buffer[nbytes] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	save[fd] = read_fd(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = line_fd(save[fd]);
	save[fd] = next_fd(save[fd]);
	return (line);
}
