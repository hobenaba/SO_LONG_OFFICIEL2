/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:51:26 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 09:54:33 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*ft_join(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strstop(char *s);
char	*ft_rem(char *s);

#endif
