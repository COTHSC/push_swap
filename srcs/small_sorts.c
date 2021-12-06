/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:44:05 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 14:45:42 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	lil_sort(t_stacks *s)
{
	if (s->size_a == 2)
		(swap_a(s, "sa\n"));
	else
	{
		if (s->stacks[0] > s->stacks[1] && s->stacks[0] > \
				s->stacks[2] && s->stacks[1] < s->stacks[2])
			swap_a(s, "sa\n");
		else if (s->stacks[0] < s->stacks[1] && s->stacks[1] < s->stacks[2])
		{
			swap_a(s, "sa\n");
			reverse_rotate_a(s, "rra\n");
		}
		else if (s->stacks[0] > s->stacks[1] && s->stacks[0] < s->stacks[2])
			rotate_a(s, "ra\n");
		else if (s->stacks[0] < s->stacks[1] && s->stacks[1] > \
				s->stacks[2] && s->stacks[0] > s->stacks[2])
		{
			swap_a(s, "sa\n");
			rotate_a(s, "ra\n");
		}
		else if (s->stacks[0] < s->stacks[1] && s->stacks[1] > s->stacks[2])
			reverse_rotate_a(s, "rra\n");
	}
}

void	small_sort(t_stacks *s)
{
	int	turns;

	turns = 0;
	push_b(s, "pb\n");
	if (s->size_a == 4)
		push_b(s, "pb\n");
	lil_sort(s);
	if (!is_sorted(s, s->start_b, s->size_b, 'a'))
		swap_b(s, "sb\n");
	while (s->size_b != 0 || !is_sorted(s, 0, s->size_a, 'a'))
	{
		if (s->size_b > 0 && (s->stacks_b[s->size_b - 1] < \
					s->stacks[s->size_a - 1] || turns == s->size_a))
			push_a(s, "pa\n");
		else
		{
			rotate_a(s, "ra\n");
			turns++;
		}
	}
}
