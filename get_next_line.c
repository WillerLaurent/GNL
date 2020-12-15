/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:18:39 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/15 13:04:07 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#define BUFFER_SIZE 100

int check_line(char *str)
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



int get_next_line(int fd, char **line)
{
	static char str[BUFFER_SIZE + 1];
	int r;
	int rtn_check;
	char buffer[BUFFER_SIZE + 1];
	//char temp[BUFFER_SIZE + 1];
	int i;
//	int j;
	printf("*********debut get_next_line********\n");
	printf("line debut ft_get = [%s]\n", *line);

	if (line == NULL || fd == -1 || BUFFER_SIZE == 0)
		return (-1);

	*line = ft_calloc(1, sizeof(char));
	if (*line == NULL)
		return (0);
	//*line = 0;
	printf("line apres calloc = [%s]\n", *line);
	printf("str = [%s]\n", str);

	ft_bzero(buffer, BUFFER_SIZE);
	while ((rtn_check = check_line(str)) == 0)
	{
				printf("******1e partie***********\n");

		printf("str1 = [%s]\n", str);
		printf("rtn_check = [%d]\n", rtn_check);
		if (ft_strlen(str) > 0)
		{
			*line = ft_strjoin(*line, str); // proteger le malloc
			printf("line = [%s]\n", *line);
		}
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = 0;
			printf("buffer apres read = [%s]\n", buffer);
		
		ft_strlcpy(str, buffer, BUFFER_SIZE + 1);
		if (r < BUFFER_SIZE && (rtn_check = check_line(str) == 0))//passe dans fin si BUFFERSIZE > longueur du fichier
		{
			printf("fin\n");
			rtn_check = 1;
			r = 0;
			break;
		}
	}
	if (rtn_check == 1)
	{
		printf("******2e partie***********\n");
		printf("rtn_check = [%d]\n", rtn_check);
			printf("str3 = %s\n", str);
				printf("buffer debut 2e partie = [%s]\n", buffer);

		if (ft_strlen(buffer) == 0 && ft_strlen(str) > 0)
		{
			printf("if strlen buffer\n");
			
			ft_strlcpy(buffer, str, BUFFER_SIZE);

			r = 1;
		}
		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		//	printf("i = %d\n", i);
		str[i] = 0;
		*line = ft_strjoin(*line, str); //proteger le malloc
					printf("line2 = [%s]\n", *line);

	//temp[0] = 0;
	ft_bzero(str, BUFFER_SIZE);
	printf("r = %d\n", r);
	printf("buffer apres bzero = [%s]\n", buffer);

		if (r > 0)
		{
		ft_strlcpy(str, buffer + i + 1, BUFFER_SIZE + 1);
		ft_bzero(buffer, BUFFER_SIZE);
		printf("str5 = %s\n", str);
			printf("buffer avant rtn1 = [%s]\n", buffer);
			return (1);
		}
	}
	return (0);
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
	line = NULL;

	fd = open("texte", O_RDONLY);
	//fd = 0;
	while ((j = get_next_line(fd, &line)) == 1)
	{
		printf("*** %d) result=%d line=[%s]*******\n\n", i, j, line);
		i++;
		free(line);
		//line = NULL;
	}
	printf("*** %d) result =%d Ligne=[%s]\n\n", i, j, line);
	free(line);
	close(fd);
//	while (1);

	
}
