#include "get_next_line.h"
#include "get_next_line.h"

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
	free (*str);
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
	static char	*str;
	char		*dst;
	int			nl;
	int			byt_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byt_read = read(fd, buffer, BUFFER_SIZE);
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	while (byt_read >= 0)
	{
		buffer[byt_read] = '\0';
		str = ft_strjoin(str, buffer);
		nl = ft_index(str);
		if (nl != -1)
			return (ft_result(&str, &dst, nl));
		if (!byt_read && !str[0])
			break ;
		if (!byt_read)
			return (ft_add(&str, 0));
		byt_read = read(fd, buffer, BUFFER_SIZE);
	}
	ft_free(&str);
	return (NULL);
}

int main(){
    int fd = open("test.txt", O_RDONLY);
    char *s = get_next_line(fd);
    while(s){
        printf("%s", s);
        free(s);
        s = get_next_line(fd);
    }
    printf("%s", s);

    // while(1);
}