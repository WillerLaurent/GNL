/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:18:39 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/21 17:06:01 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	init(char **line, int fd, char *buffover)
{
	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (0);
	if (ft_strlen(buffover) == 0)
		ft_bzero(buffover, BUFFER_SIZE);
	*line = ft_calloc(1, sizeof(char));
	if (*line == NULL)
		return (0);
	return (1);
}

int	cut_string(char **line, char *buffover, int value)
{
	int		buff_len;
	char	temp[BUFFER_SIZE + 1];

	buff_len = ft_strlen(buffover);
	ft_bzero(temp, buff_len);
	if (buff_len > 0)
	{
		ft_strlcpy(temp, buffover, buff_len + 1);
		ft_strlcpy(buffover, temp + value + 1, buff_len - value + 1);
		temp[value] = 0;
		if (!(*line = ft_strjoin(*line, temp)))
			return (-1);
	}
	if (value == 0 && buff_len == 0)
		return (0);
	return (1);
}

int	read_line(char **line, int fd, char *buffover)
{
	int r;

	if (!(*line = ft_strjoin(*line, buffover)))
		return (-1);
	r = read(fd, buffover, BUFFER_SIZE);
	if (r == -1)
		return (r);
	buffover[r] = '\0';
	return (r);
}

int	get_next_line(int fd, char **line)
{
	static char	buffover[BUFFER_SIZE + 1];
	int			r;
	int			rtn_check;

	if (!init(line, fd, buffover))
		return (-1);
	while ((rtn_check = check_line(buffover)) == -1)
	{
		if ((r = read_line(line, fd, buffover)) == -1)
		{
			*line = 0;
			return (-1);
		}
		if (r == 0)
			return (cut_string(line, buffover, 0));
	}
	return ((cut_string(line, buffover, rtn_check)));
}
