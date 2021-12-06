/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:38:41 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 14:39:27 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stacks *s, int start, int length, char dir)
{
	int	d;

	d = start;
	if (dir == 'a')
	{
		while (d < start + length - 1)
		{
			if (s->stacks[d] < s->stacks[d + 1])
				return (0);
			d++;
		}
	}
	return (1);
}

int	is_min(int *array, int nbr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] < nbr)
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap_ptr(int *a, int *b)
{
	int	tempptr;

	tempptr = *a;
	*a = *b;
	*b = tempptr;
}
