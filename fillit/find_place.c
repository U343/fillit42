/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:42:04 by bedavis           #+#    #+#             */
/*   Updated: 2019/10/31 11:26:57 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Если фигурка подходит и не пересекает ничего лишнего
*/

int		is_match(int *m_i, __uint128_t *res, __uint128_t *pole, int first)
{
	if (((res[m_i[2]] & *pole) == 0) && !first &&
	((res[m_i[2]] & bottom_border(m_i[1] + 1)) == 0) &&
	((res[m_i[2]] & right_border(m_i[1] + 1)) == 0))
		return (1);
	else
		return (0);
}

/*
** Если фигурка не подошла
*/

int		if_noplace(int *m_i, __uint128_t *res, int *change_first)
{
	*change_first = 0;
	if ((res[m_i[2]] & right_border(m_i[1])) == 0)
		res[m_i[2]] = res[m_i[2]] >> 1;
	else
	{
		while ((res[m_i[2]] & left_border()) == 0)
			res[m_i[2]] = res[m_i[2]] << 1;
		if ((res[m_i[2]] & bottom_border(m_i[1])) == 0)
			res[m_i[2]] = res[m_i[2]] >> 11;
		else
			return (0);
	}
	return (1);
}

/*
** is_find[0] == is_find
** is_find[1] == change_first
*/

int		find_place(int *m_i, __uint128_t *res, __uint128_t *pole,
		char pole_alpha[16][16])
{
	int is_find[2];

	is_find[0] = 0;
	if (!(is_find[1] = 0) && (m_i[2] >= m_i[0]))
		return (1);
	int_move_one(&res[m_i[2]]);
	while (!is_find[0])
	{
		if (is_match(m_i, res, pole, is_find[1]))
		{
			*pole = *pole | res[m_i[2]];
			is_find[0] = 1;
			put_pole(m_i[2], res, pole_alpha);
		}
		else if (!if_noplace(m_i, res, &is_find[1]))
			return (0);
		if (is_find[0] && ++m_i[2])
			if (!(find_place(m_i, res, pole, pole_alpha)) && !(is_find[0] = 0))
			{
				is_find[1] = 1;
				*pole = *pole & (~res[--m_i[2]]);
				unput_pole(m_i[2], res, pole_alpha);
			}
	}
	return (1);
}
