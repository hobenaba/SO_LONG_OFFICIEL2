/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:13:59 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 12:23:36 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_move(int key, int *a, int *b)
{
	*a = 0;
	*b = 0;
	if (key == 13 || key == 126)
		*a = -1;
	else if (key == 0 || key == 123)
		*b = -1;
	else if (key == 1 || key == 125)
		*a = 1;
	else if (key == 2 || key == 124)
		*b = 1;
}

int	ft_check_which_key(int key, t_LIST *game, int *line, int *chara)
{
	ft_move(key, &(game -> mbls), &(game -> mbcs));
	if (game -> mbls == 0 && game -> mbcs == 0)
		return (0);
	if (game -> MAP[*line + game -> mbls][*chara + game -> mbcs] == '0'
		|| game -> MAP[*line + game -> mbls][*chara + game -> mbcs] == 'C')
	{
		if (game -> MAP[*line + game -> mbls][*chara + game -> mbcs] == 'C')
			game -> check1--;
		game -> MAP[*line + game -> mbls][*chara + game -> mbcs]
			= game -> MAP[*line][*chara];
		game -> MAP[*line][*chara] = '0';
		*line = *line + game -> mbls;
		*chara = *chara + game -> mbcs;
		return (1);
	}
	else if (game -> MAP[*line + game -> mbls][*chara + game -> mbcs] == '1')
		return (0);
	else if (game -> MAP[*line + game -> mbls][*chara + game -> mbcs] == 'E')
	{
		if (game -> check1 == 0)
		{
			mlx_destroy_window(game -> mlx_ptr, game -> win_ptr);
			exit(0);
		}
	}
	return (0);
}

int	ft_which_key(int key, t_LIST *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game -> mlx_ptr, game -> win_ptr);
		exit(0);
	}
	ft_find_player(game);
	game -> check = ft_check_which_key
		(key, game, &(game -> p_line), &(game -> p_chara));
	if (game -> check == 1)
	{
		mlx_clear_window(game -> mlx_ptr, game -> win_ptr);
		ft_put_img(game);
	}
	game -> move++;
	ft_printf("step : %d\n", game -> move);
	return (0);
}
