/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:43:04 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 15:01:02 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_chunck_size(t_stacks *s)
{
	if (s->size_a < 30)
		return (8);
	if (s->size_a < 50)
		return (10);
	if (s->size_a < 100)
		return (15);
	else if (s->size_a < 200)
		return (20);
	else if (s->size_a < 300)
		return (30);
	else if (s->size_a < 400)
		return (45);
	else
		return (s->size_a / 11);
}

void	purge_a(t_stacks *s)
{
	while (s->size_a != 0)
	{
		if (s->size_a == 3)
			lil_sort(s);
		push_b(s, "pb\n");
	}
}

void	push_to_b(t_stacks *s, int low, int high, int divisor)
{
	int	i;
	int	pivot;
	int	chunck_size;

	i = 0;
	chunck_size = get_chunck_size(s);
	if (s->size_a <= chunck_size)
		purge_a(s);
	if (s->size_a > chunck_size)
		pivot = get_pos(s->stacks, s->size_a, chunck_size);
	else
		pivot = 0;
	while (i++ <= s->size_a + s->size_b - 1 && s->size_a != 0 && \
			get_pos(s->stacks, s->size_a, 0) >= pivot)
	{
		if (get_pos(s->stacks, s->size_a, 1) < pivot)
			get_to_top_a(s, where_is_min(s->stacks, \
						get_pos(s->stacks, s->size_a, 0), s->size_a));
		if (s->stacks[s->size_a - 1] >= pivot)
			push_b(s, "pb\n");
		else
			rotate_a(s, "ra\n");
	}
	if (s->size_a != 0)
		push_to_b(s, low + chunck_size, high, divisor);
}

void	and_back_to_a(t_stacks *s)
{
	int	swap;

	swap = 0;
	while (s->size_b != 0)
	{
		if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 0))
		{
			push_a(s, "pa\n");
			if (swap == 1 && s->stacks_b[s->size_b - 1] \
					> s->stacks_b[s->size_b - 2])
				swap_both(s, "ss\n");
			else if (swap == 1)
				swap_a(s, "sa\n");
			swap = 0;
		}
		else if (s->stacks_b[s->size_b - 1] \
				== get_pos(s->stacks_b, s->size_b, 1) && swap == 0)
		{
			push_a(s, "pa\n");
			swap = 1;
		}
		else
			get_to_top(s, where_is_min(s->stacks_b, \
						get_pos(s->stacks_b, s->size_b, 0), s->size_b));
	}
}

int	quick(t_stacks *s)
{
	push_to_b(s, 0, s->size_a, 7);
	and_back_to_a(s);
	return (1);
}
