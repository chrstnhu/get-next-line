/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:18:49 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/14 18:20:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-------------------------------BONUS-----------------------
#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text_no_newline.txt", O_RDONLY);
	fd3 = open("text_newline.txt", O_RDONLY);
	fd4 = open("text_null.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		perror("Error opening file\n");
		return (1);
	}
	if (fd1)
	{
		printf("\nOpen text 1st time:\n");
		line = get_next_line(fd1);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd2)
	{
		printf("Open text_no_newline 1st time:\n");
		line = get_next_line(fd2);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd3)
	{
		printf("Open text_newline 1st time:\n");
		line = get_next_line(fd3);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd4)
	{
		printf("Open text_null 1st time:\n");
		line = get_next_line(fd4);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd1)
	{
		printf("Open text 2nd time:\n");
		line = get_next_line(fd1);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd3)
	{
		printf("Open text_newline 2nd time:\n");
		line = get_next_line(fd3);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd1)
	{
		printf("Open text 3rd time:\n");
		line = get_next_line(fd1);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd2)
	{
		printf("Open text_no_newline 2nd time:\n");
		line = get_next_line(fd2);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd1)
	{
		printf("Open text 4rd time:\n");
		line = get_next_line(fd1);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd3)
	{
		printf("Open text_newline 3rd time:\n");
		line = get_next_line(fd3);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd3)
	{
		printf("Open text_newline 4th time:\n");
		line = get_next_line(fd3);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	if (fd3)
	{
		printf("Open text_newline 5th time:\n");
		line = get_next_line(fd3);
		if (!line)
			printf("Reached end of file or error.\n");
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
