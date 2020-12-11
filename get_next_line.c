/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:18:39 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/11 08:49:00 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(char **line, char **str, int fd)
{
	if (line == NULL || fd == -1)
		return (0);
	if (!*str)
	{
		if (!(*str = malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (0);
	}
	return (1);
}

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
	static char	*str;
	int			i;

	if (!check_error(line, &str, fd))
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = read_line(str, fd);
	i = 0;
	if (str[i])
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
