/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:24:46 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 12:18:58 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_which_pointer(t_LIST *game)
{
	game -> wall = mlx_xpm_file_to_image(game -> mlx_ptr,
			"textures/AnyConv.com__my floor.xpm", &(game -> x), &(game -> y));
	game -> floor = mlx_xpm_file_to_image(game -> mlx_ptr,
			"textures/785136_1.xpm", &(game -> x), &(game -> y));
	game -> rabbit = mlx_xpm_file_to_image(game -> mlx_ptr,
			"textures/AnyConv.com__my rabbit.xpm", &(game -> x), &(game -> y));
	game -> carrot = mlx_xpm_file_to_image(game -> mlx_ptr,
			"mycollectible.xpm", &(game -> x), &(game -> y));
	game -> exit = mlx_xpm_file_to_image(game -> mlx_ptr,
			"textures/AnyConv.com__myexit.xpm", &(game -> x), &(game -> y));
}
