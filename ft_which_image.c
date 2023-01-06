/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:52 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 12:23:45 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_which_image(char c, t_LIST *game)
{
	if (c == '1')
		return (game -> wall);
	else if (c == '0')
		return (game -> floor);
	else if (c == 'P')
		return (game -> rabbit);
	else if (c == 'C')
		return (game -> carrot);
	else if (c == 'E')
		return (game -> exit);
	return (0);
}
