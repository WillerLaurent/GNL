/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <lwiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:57:20 by lwiller           #+#    #+#             */
/*   Updated: 2020/12/10 13:53:34 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strcpy(char *dst, const char *src);
int		get_next_line(int fd, char **line);

#endif
