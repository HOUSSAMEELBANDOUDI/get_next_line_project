/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:58:53 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/23 16:05:58 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_result(char **str, char **dst, int i)
{
	*dst = ft_substr(*str, 0, i + 1);
	*str = ft_add(str, i + 1);
	return (*dst);
}

char	*ft_add(char **str, int i)
{
	char	*new;

	new = ft_substr(*str, i, ft_strlen(*str + i));
	free(*str);
	*str = NULL;
	return (new);
}

char	*ft_get_line(char **str, char **dst, char **buffer, int fd)
{
	int	byt_read;
	int	nl;

	byt_read = read(fd, *buffer, BUFFER_SIZE);
	while (byt_read >= 0)
	{
		(*buffer)[byt_read] = '\0';
		str[fd] = ft_strjoin(str[fd], *buffer);
		nl = ft_index(str[fd]);
		if (nl != -1)
			return (ft_result(&str[fd], dst, nl));
		if (!byt_read && !str[fd][0])
			break ;
		if (!byt_read)
			return (ft_add(&str[fd], 0));
		byt_read = read(fd, *buffer, BUFFER_SIZE);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str[OPEN_MAX];
	char		*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (!str[fd])
		return (NULL);
	dst = ft_get_line(str, &dst, &buffer, fd);
	free(buffer);
	buffer = NULL;
	return (dst);
}

int	ft_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
