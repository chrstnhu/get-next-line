/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:17:33 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/14 18:17:34 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-----------------------------MANDATORY---------------------
#include "get_next_line.h"

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
		perror("Error opening file");
		return (1);
	}
	while (1)
	{
		printf("\nRead text :\n");
		line = get_next_line(fd1);
		if (!line)
		{
			printf("Reached end of file or error.\n");
			break ;
		}
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd1);
	while (1)
	{
		printf("\nRead text_no_newline :\n");
		line = get_next_line(fd2);
		if (!line)
		{
			printf("Reached end of file or error.\n");
			break ;
		}
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd2);
	while (1)
	{
		printf("\nRead text_newline :\n");
		line = get_next_line(fd3);
		if (!line)
		{
			printf("Reached end of file or error.\n");
			break ;
		}
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd3);
	while (1)
	{
		printf("\nRead text_null :\n");
		line = get_next_line(fd4);
		if (!line)
		{
			printf("Reached end of file or error.\n");
			break ;
		}
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd4);
    while (1)
    {
        printf("\nRead stdin:\n");
        line = get_next_line(0);
        if (!line)
        {
            printf("Reached end of file or error.\n");
            free(line);
            break;
        }
        printf("Line read: %s\n", line);
        free(line);
    }
	return (0);
}
