/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:36:09 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/15 09:25:35 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_strjoin(char *s1, char *s2)
{
	int len_s1;
	int len_s2;
	int i;
	int j;
	char *str;

	printf("s1 = [%s]\n", s1);
	printf("s2 = [%s]\n", s2);

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(str = malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		return (NULL);
	str[0] = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s1);
	return (str);
}

char *ft_strdup(const char *str)
{
	char *cpy;
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	if (!(cpy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	cpy[len] = 0;
	len--;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char *ft_substr(const char *str, unsigned int start, size_t len)
{
	char *sub_str;
	unsigned int len_str;
	size_t i;

	if (str == NULL)
		return (NULL);
	i = 0;
	len_str = ft_strlen(str);
	if (start >= len_str)
		return (ft_strdup(""));
	if (len > (len_str - start))
		len = len_str - start;
	if (!(sub_str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len && str[i + start])
	{
		sub_str[i] = str[i + start];
		i++;
	}
	sub_str[i] = 0;
	return (sub_str);
}

char *ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (dst);
}

void ft_bzero(void *s, size_t n)
{
	unsigned long i;
	unsigned char *str;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}

void *ft_calloc(size_t count, size_t size)
{
	size_t i;
	void *array;

	i = 0;
	array = (void *)malloc(count * size);
	if (!array)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}