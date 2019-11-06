/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:09:43 by wanton            #+#    #+#             */
/*   Updated: 2019/10/28 11:54:53 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

__uint128_t			ft_power(int num, int pow)
{
	__uint128_t		res;
	int				i;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res = res * num;
		i++;
	}
	return (res);
}

int					ft_sqrt(int nb)
{
	int	temp;

	temp = 2;
	while ((temp * temp) < nb)
	{
		temp++;
	}
	return (temp);
}

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	if (n != 0)
	{
		i = 0;
		tmp = (unsigned char *)s;
		while (i < n)
		{
			tmp[i] = '\0';
			i++;
		}
	}
}

void				map_clear(char pole_alpha[16][16])
{
	int i;

	i = 0;
	while (i < 11)
	{
		ft_bzero(pole_alpha[i++], 11);
	}
}
