/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:59:19 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/10 11:17:46 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int check_walls(t_LIST *game)
{	
	int j;
	int i;
	int mark;
	int mark1;

	j = 0;
	mark = 0;
	mark1 = 0;
	while (game -> MAP[j])
	{
		i = 0;
		while (game -> MAP[j][i])
		{
			if (j = 0 && game -> MAP[j][i] == MAP[j + 1][i])
				mark++;
			else if (j == game -> dolen - 1 && game -> MAP[j][i] == MAP[j - 1][i])
				mark++;
			if (i == 0 && game -> MAP[j][i] == MAP[j][i + 1])
				mark1++;
			else if (i == game -> len - 1)
				mark1++;
			if (mark >= game -> dolen - 1 || mark1 >= game -> len - 1)
				return (5);
			i++;
		}
		j++;
	}
	return (0)
}
int	ft_valid(t_LIST *game, char c, int chara, int line)
{	
	game -> len = ft_strlen(game -> MAP[line]);
	game -> dolen = ft_dostrlen(game -> MAP);
	if (game -> MAP[line + 1])
	{
		if (ft_strlen(game -> MAP[line]) != ft_strlen(game -> MAP[line + 1]))
			return (1);
	}
	else if (line == 0 || chara == 0 || chara == game -> len - 1
		|| line == game -> dolen - 1)
	{	
		// if (!check_walls(game));
		// 	return (5);
		if (c != '1')
			return (2);
	}
	if (c == 'P')
		game -> check++;
	else if (c == 'C')
		game -> check1++;
	else if (c == 'E')
		game-> check2++;
	else if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (3);
	else if (line == game -> dolen - 1 && (game -> check != 1
			|| game -> check1 == 0 || game -> check2 != 1))
		return (4);
	return (0);
}

int	ft_check(t_LIST *game)
{
	int	i;
	int	line;

	line = 0;
	game -> check = 0;
	game -> check1 = 0;
	game -> check2 = 0;
	game -> dolen = ft_dostrlen(game -> MAP);
	if (ft_strlen(game -> MAP[line]) != ft_dostrlen(game -> MAP))
	{
		game -> len = ft_strlen(game -> MAP[line]);
		while (game -> MAP[line])
		{
			i = 0;
			while (game ->MAP[line][i])
			{
				if (ft_valid(game, game -> MAP[line][i], i, line) != 0)
					return (ft_valid(game, game -> MAP[line][i], i, line));
				i++;
			}
			line++;
		}
	}
	return (0);
}
