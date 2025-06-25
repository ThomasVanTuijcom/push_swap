/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:11:06 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/05 16:04:16 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char **str)
{
	int		i;
	char	*result;
	char	*tmp;

	if (!*str)
		return (NULL);
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	result = ft_substr_gnl(*str, 0, i + 1);
	if (!result)
		return (NULL);
	tmp = *str;
	if ((*str)[i] == '\n')
		*str = ft_strdup_gnl(*str + i + 1);
	else
		*str = ft_strdup_gnl("");
	free(tmp);
	if (!*str)
		return (NULL);
	return (result);
}

static void	*free_saved(char **saved)
{
	if (*saved)
	{
		free(*saved);
		*saved = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*saved = NULL;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(saved, '\n') && (bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			saved = ft_strjoin_gnl(&saved, buffer);
			if (!saved)
				return (NULL);
		}
	}
	if (bytes_read < 0 || !saved || !*saved)
		return (free_saved(&saved));
	return (get_line(&saved));
}
