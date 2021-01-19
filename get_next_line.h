/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:45:44 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/06 18:06:12 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef	struct		s_gnl
{
	char			*buff;
	char			*flag;
	int				i;
	int				error;
	char			*line1;
}					t_gnl;

int					get_next_line(int fd, char **line);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *str);
char				*ft_strchr(const char *str, int ch);
size_t				ft_strlcpy(char *dst, const char *str, size_t n);
void				ft_bzero(void *s, size_t n);

#endif
