/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:04:58 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 14:55:19 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort(t_stacks *s)
{
	if (is_sorted(s, 0, s->size_a, 'a') || s->size_a == 1)
		;
	else if (s->size_a <= 3)
		lil_sort(s);
	else if (s->size_a <= 5)
		small_sort(s);
	else
		quick(s);
	free(s->stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc != 1)
	{
		if (!fill_struct(&s, argv, argc))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		sort(&s);
	}
	return (0);
}
