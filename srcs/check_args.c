/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:11:18 by jescully          #+#    #+#             */
/*   Updated: 2021/12/06 14:21:11 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*concat_arg(char **argv, int argc)
{
	int		i;
	char	*argstr;
	char	*temp;

	argstr = ft_strdup(" ");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(argstr, " ");
		free(argstr);
		argstr = ft_strjoin(temp, argv[i++]);
		free(temp);
	}
	return (argstr);
}

int	ft_is_valid_char(char *s, int i)
{
	if (ft_issign(s[i]) || ft_isdigit(s[i]))
	{
		if (ft_issign(s[i]))
		{
			if (!s[i + 1])
				return (0);
			else if (!ft_isdigit(s[i + 1]))
				return (0);
		}
	}
	return (1);
}

int	check_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_is_valid_char(s, i))
			return (1);
		i++;
	}
	return (0);
}

int	ft_unique_int(t_stacks *s, int new, int len)
{
	int	i;
	int	d;

	d = 0;
	i = s->size_a;
	while (d < len)
	{
		if (s->stacks[i - d - 1] == new)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		d++;
	}
	return (1);
}
