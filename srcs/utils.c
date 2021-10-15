/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:21:58 by jescully          #+#    #+#             */
/*   Updated: 2021/10/15 15:30:08 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*concat_arg(char **argv, int argc)
{
	int		i;
	char	*argstr;
	char	*temp;

	argstr = " ";
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(argstr, " ");
		argstr = ft_strjoin(temp, argv[i++]);
		free(temp);
	}
	return (argstr);
}

int	fill_struct(t_stacks *s, char **argv, int argc)
{
	char	*argstr;
	char	**argray;

	argstr = concat_arg(argv, argc);
	if (!check_argstr(argstr))
		return (0);
	argray = ft_split(argstr, ' ');
	free (argstr);
	s->size_a = 0;
	while (argray[s->size_a])
		s->size_a++;
	s->stacks = (int *)malloc(sizeof(int) * s->size_a * 2);
	s->size_b = 0;
	s->start_b = s->size_a;
	s->stacks_b = &s->stacks[s->start_b];
	if (!fill_stack(s, argray, s->size_a))
		return (0);
	free(argray);
	return (1);
}
/*
void	print_stacks(t_stacks *s)
{
	int	d;

	d = 0;
	printf("	 stack 1		  stack 2\n");
	while (d < s->start_b)
	{
		printf("		");
		if (d < s->size_a)
			printf("%d", s->stacks[d]);
		else
			printf(" ");
		printf("				");
		if (d < s->size_b && s->size_b != 0)
			printf("%d", s->stacks[d + s->start_b]);
		printf("\n");
		d++;
	}
}
*/

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
			return (0);
		free(argray[d]);
		i--;
		d++;
	}
	return (1);
}

int	ft_isint(long long int i)
{
	if (i <= INT_MAX && i >= INT_MIN)
		return (1);
	return (0);
}

int	ft_unique_int(t_stacks *s, int new, int len)
{
	int	i;
	int	d;

	d = 0;
	i = s->size_a;
	while (d < len)
	{
		if (s->stacks[i - d - 1] == new)
			return (0);
		d++;
	}
	return (1);
}
