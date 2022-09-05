/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:20:42 by prossi            #+#    #+#             */
/*   Updated: 2022/09/05 13:37:00 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//get_next_line_utils.c
int		ft_strlen(char *str);
char	*ft_strdup(char *str);

//get_next_line.c
char	*get_next_line(int fd);

#endif
