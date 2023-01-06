/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:59:36 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 12:25:58 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_LIST *game)
{
	while (game -> MAP[game -> p_line])
	{
		while (game -> MAP[game -> p_line][game -> p_chara] != '\0'
			&& game -> MAP[game -> p_line][game -> p_chara] != 'P')
			game -> p_chara++;
		if (game -> MAP[game -> p_line][game -> p_chara] == 'P')
			break ;
		game -> p_chara = 0;
		game -> p_line++;
	}
}
