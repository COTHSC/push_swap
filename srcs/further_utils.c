/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   further_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:17:29 by jescully          #+#    #+#             */
/*   Updated: 2021/10/15 15:29:08 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_iswhitespace(int c)
{
	if (c == '\v' || c == '\r' || c == '\f' || \
			c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

int	ft_isnumber(char *nbrstr)
{
	int	i;

	i = 0;
	while (nbrstr[i])
	{
		if (!ft_isdigit(nbrstr[i]) && !ft_iswhitespace(nbrstr[i]))
			return (0);
	}
	return (1);
}

int	ft_issign(char c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (1);
	return (0);
}

int	check_argstr(char *argstr)
{
	int	i;

	i = 0;
	while (argstr[i])
	{
		if (!ft_isdigit(argstr[i]) && !ft_iswhitespace(argstr[i]) \
				&& !ft_issign(argstr[i]))
			return (0);
		i++;
	}
	return (1);
}
