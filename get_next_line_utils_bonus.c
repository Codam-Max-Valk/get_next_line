/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 13:43:07 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/28 17:13:25 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

int	ft_strlen(const char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;
	size_t	i;

	if (!s1)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc (s1len + s2len + 1);
	if (!ptr)
		return (ft_free(s1));
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		ptr[s1len + i] = s2[i];
	ptr[s1len + s2len] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else
		return (0);
}
