/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:18:39 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/10 10:40:14 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 100

char	*read_line(char *str, int fd)
{
	int		r;
	char	buffer[BUFFER_SIZE + 1];

	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = 0;
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char *str;
	int			i;

	if (!(str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = read_line(str, fd);
	i = 0;
	if (*str)
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_substr(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	char *line;
	int fd;
	int i;
	int j;

	(void)ac;
	(void)av;
	i = 1;
	fd = open("texte", O_RDONLY);
	//fd = 0;
	while ((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		//line = NULL;
	}
}
