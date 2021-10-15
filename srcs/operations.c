/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 operations.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: jescully <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2021/10/04 10:15:07 by jescully		   #+#	  #+#			  */
/*	 Updated: 2021/10/15 15:52:31 by jescully		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../libft/libft.h"
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



void	quicksort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

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
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
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
	arrcpy = (int *)malloc(sizeof(int) * len);
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
