/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:54:22 by jescully          #+#    #+#             */
/*   Updated: 2021/10/15 15:54:31 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_a(t_stacks *s, char *out)
{
	int	temp;

	if (s->size_a != 0)
	{
		temp = s->stacks[s->size_a - 1];
		s->stacks[s->size_a - 1] = s->stacks[s->size_a - 2];
		s->stacks[s->size_a - 2] = temp;
	}
	ft_putstr_fd(out, 1);
	return (1);
}

int	push_a(t_stacks *s, char *out)
{
	if (s->size_b != 0)
	{
		s->stacks[s->size_a] = s->stacks[s->start_b + s->size_b - 1];
		s->size_a++;
		s->size_b--;
	}
	ft_putstr_fd(out, 1);
	return (1);
}

int	rotate_a(t_stacks *s, char *out)
{
	int	temp;
	int	d;

	if (s->size_a != 0)
	{
		d = s->size_a - 1;
		temp = s->stacks[s->size_a - 1];
		while (d > 0)
		{
			s->stacks[d] = s->stacks[d - 1];
			d--;
		}
		s->stacks[0] = temp;
	}
	ft_putstr_fd(out, 1);
	return (1);
}

int	reverse_rotate_a(t_stacks *s, char *out)
{
	int	temp;
	int	d;

	if (s->size_a != 0)
	{
		d = 0;
		temp = s->stacks[0];
		while (d < s->size_a - 1)
		{
			s->stacks[d] = s->stacks[d + 1];
			d++;
		}
		s->stacks[s->size_a - 1] = temp;
	}
	ft_putstr_fd(out, 1);
	return (1);
}
