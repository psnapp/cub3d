/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:17:48 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/16 18:06:44 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_stack(char **stack, char **line, int *error)
{
	char	*flag;
	char	*freeline;

	if (!(flag = NULL) && *stack)
	{
		if ((flag = ft_strchr(*stack, '\n')))
		{
			*flag = '\0';
			*line = ft_strdup(*stack);
			freeline = *stack;
			*stack = ft_strdup(++flag);
			free(freeline);
		}
		else
		{
			*line = ft_strdup(*stack);
			ft_bzero(*stack, ft_strlen(*stack));
			free(*stack);
			*stack = NULL;
		}
	}
	else
		*line = ft_strdup("");
	*error = !line || !stack ? -1 : 0;
	return (flag);
}

static int		ft_return(int i, char *flag, int error, char *buff)
{
	free(buff);
	if (error == -1)
		return (-1);
	if (i > 0 || flag)
		return (1);
	return (i);
}

void			ft_line(char **line, char *buff, char *line1, int *error)
{
	line1 = *line;
	if (!(*line = ft_strjoin(*line, buff)))
		*error = -1;
	free(line1);
	line1 = 0;
}

int				get_next_line(int fd, char **line)
{
	t_gnl			vars;
	static char		*stack;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(vars.buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)))))
		return (-1);
	vars.error = 0;
	vars.flag = ft_stack(&stack, line, &vars.error);
	while (!vars.flag && (vars.i = read(fd, vars.buff, BUFFER_SIZE)) >= 0)
	{
		if (vars.i == 0)
			return (ft_return(vars.i, vars.flag, vars.error, vars.buff));
		vars.buff[vars.i] = '\0';
		if ((vars.flag = ft_strchr(vars.buff, '\n')))
		{
			*vars.flag = '\0';
			vars.line1 = stack;
			stack = ft_strdup(++vars.flag);
			free(vars.line1);
			vars.line1 = 0;
		}
		ft_line(line, vars.buff, vars.line1, &vars.error);
	}
	return (ft_return(vars.i, vars.flag, vars.error, vars.buff));
}
