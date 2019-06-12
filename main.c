/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:04:29 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/12 12:21:33 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd[1100];
	char	*line;
	int		ret; 
	int		i;
	int		fdcnt;

	fdcnt = 1;
	if (!(argc > 1))
		printf("\e[91m[Error]		not Enough arguments!\33[m\n");

	while (fdcnt <= argc -1)
	{
		i = 0;
		fd[fdcnt] = open(argv[fdcnt], O_RDONLY);
		// see if i can read the file
		if (fd[fdcnt] < 0)
		{
			printf("\e[91m[ERROR]	Could not read file: %s\n", argv[fdcnt]);
			return (-1);
		}
		printf("\e[32mFD: %d	FILE: %s\e[39m\n", fd[fdcnt], argv[fdcnt]);
		// show content of file to screen
		while ((ret = get_next_line(fd[fdcnt], &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
			i++;
		}
		close (fd[fdcnt]);
		fdcnt++;
	}
	return (1);
}
