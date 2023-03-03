/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sv <sv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:48:21 by sbocanci          #+#    #+#             */
/*   Updated: 2023/03/03 10:28:41 by sv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*readed_line[OPEN_MAX];
	char		*buff;
	int			readed;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buff))
		return (-1);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		buff[readed] = '\0';
		if (!(readed_line[fd]))
			readed_line[fd] = ft_strdup(buff);
		else
			paste_line(&readed_line[fd], buff); // ok
		if (ft_strchr(buff, '\n')) // ok
			break ;
	}
	free(buff);
	return (result(line, readed_line, fd, readed)); // ok
}

void	paste_line(char **readed_line, char *buff)
{
	char		*tmp;

	tmp = ft_strjoin(*readed_line, buff); // ok
	free(*readed_line);
	*readed_line = tmp;
}

static int	result(char **line, char **readed_line, int fd, int readed)
{
	int		len;
	char	*tmp;

	if (readed < 0)
		return (-1);
	else if (readed == 0 && readed_line[fd] == NULL && *line)
		return (0);
	len = 0;
	while (readed_line[fd][len] != '\n' && readed_line[fd][len] != '\0')
		len++;
	if (readed_line[fd][len] == '\n')
	{
		*line = ft_substr(readed_line[fd], 0, len); // ok
		tmp = ft_strdup(&readed_line[fd][len + 1]); // ok
		free(readed_line[fd]);
		readed_line[fd] = tmp;
		if (readed_line[fd][0] == '\0')
			ft_strdel(&readed_line[fd]); // ok
		return (1);
	}
	*line = ft_strdup(readed_line[fd]);
	ft_strdel(&readed_line[fd]);
	return (0);
}

static void	ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

/*
** libft
*/
char	*ft_strchr(const char *s, int c)
{
	if (*s == (char)c)
		return ((char *)s);
	else if (!*s)
		return (0);
	else
		return (ft_strchr(++s, c));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1); // ok
	len2 = ft_strlen(s2);
	join = malloc((len1 + len2 + 1) * sizeof(*join));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[len1++] = s2[i];
	join[len1] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	substr = malloc((len + 1) * sizeof(*substr));
	if (!substr)
		return (0);
	while ((i < len) && (start + i) < slen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = -1;
	s = malloc((ft_strlen(s1) + 1) * sizeof(*s));
	if (!s1 || !s)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}

size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (ft_strlen(s + 1) + 1);
}
