/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:02:41 by jescully          #+#    #+#             */
/*   Updated: 2021/10/15 16:02:47 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_both(t_stacks *s, char *out)
{
	swap_a(s, "");
	swap_b(s, "");
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

int	rotate_both(t_stacks *s, char *out)
{
	rotate_a(s, "");
	rotate_b(s, "");
	ft_putstr_fd(out, 1);
	return (1);
}
