/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:40:13 by bedavis           #+#    #+#             */
/*   Updated: 2019/10/26 15:43:00 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Перемещает тетримино в левый верхний угол карты
*/

void	int_move_one(__uint128_t *x)
{
	while (((*x & up_border()) == 0) || ((*x & left_border()) == 0))
	{
		if ((*x & up_border()) == 0)
			*x = *x << 11;
		if ((*x & left_border()) == 0)
			*x = *x << 1;
	}
}

int		init_move(int n, __uint128_t *mas)
{
	int		i;

	i = 0;
	while (i < n)
	{
		int_move_one(&mas[i]);
		i++;
	}
	return (1);
}
