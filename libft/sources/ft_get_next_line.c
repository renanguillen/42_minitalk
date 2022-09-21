/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:25:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:19:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_freethis(char **str)
{
	if (str[0])
	{
		free(str[0]);
		str[0] = NULL;
	}
}

static char	*ft_badsplit(char **line_static)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	if (!line_static[0])
		return (NULL);
	while (line_static[0][i] != '\n' && line_static[0][i] != '\0')
		i++;
	line = ft_substr(line_static[0], 0, (i + 1));
	temp = ft_strdup(line_static[0]);
	ft_freethis(line_static);
	line_static[0] = ft_substr(temp, (i + 1), ft_strlen(temp));
	ft_freethis(&temp);
	if (!ft_strchr(line, '\n'))
	{
		if (!ft_strlen(line))
			ft_freethis(&line);
		ft_freethis(line_static);
	}
	return (line);
}

char	*ft_get_next_line(int fd)
{
	char		*found;
	char		*temp;
	static char	*line_static;
	int			file_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	found = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	file_read = read (fd, found, BUFFER_SIZE);
	while (file_read > 0)
	{
		found[file_read] = 0;
		if (line_static == NULL)
			line_static = ft_strdup(found);
		else
		{
			temp = ft_strjoin(line_static, found);
			ft_freethis(&line_static);
			line_static = temp;
		}
		if (ft_strchr(line_static, '\n'))
			break ;
		file_read = read (fd, found, BUFFER_SIZE);
	}
	return (ft_freethis(&found), ft_badsplit(&line_static));
}
