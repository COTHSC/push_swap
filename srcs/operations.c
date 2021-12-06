/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:25:04 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 16:29:49 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quicksort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	if (low < high)
	{
		i = low;
		j = high;
		pivot = low;
		while (i < j)
		{
			while (arr[i] > arr[pivot] && i != high)
				i++;
			while (arr[j] <= arr[pivot] && j != low)
				j--;
			if (i < j)
			{
				ft_swap_ptr(&arr[i], &arr[j]);
			}
		}
		ft_swap_ptr(&arr[i], &arr[j]);
		quicksort(arr, low, j - 1);
		quicksort(arr, j + 1, high);
	}
}

int	get_pos(int *arr, int len, int pos)
{
	int	i;
	int	*arrcpy;
	int	ret;

	i = 0;
	arrcpy = (int *)ft_calloc(sizeof(int), len + 2);
	if (!arrcpy)
		exit (0);
	while (i < len)
	{
		arrcpy[i] = arr[i];
		i++;
	}
	quicksort(arrcpy, 0, len - 1);
	ret = arrcpy[pos];
	free(arrcpy);
	return (ret);
}

int	get_to_top_a(t_stacks *s, int pos)
{
	int	i;

	if (pos > s->size_a - 1)
		pos -= s->size_a;
	if (pos < 0)
		pos += s->size_a;
	i = 0;
	if (pos >= (s->size_a - 1) / 2)
	{
		while (pos++ != (s->size_a - 1))
		{
			rotate_a(s, "ra\n");
			i++;
		}
	}
	else
	{
		while (pos-- != -1)
		{
			reverse_rotate_a(s, "rra\n");
			i--;
		}
	}
	return (i);
}

int	get_to_top(t_stacks *s, int pos)
{
	int	i;

	if (pos > s->size_b - 1)
		pos -= s->size_b;
	if (pos < 0)
		pos += s->size_b;
	i = 0;
	if (pos >= (s->size_b - 1) / 2)
	{
		while (pos++ != (s->size_b - 1))
		{
			rotate_b(s, "rb\n");
			i++;
		}
	}
	else
	{
		while (pos-- != -1)
		{
			reverse_rotate_b(s, "rrb\n");
			i--;
		}
	}
	return (i);
}

int	where_is_min(int *arr, int min, int len)
{
	int	i;

	i = 0;
	while (arr[i] != min && i < len)
		i++;
	return (i);
}
