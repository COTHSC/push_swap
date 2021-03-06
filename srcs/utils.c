/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:21:58 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 16:28:54 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_string(char *s)
{
	if (!check_argstr(s))
	{
		free (s);
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	if (check_str(s))
	{
		free (s);
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
}

int	fill_struct(t_stacks *s, char **argv, int argc)
{
	char	*argstr;
	char	**argray;

	argstr = concat_arg(argv, argc);
	check_string(argstr);
	argray = ft_split(argstr, ' ');
	free (argstr);
	s->size_a = 0;
	while (argray[s->size_a])
		s->size_a++;
	s->stacks = (int *)ft_calloc(sizeof(int), s->size_a * 2 + 1);
	if (!s->stacks)
		exit (1);
	s->size_b = 0;
	s->start_b = s->size_a;
	s->stacks_b = &s->stacks[s->start_b];
	if (!fill_stack(s, argray, s->size_a))
		return (0);
	free(argray);
	return (1);
}

int	fill_stack(t_stacks *s, char **argray, int i)
{
	int	d;

	d = 0;
	while (i > 0)
	{
		if (ft_isint(ft_atoi(argray[d])) && \
				ft_unique_int(s, ft_atoi(argray[d]), d))
			s->stacks[i - 1] = ft_atoi(argray[d]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			while (argray[d])
				free(argray[d++]);
			free(argray);
			free(s->stacks);
			exit (0);
		}
		free(argray[d]);
		i--;
		d++;
	}
	return (1);
}
