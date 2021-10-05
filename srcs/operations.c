/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:15:07 by jescully          #+#    #+#             */
/*   Updated: 2021/10/05 18:14:05 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/push_swap.h"

int swap_a(t_stacks *s, char *out)
{
	int temp;
	if (s->size_a != 0)
	{		
		temp = s->stacks[s->size_a - 1];
		s->stacks[s->size_a - 1] = s->stacks[s->size_a - 2];
		s->stacks[s->size_a - 2] = temp;
	}
    ft_putstr_fd(out, 1);
	return 1;	
}

int swap_b(t_stacks *s, char *out)
{
	int temp;
	if (s->size_b != 0)
	{		
		temp = s->stacks[s->start_b + s->size_b - 1];
		s->stacks[s->start_b + s->size_b -1] = s->stacks[s->start_b + s->size_b - 2];
		s->stacks[s->start_b + s->size_b - 2] = temp;
	}
    ft_putstr_fd(out, 1);
	return 1;	

}

int swap_both(t_stacks *s, char *out)
{
	swap_a(s, "");
	swap_b(s, "");
    ft_putstr_fd(out, 1);
	return (1);
}

int push_b(t_stacks *s, char *out)
{

	if (s->size_a != 0)
	{	
		s->stacks[s->start_b + s->size_b] = s->stacks[s->size_a - 1];
		s->size_b++;
		s->size_a--;
	}
    ft_putstr_fd(out, 1);
	return 1;	
}

int push_a(t_stacks *s, char *out)
{
	
	if(s->size_b != 0)
	{
		s->stacks[s->size_a] = s->stacks[s->start_b + s->size_b - 1];
		s->size_a++;
		s->size_b--;
	}

    ft_putstr_fd(out, 1);

	return 1;	
}

int	rotate_a(t_stacks *s, char *out)
{
	int temp;
	int d;

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
	int temp;
	int d;

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

int	reverse_rotate_b(t_stacks *s, char *out)
{
	int temp;
	int d;

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

int	reverse_rotate_both(t_stacks *s, char *out)
{
	reverse_rotate_a(s, "");
	reverse_rotate_b(s, "");
    ft_putstr_fd(out, 1);
	return (1);
}

int	rotate_b(t_stacks *s, char *out)
{
	int temp;
	int d;

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

int	rotate_both(t_stacks *s, char *out)
{
	rotate_a(s, "");
	rotate_b(s, "");
    ft_putstr_fd(out, 1);
	return (1);
}

int is_sorted(t_stacks *s, int start, int length)
{
	int d;

	d = start;
	while (d < start + length - 1)
	{
		if (s->stacks[d] < s->stacks[d + 1])
			return 0;
		d++;
	}
	return 1;
}
