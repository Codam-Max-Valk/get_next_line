/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:56:08 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/28 18:10:28 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
// # include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

/*get_next_line_utils*/

/**frees input 'str'
returns NULL.*/
void	*ft_free(char *str);
/**computes the length of the string 'line'.*/
int		ft_strlen(const char *line);
/**Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.*/
char	*ft_strjoin(char *s1, const char *s2);
/**allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it.*/
char	*ft_strdup(const char *s1);
/**locates the first occurrence of c (converted to a char)
in the string pointed to by s.*/
char	*ft_strchr(const char *s, int c);

/*get_next_line main functions*/

/**reads from fd to buffer until \n or eof
concatenates 'saved_str' and 'buffer' until \n or eof
returns a pointer to the created string*/
char	*ft_read_line(int fd, char *saved_str);
/**trims the input 'str'
returns a pointer to a copy of 'str' until the newline if saved = 0
returns a pointer to a copy of 'str' from newline to \0 if saved = 1*/
char	*ft_trim_str(char *str, int saved);

/**returns a line read from a file descriptor
returns NULL when there's nothing else to read,
or an error occured.*/
char	*get_next_line(int fd);

#endif
