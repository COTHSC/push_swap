/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <jescully@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:06:08 by jescully          #+#    #+#             */
/*   Updated: 2021/10/05 15:19:37 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_iswhitespace(int c)
{
	if (c == '\v' || c == '\r' || c == '\f' || \
		c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

long long int			ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long long int		result;
	char	*cnptr;

	sign = 1;
	i = 0;
	result = 0;
	cnptr = (char *)nptr;
	while (ft_iswhitespace(*cnptr))
		cnptr++;
	if (*cnptr == '-' && ft_isdigit(*(cnptr + 1)))
	{
		sign = -1;
		cnptr++;
	}
	if (*cnptr == '+' && ft_isdigit(*(cnptr + 1)))
		cnptr++;
	while (ft_isdigit(*cnptr))
	{
		result = result * 10 + (*cnptr - '0');
		cnptr++;
	}
	return (sign * result);
}
