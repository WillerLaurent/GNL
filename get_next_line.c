/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:18:39 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/18 12:30:15 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 4

#include <stdio.h>

int check_line(char *str)
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

int init(char **line, int fd, char *buffover)
{
	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (0);
	if (ft_strlen(buffover) == 0)
		ft_bzero(buffover, BUFFER_SIZE);
	return (1);
}

int cut_string(char **line, char *buffover, int value)
{
	int buff_len;
	char temp[BUFFER_SIZE + 1];

	printf("*****************  cut string   ***********************\n");
	//i = 0;
	printf("value = %d\n", value);
	printf("buffover debut cut = [%s]\n", buffover);
	//temp[0] = 0;
	buff_len = ft_strlen(buffover);
	printf("buff_len = %d\n", buff_len);
	printf("value = %d\n", value);
	if (buff_len > 0)
	{
		ft_strlcpy(temp, buffover, buff_len + 1);
		printf("temp cut apres copy = [%s]\n", temp);
		ft_strlcpy(buffover, temp + value + 1, buff_len - value);
		temp[value] = 0;
		if (!(*line = ft_strjoin(*line, temp)))
		return (-1);
	}

	/*while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;*/

	//printf("temp cut apres copy et 0 = [%s]\n", temp);

	
	//	printf("buff_len = %d\n", buff_len);
	printf("buffover fin cut = [%s]\n", buffover);

	if (value == 0 && buff_len == 0)
		return (0);
	return (1);
}

int read_line(char **line, int fd, char *buffover)
{
	int r;
	char buffer[BUFFER_SIZE + 1];

	printf("***********  read line  ********************\n");

	printf("buffover debut read = [%s]\n", buffover);
	buffer[0] = 0;
	if (!(*line = ft_strjoin(*line, buffover)))
		return (-1);
	r = read(fd, buffer, BUFFER_SIZE);
	if (r == -1)
		return (r);
	buffer[r] = '\0';
	ft_strlcpy(buffover, buffer, r + 1);
	printf("buffover fin read = %s\n", buffover);

	return (r);
}

int get_next_line(int fd, char **line)
{
	printf("*****  get next  ****************\n");
	static char buffover[BUFFER_SIZE + 1];
	int r;
	int rtn_check;
	int rtn_cut;
	//char		buffer[BUFFER_SIZE + 1];

	rtn_cut = 0;
	printf("buffover get = [%s]\n", buffover);
	if (!init(line, fd, buffover))
		return (-1);
	while ((rtn_check = check_line(buffover)) == -1)
	{
		printf("rtn_check get = %d\n", rtn_check);
		//	printf("line = %p\n", *line);
		if ((r = read_line(line, fd, buffover)) == -1)
		{
			*line = 0;
			return (-1);
		}
		//buffer[r] = '\0';
		printf("r = %d\n", r);
		if (r == 0)
			return (cut_string(line, buffover, 0));
		/*if (r < BUFFER_SIZE && !(check_line(buffover)))
		{
			r = 0;//appeler cut_string avec rtn_check = 0
			rtn_check = 0;
			break ;
		}*/
	}
	//if (rtn_check >= 0)//utilité???
	printf("rtn_check get = %d\n", rtn_check);

	return ((cut_string(line, buffover, rtn_check)));
}

int main(int ac, char **av)
{
	char *line;
	int fd;
	int i;
	int j;

	(void)ac;
	(void)av;
	i = 1;
	if (!(line = ft_calloc(sizeof(char), 1)))
		return (0);
	//line = NULL;
	fd = open("texte", O_RDONLY);
	while ((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : [%s]\n\n", j, i, line);
		i++;
		printf("adresse line %p\n", line);

		free(line);
		printf("adresse line apres free %p\n", line);
		if (!(line = ft_calloc(sizeof(char), 1)))
			return (0);
		//line = NULL;
	}
	printf("%d Ligne %d : [%s]\n\n", j, i, line);
	free(line);
	close(fd);
	//while(1)
}