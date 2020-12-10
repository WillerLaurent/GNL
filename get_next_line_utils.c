/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:36:09 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/10 09:11:22 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*str;

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
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		len;
	int		i;

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

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*char	*ft_strchr(const char *str, int c)
{
	int i;

	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}*/

char	*ft_strcpy(char *dst, const char *src)
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

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	len_str;
	size_t			i;

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
