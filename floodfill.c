/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:51:34 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/10 10:47:50 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**floodfill_map(t_LIST *game)
{
	char	**p;
	int		j;

	p = malloc (game -> dolen * sizeof (char *));
	if (!p)
		return (NULL);
	j = 0;
	while (j < game -> dolen)
	{
		p[j] = ft_strdup(game -> MAP[j]);
		j++;
	}
	p[j] = 0;
	return (p);
}

void	floodfill_map_changer(char **flmap, int j, int i)
{
	if (flmap[j][i + 1] != '1' && flmap[j][i + 1] != 'E'
		&& flmap[j][i + 1] != 'H')
	{
		flmap[j][i + 1] = 'H';
		floodfill_map_changer(flmap, j, i + 1);
	}
	if (flmap[j][i - 1] != '1' && flmap[j][i - 1] != 'E'
		&& flmap[j][i - 1] != 'H')
	{
		flmap[j][i - 1] = 'H';
		floodfill_map_changer(flmap, j, i - 1);
	}
	if (flmap[j + 1][i] != '1' && flmap[j + 1][i] != 'E'
		&& flmap[j + 1][i] != 'H')
	{
		flmap[j + 1][i] = 'H';
		floodfill_map_changer(flmap, j + 1, i);
	}
	if (flmap[j - 1][i] != '1' && flmap[j - 1][i] != 'E'
		&& flmap[j - 1][i] != 'H')
	{
		flmap[j - 1][i] = 'H';
		floodfill_map_changer(flmap, j - 1, i);
	}
}

int	ft_check_themap(char **p, int line, int chara)
{
	if (p[line][chara] == 'C')
		return (ft_printf("Error\nNo Access to one of the Collectibles"), 1);
	else if (p[line][chara] == 'E')
	{
		if (p[line][chara + 1] == '1' && p[line][chara - 1] == '1'
			&& p[line + 1][chara] == '1' && p[line - 1][chara] == '1')
		{
			ft_printf("Error\nThe Player doesn't have access to The Exit");
			return (1);
		}
	}
	return (0);
}

int	floodfill(t_LIST *game)
{
	char	**p;
	int		j;
	int		i;

	j = 0;
	i = 0;
	p = floodfill_map (game);
	ft_find_player(game);
	floodfill_map_changer(p, game -> p_line, game -> p_chara);
	// while (p[j])
	// {
	// 	printf("%s\n", p[j]);
	// 	j++;
	// }
	// j = 0;
	while (p[j])
	{
		i = 0;
		while (p[j][i])
		{
			if (p[j][i] == 'C' || p[j][i] == 'E')
			{
				if (ft_check_themap(p, j, i) != 0)
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
