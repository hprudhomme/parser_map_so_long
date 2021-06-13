/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:53:11 by hprudhom          #+#    #+#             */
/*   Updated: 2021/01/13 13:58:36 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_breakline(char **src, char **line)
{	
	// printf("ret = %d\n", ret);
	int		len;
	char	*tmp;
	// char	buf[BUFFER_SIZE + 1];

	len = 0;
	while ((*src)[len] != '\n' && (*src)[len] != '\0')
		len++;
	if ((*src)[len] == '\n')
	{
		*line = ft_substr(*src, 0, len);
		tmp = ft_strdup(&((*src)[len + 1]));
		free(*src);
		*src = tmp;
		if ((*src)[0] == '\0')
		{	
			// printf("je suis la\n");
			ft_strdel(src);
			return (0);
		}
	}
	else
	{	
		// printf("je suis ici\n");
		*line = ft_strdup(*src);
		ft_strdel(src);
		return (0);
	}
	// ret = read(fd, buf, 2))
	// if (ret != 0)
	// {	
	// 	buf[ret] = '\0';
	// 	tmp = ft_strjoin(src[fd], buf);
	// 	free(src[fd]);
	// 	src[fd] = tmp;
	// }
	// else
	// 	return (0);

	// printf("line = %s\n", *line);
	// printf("src-end = %s\n", *src);
	return (1);
}

static int		ft_verif(char **src, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && src[fd] == NULL)
		return (0);		
	else
		return (ft_breakline(&src[fd], line));
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static char		*src[4096];
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (src[fd] == NULL)
			src[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(src[fd], buf);
			free(src[fd]);
			src[fd] = tmp;
		}
		if (ft_strchr(src[fd], '\n'))
			break ;
	}
	return (ft_verif(src, line, ret, fd));
}
