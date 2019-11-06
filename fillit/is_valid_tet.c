/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:29:26 by bedavis           #+#    #+#             */
/*   Updated: 2019/10/31 11:37:29 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_index(char index[11][11])
{
	int		i;
	int		j;
	int		count;
	int		count_big;

	count = 0;
	count_big = 0;
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			if (index[i][j] == 0)
				return (0);
			if (index[i][j] > 0)
				count++;
			if (index[i][j] >= 1)
				count_big += index[i][j];
			j++;
		}
		i++;
	}
	return ((count_big >= 6 && count == 4) ? 1 : 0);
}

/*
** Проверка на валидность тетримино
** вычисляем индексы количества соседей каждой ячейки
** и проверяем что их 4, все не 0 и есть хотя бы две с индексом > 1
*/

int			check_neighbour(char index[11][11], int i, int j)
{
	int		n;

	n = 0;
	if (i > 0 && index[i - 1][j] > -1)
		n++;
	if (i < 11 && index[i + 1][j] > -1)
		n++;
	if (j > 0 && index[i][j - 1] > -1)
		n++;
	if (j < 11 && index[i][j + 1] > -1)
		n++;
	return (n);
}

int			put_index(char index[11][11])
{
	int		i;
	int		j;
	int		n;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			n = 0;
			if (index[i][j] > -1)
				index[i][j] = check_neighbour(index, i, j);
			j++;
		}
		i++;
	}
	return (check_index(index));
}

int			is_valid_int(__uint128_t x)
{
	char		index[11][11];
	int			k;
	int			i;
	int			j;

	i = 0;
	j = 0;
	k = 120;
	while (k >= 0)
	{
		index[i][j] = -1;
		if ((x >> k) & 1)
		{
			index[i][j] = 0;
		}
		j = (k % 11) ? j + 1 : 0;
		i = (k % 11) ? i : i + 1;
		k--;
	}
	return (put_index(index));
}

/*
** ПРоверка всех чисел в масииве на валидность
*/

int			is_valid_tetr(int n, __uint128_t *mas)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (!is_valid_int(mas[i]))
			return (0);
		i++;
	}
	return (1);
}
