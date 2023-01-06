/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:20:53 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 19:27:26 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	ft_which_error(t_LIST *game)
{
	if (game -> true == 1)
		ft_printf("Error\nThe Lines of the Map are not the exactly the same");
	else if (game -> true == 2)
		ft_printf("Error\nYour Map it's not surrounded by Walls");
	else if (game -> true == 3)
		ft_printf("Error\nOne of The Characters is not one of its Compositions");
	else if (game -> true == 4)
	{
		if (game -> check != 1)
			ft_printf("Error\nThere is a Problem with Your player");
		else if (game -> check1 == 0)
			ft_printf("Error\nThere is no collectibles to work with");
		ft_printf("Error\nThere is a Problem with your Exit");
	}
}

int	main(int ac, char **av)
{
	t_LIST	game;

	if (ac == 2)
	{
		game.p_line = 0;
		game.p_chara = 0;
		game.true3 = themap(av[1], &game);
		game.true2 = 0;
		if (game.true3 == 8)
			ft_printf("Error\nThere is no Map to work with");
		else if (game.true3 == 9)
			ft_printf("Error\nThis is not a Valid Map");
		if (game.true3 == 0)
			game.true = ft_check(&game);
		// if (game.true == 0)
		// 	game.true2 = floodfill(&game);
		if (game.true != 0)
			ft_which_error(&game);
		if (game.true == 0 && game.true2 == 0 && game.true3 == 0)
			ft_mywindow(&game);
	}
	return (0);
}
