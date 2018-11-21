/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:56:44 by vpozniak          #+#    #+#             */
/*   Updated: 2018/11/13 17:57:08 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_getline(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	size_t sort;
	char *s1;

    sort = (size_t)read(fd, buff, BUFF_SIZE);
	buff[sort] = '\0';
	s1 = *line;
	*line = ft_strjoin(*line ? *line : "", buff);
	free(s1);
	return (sort);

}

size_t    ft_len(const char *src)
{
	const char *i;

	i = src;
	while (*i)
		i++;
	return (i - src);
}

static int    ft_cpy(char **i, char **j)
{
    size_t	s;

    s = ft_len(*j);
    *i = ft_strdup(*j);
    if (!(*i))
        return (-1);
    ft_memset(*j, 0, s);
    return (1);
}

int          ft_audit(char **l, char **i, char **j)
{
    size_t	s;

    s = ft_len(*j + 1);
	**j = '\0';
	if (!(*l = ft_strdup(*i)))
		return (-1);
	ft_memcpy(*i, *j + 1, s + 1);
	return (1);
}

int          get_next_line(const int fd, char **line)
{
	static char *src = "";
	int sort;
	char *str;

    sort = 1;
	if (!line || fd < 0 || (src[0] == '\0' && (!(src = ft_strnew(0)))))
		return (-1);
	while (sort > 0)
	{
		if ((str = ft_strchr(src, '\n')) != 0)
		{
			ft_audit(&(*line), &src, &str);
			return (1);
		}
        sort = ft_getline(fd, &src);
	}
	if (sort == 0 && ft_len(src))
        sort = ft_cpy(&(*line), &src);
	return (sort);
}

int      main()
{
	int fd;
	char *line;
	int ret;
	//system("leaks -q a.out");
	fd = open("../test2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
		printf("%d -> %s\n", ret, line);
	// system("leaks -q a.out");
	return(0);
}