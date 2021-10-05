/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jescully <jescully@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:02:10 by jescully          #+#    #+#             */
/*   Updated: 2021/10/05 14:36:11 by jescully         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_ischar(char o, char c)
{
	if (o == c)
		return (1);
	return (0);
}

static int			ft_countthewords(char const *s, char c)
{
	int		i;
	int		cw;

	i = 0;
	cw = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			cw++;
		i++;
	}
	if (i == 0)
		return (0);
	if (s[0] != c)
		cw++;
	if (s[i - 1] == c)
		cw--;
	return (cw);
}

static int			ftwtw(int len, char **strs, int row, const char *s)
{
	int		collumn;

	collumn = 0;
	while (collumn < len)
	{
		strs[row][collumn] = s[collumn];
		collumn++;
	}
	strs[row++][collumn] = '\0';
	return (row);
}

char				**ft_split(char const *s, char c)
{
	int		wc;
	char	**strs;
	int		lead;
	int		follow;
	int		row;

	row = 0;
	lead = 0;
	wc = ft_countthewords(s, c);
	if (!(strs = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	while (row < wc)
	{
		while (ft_ischar(s[lead], c))
			lead++;
		follow = lead;
		while (!ft_ischar(s[lead], c) && s[lead])
			lead++;
		if (!(strs[row] = (char *)malloc(sizeof(char) * ((lead - follow + 1)))))
			return (NULL);
		row = ftwtw(lead - follow, strs, row, (s + follow));
	}
	strs[row] = NULL;
	return (strs);
}
