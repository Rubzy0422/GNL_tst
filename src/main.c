/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 09:50:07 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/14 12:17:32 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int		multicheck(int argc, char **argv)
{
	int		fd[1100];
	char	*line;
	int		ret;
	int		fdcnt;

	fdcnt = 1;
	//Read Line 1
	while (fdcnt <= argc -1)
	{
		fd[fdcnt] = open(argv[fdcnt], O_RDONLY);
		if (fd[fdcnt] < 0)
		{
			printf("\e[91m[ERROR]	Could not read file: %s\n", argv[fdcnt]);
			return (-1);
		}
		if ((ret = get_next_line(fd[fdcnt], &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		fdcnt++;
	}
	//read body
	fdcnt = 1;
	while (fdcnt <= argc -1)
	{
		while ((ret = get_next_line(fd[fdcnt], &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		fdcnt++;
		close (fd[fdcnt]);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd[1100];
	char	*line;
	int		ret;
	int		fdcnt;

	fdcnt = 1;
	if (argc == 1)
	{
		printf("\e[91m[Error]		Give me something to read!\33[m\n");
		return (0);
	}
	while (fdcnt <= argc -1)
	{
		fd[fdcnt] = open(argv[fdcnt], O_RDONLY);
		if (fd[fdcnt] < 0)
		{
			printf("\e[91m[ERROR]	Could not read file: %s\n", argv[fdcnt]);
			return (-1);
		}
		while ((ret = get_next_line(fd[fdcnt], &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		close (fd[fdcnt]);
		fdcnt++;
	}
	char mfd;

	printf("\e[93mMulti FD?[y/n]:\n\33[m");
	scanf("%c", &mfd);
	if (mfd == 'y' || mfd == 'Y')
		if (multicheck(argc, argv))
			printf("Didn't Break ...!\n");
	
	printf("\e[92mDONE!\n");
	return (0);
}
