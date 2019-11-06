/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_border2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:04:35 by wanton            #+#    #+#             */
/*   Updated: 2019/10/28 11:28:12 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

__uint128_t	right_border(int n)
{
	__uint128_t	res;
	int			pow;

	res = 0;
	pow = 121 - n;
	while (pow >= (11 - n))
	{
		res = res + ft_power(2, pow);
		pow -= 11;
	}
	return (res);
}

__uint128_t	bottom_border(int n)
{
	__uint128_t	res;
	int			pow;
	int			i;

	res = 0;
	pow = 120 - ((n - 1) * 11);
	i = 0;
	while (i++ < 11)
	{
		res = res + ft_power(2, pow--);
	}
	return (res);
}

__uint128_t	up_border(void)
{
	return (bottom_border(1));
}

__uint128_t	left_border(void)
{
	return (right_border(1));
}
