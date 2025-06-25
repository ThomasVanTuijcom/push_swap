/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:27:21 by tvan-tui          #+#    #+#             */
/*   Updated: 2025/02/05 16:04:35 by tvan-tui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*result;
	size_t	s1_length;
	size_t	s2_length;
	size_t	i;
	size_t	j;

	s1_length = ft_strlen_gnl(*s1);
	s2_length = ft_strlen_gnl(s2);
	result = (char *) malloc(sizeof(char) * (s1_length + s2_length + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_length)
		result[i++] = (*s1)[j++];
	j = 0;
	while (j < s2_length)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(*s1);
	return (result);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	result = (char *) malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_gnl(s) - start < len)
		len = ft_strlen_gnl(s) - start;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (len)
	{
		result[i++] = s[start++];
		len--;
	}
	result[i] = '\0';
	return (result);
}
