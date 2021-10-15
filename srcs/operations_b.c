/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:01:31 by jescully          #+#    #+#             */
/*   Updated: 2021/10/15 16:01:43 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_b(t_stacks *s, char *out)
{
	int	temp;

	if (s->size_b != 0)
	{
		temp = s->stacks[s->start_b + s->size_b - 1];
		s->stacks[s->start_b + s->size_b - 1] = \
								s->stacks[s->start_b + s->size_b - 2];
		s->stacks[s->start_b + s->size_b - 2] = temp;
	}
	ft_putstr_fd(out, 1);
	return (1);
}

int	push_b(t_stacks *s, char *out)
{
	if (s->size_a != 0)
	{
		s->stacks[s->start_b + s->size_b] = s->stacks[s->size_a - 1];
		s->size_b++;
		s->size_a--;
	}
	ft_putstr_fd(out, 1);
	return (1);
}

int	reverse_rotate_b(t_stacks *s, char *out)
{
	int	temp;
	int	d;

	if (s->size_b != 0)
	{
		d = s->start_b;
		temp = s->stacks[s->start_b];
		while (d < s->start_b + s->size_b - 1)
		{
			s->stacks[d] = s->stacks[d + 1];
			d++;
		}
		s->stacks[s->start_b + s->size_b - 1] = temp;
	}
	ft_putstr_fd(out, 1);
	return (1);
}

int	rotate_b(t_stacks *s, char *out)
{
	int	temp;
	int	d;

	if (s->size_b != 0)
	{
		d = s->size_b - 1;
		temp = s->stacks[s->start_b + s->size_b - 1];
		while (d > 0)
		{
			s->stacks[s->start_b + d] = s->stacks[s->start_b + d - 1];
			d--;
		}
		s->stacks[s->start_b] = temp;
	}
	ft_putstr_fd(out, 1);
	return (1);
}
