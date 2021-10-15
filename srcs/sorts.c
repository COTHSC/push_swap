/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 sorts.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: jescully <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2021/10/15 15:01:56 by jescully		   #+#	  #+#			  */
/*	 Updated: 2021/10/15 16:37:19 by jescully		  ###	########.fr		  */
/*																			  */
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

int	push_to_b(t_stacks *s, int low, int high, int divisor)
{
	int	i;
	int	pivot;
	int	chunck_size;

	i = 0;
	chunck_size = (high / divisor++) - 1;
	if (s->size_a <= chunck_size)
	{
		while (s->size_a != 0)
			push_b(s, "pb\n");
	}
	pivot = get_pos(s->stacks, s->size_a, chunck_size);
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
	while (s->size_a != 0)
		push_to_b(s, low + chunck_size, high, divisor);
	return (1);
}

int	and_back_to_a(t_stacks *s, int low, int high)
{
	int	swap;

	low++;
	high++;
	high--;
	swap = 0;
	while (s->size_b != 0)
	{
		if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 0))
		{
			push_a(s, "pa\n");
			if (swap == 1 && s->stacks_b[s->size_b - 1] > s->stacks_b[s->size_b - 2])
				swap_both(s, "ss\n");
			else if (swap == 1)
				swap_a(s, "sa\n");
			swap = 0;
		}
		else if (s->stacks_b[s->size_b - 1] == get_pos(s->stacks_b, s->size_b, 1) && swap == 0)
		{
			push_a(s, "pa\n");
			swap = 1;
		}
		else
			get_to_top(s, where_is_min(s->stacks_b, get_pos(s->stacks_b, s->size_b, 0), s->size_b));
	}
	return (1);
}

int	quick(t_stacks *s, int low, int high)
{
	low++;
	push_to_b(s, 0, s->size_a, 11);
	and_back_to_a(s, 0, high);
	return (1);
}
