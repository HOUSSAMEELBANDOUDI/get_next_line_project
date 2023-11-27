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

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str[1024];
	char		*dst;
	int			nl;
	int			byt_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byt_read = read(fd, buffer, BUFFER_SIZE);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (!str[fd])
		return (NULL);
	while (byt_read >= 0)
	{
		buffer[byt_read] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
		nl = ft_index(str[fd]);
		if (nl != -1)
			return (ft_result(&str[fd], &dst, nl));
		if (!byt_read && !str[fd][0])
			break ;
		if (!byt_read)
			return (ft_add(&str[fd], 0));
		byt_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (NULL);
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
/*int	main(void)
{
	int fd = open("test.txt", O_RDONLY | O_CREAT);
	int fd1 = open("hm.txt", O_RDONLY | O_CREAT);
	char *s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		s = get_next_line(fd1);
	}
	printf("%s", s);

	// while(1);
}*/