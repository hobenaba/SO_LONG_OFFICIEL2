/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mywindow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:24:59 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 19:34:05 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_mywindow(t_LIST *game)
{
	game -> mlx_ptr = mlx_init();
	game -> win_ptr = mlx_new_window
		(game -> mlx_ptr, 60 * game -> len, 60 * game -> dolen, "My Game");
	ft_which_pointer(game);
	ft_put_img(game);//i have a problem here//
	mlx_key_hook(game -> win_ptr, ft_which_key, game);
	mlx_loop(game -> mlx_ptr);
	//printf("in ft_mywindow :\n%d", game -> check1);
	return (0);
}
