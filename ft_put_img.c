/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:34:20 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 19:34:48 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_img(t_LIST *game)
{
	int		i;
	int		j;
	void	*img_ptr;

	j = 0;
	while (game -> MAP[j])
	{
		i = 0;
		while (game -> MAP[j][i])
		{
			img_ptr = ft_which_image(game -> MAP[j][i], game);
			mlx_put_image_to_window(game -> mlx_ptr, // i have a problem here when it does segfault //
				game -> win_ptr, img_ptr, i * game -> x, j * game -> y);
			i++;
		}
		j++;
	}
	return (0);
}
