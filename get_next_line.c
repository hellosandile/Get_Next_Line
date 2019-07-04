/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:06:22 by samkhize          #+#    #+#             */
/*   Updated: 2019/07/04 14:15:26 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *start,char **line)
{
	size_t i;
	char *temp;
	char *temp2;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	*line = ft_strsub(start, 0, i);
	if (ft_strchr(start, '\n') != NULL)
	{
		temp2 = start;
		temp = ft_strchr(start, '\n');
		temp++;
		temp = ft_strdup(temp);
		free(temp2);
	}
	else
	{
		temp = ft_strdup("");
	}
	return (temp);
}

int	get_next_line(const int fd, char **line)
{
	static char *raed;
	char *temp;
	char buf[BUFF_SIZE + 1];
	int retu;

	if (read(fd, buf, 0) < 0 || fd < 0 || BUFF_SIZE < 1 )
		return (-1);
	if (raed == NULL)
		raed = ft_strdup("");
	while (ft_strchr(raed, '\n') == NULL)
	{
		retu = read(fd, buf, BUFF_SIZE);
			if (raed == NULL)
				break;
		buf[retu] = '\0';
		raed = ft_strjoin(raed, buf);
	}
	if (retu == 0 && raed == '\0')
		return (0);
	raed = ft_readline(raed, line);
	return (1);
}
