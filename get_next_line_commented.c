/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:49 by prossi            #+#    #+#             */
/*   Updated: 2021/10/21 18:04:38 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

/* read_line is assigned a value to make it run.
 * If the value is less than one there is an error. 
 * If the value is zero it is the end of the file.
 * If there is no backup, give it the value of an empty strdup.
 * Char_Temp is assigned the value of backup, and backup is assigned 
 * the value of strjoin, which is Char_Temp with buffer attached to the end.
 * Char_Temp is freed. If a newline is found in buffer the loop is broken.
 * Backup is then returned.*/

static char	*function_name(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

/* count is set to zero and incremented while the value is not a newline
 * or null terminator. After incrementing through, if the value is a
 * null terminator, return zero.
 * backup is assigned the value of substr, which is created from 
 * line with starting point of count plus one, and the length of line.
 * If there is no value in backup, it is freed. 
 * Otherwise, return backup.*/

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

/* Line is the string we want to return, backup holds the 
 * leftovers of line only within it's file (hence static char).
 * If there are undefined stdin values (e.g. in fd or BUFFER_SIZE)
 * it will return zero. Buf is assigned its value; if there
 * is no buf, return zero. 
 * Line is assigned the value of char *function_name, which is made up of
 * fd, buf, and backup. Buf is freed.
 * If there is no line, return null.
 * Backup is assigned the value of static char *extract, which is the
 * line we want to return to get the end result. */

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = function_name(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
