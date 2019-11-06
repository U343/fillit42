/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pole.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:19:57 by bedavis           #+#    #+#             */
/*   Updated: 2019/10/31 11:40:50 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Зпалняет поле пустыми ячейками .
*/

void	init_pole(char pole_alpha[16][16], int m)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < m)
	{
		j = 0;
		while (j < m)
			pole_alpha[i][j++] = '.';
	}
}

void	print_pole(char pole_alpha[16][16], int m)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < m)
	{
		j = 0;
		while (j < m)
			ft_putchar(pole_alpha[i][j++]);
		ft_putchar('\n');
	}
}

void	put_pole(int n, __uint128_t *res, char pole_alpha[16][16])
{
	int			i;
	int			j;
	int			k;
	__uint128_t	chislo;

	k = 120;
	i = 0;
	j = 0;
	chislo = res[n];
	while (k >= 0)
	{
		if ((chislo >> k) & 1)
		{
			pole_alpha[i][j] = (char)(n + 'A');
		}
		j = (k % 11) ? j + 1 : 0;
		i = (k % 11) ? i : i + 1;
		k--;
	}
}

void	unput_pole(int n, __uint128_t *res, char pole_alpha[16][16])
{
	int			i;
	int			j;
	int			k;
	__uint128_t	chislo;

	k = 120;
	i = 0;
	j = 0;
	chislo = res[n];
	while (k >= 0)
	{
		if ((chislo >> k) & 1)
		{
			pole_alpha[i][j] = '.';
		}
		j = (k % 11) ? j + 1 : 0;
		i = (k % 11) ? i : i + 1;
		k--;
	}
}

void	ft_putstr(char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i++]);
		}
	}
}
