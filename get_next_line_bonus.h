/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:04:16 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/27 11:05:35 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_index(char *s);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_add(char **str, int i);
char	*ft_result(char **str, char **dst, int i);
char	*ft_get_line(char **str, char **dst, char **buffer, int fd);

#endif
