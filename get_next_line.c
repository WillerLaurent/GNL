/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:18:39 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/17 11:42:02 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

int		check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		init(char **line, int fd, char *buffer, char *buffover)
{
	if (fd == -1 || fd > 256 || BUFFER_SIZE <= 0)
		return (0);
	*line = ft_calloc(1, sizeof(char));
	if (*line == NULL)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE);
	if (ft_strlen(buffover) == 0)
		ft_bzero(buffover, BUFFER_SIZE);
	return (1);
}

int		cut_string(char **line, char *buffover, char *buffer, int r)
{
	int i;

	i = 0;
	if (ft_strlen(buffer) == 0 && ft_strlen(buffover) > 0)
		ft_strlcpy(buffer, buffover, r);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	ft_bzero(buffover, r);
	ft_strlcpy(buffover, buffer + i + 1, r + 1);
	buffer[i] = 0;
	if (!(*line = ft_strjoin(*line, buffer)))
	{
		free(*line);
		return (0);
	}
	ft_bzero(buffer, r);
	if (r > 0)
		return (1);
	return (0);
}

int		read_line(char **line, int fd, char *buffer, char *buffover)
{
	int r;

	if (!(*line = ft_strjoin(*line, buffover)))
	{
		free(*line);
		return (0);
	}
	r = read(fd, buffer, BUFFER_SIZE);
	buffer[r] = '\0';
	if (r == -1)
		return (-1);
	ft_bzero(buffover, r);
	ft_strlcpy(buffover, buffer, r + 1);
	return (r);
}

int		get_next_line(int fd, char **line)
{
	static char	buffover[BUFFER_SIZE + 1];
	static int	r;
	int			rtn_check;
	char		buffer[BUFFER_SIZE + 1];

	if (!init(line, fd, buffer, buffover))
		return (-1);
	while (!(rtn_check = check_line(buffover)))
	{
		r = read_line(line, fd, buffer, buffover);
		if (r < 0)
			return (-1);
		if (r < BUFFER_SIZE && !(check_line(buffover)))
		{
			r = 0;
			rtn_check = 1;
			break ;
		}
	}
	if (rtn_check == 1)
	{
		if (cut_string(line, buffover, buffer, r))
			return (1);
	}
	return (0);
}
