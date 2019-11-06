/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:49:13 by wanton            #+#    #+#             */
/*   Updated: 2019/10/28 19:04:44 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Функция для вызова других функций
** Массив тетримо, представленных в виде short int передается в другие функции
** Также вызывает внутри себя функцию для проверки валидности тетримино
** mass_info[0] - cout; [1] - m (размер поля); [2] n - (номер фигуры)
*/

void		check_valid(int count, __uint128_t *res)
{
	if (!(is_valid_tetr(count, res)))
	{
		ft_putstr("error\n");
		exit(0);
	}
}

void		mass_transfer(int count, __uint128_t *res)
{
	__uint128_t					pole;
	char						pole_alpha[16][16];
	int							is_end;
	int							mass_info[3];

	pole = 0;
	mass_info[0] = count;
	mass_info[1] = ft_sqrt(count * 4);
	mass_info[2] = 0;
	check_valid(count, res);
	map_clear(pole_alpha);
	is_end = 0;
	while (mass_info[1] <= 11 && !is_end)
	{
		init_pole(pole_alpha, mass_info[1]);
		if (find_place(mass_info, res, &pole, pole_alpha))
		{
			print_pole(pole_alpha, mass_info[1]);
			is_end = 1;
		}
		mass_info[1]++;
	}
	if (!is_end)
		ft_putstr("error\n");
}

/*
** Формирование массива uint128 для упрощенного представления тетримино
*/

void		convert_int(int count, char *tmp)
{
	__uint128_t			res[count];
	int					i;
	int					pw;

	i = 0;
	while (i < count)
		res[i++] = 0;
	i = 0;
	while (i < count)
	{
		pw = 120;
		while (pw >= 84)
		{
			if (*tmp == '#')
				res[i] = res[i] + ft_power(2, pw);
			if (*tmp++ != '\n')
				pw--;
			else
				pw = pw - 7;
		}
		tmp += 2;
		i++;
	}
	mass_transfer(count, res);
}

/*
** Проверка валидности файла
*/

int			check_mass(char *buf)
{
	int i;
	int foo;
	int n;

	i = 0;
	n = 2;
	while (buf[i] != '\0')
	{
		foo = 0;
		n--;
		while (foo++ < 20)
		{
			if (!buf[i])
				return (0);
			if (buf[i] != '.' && buf[i] != '#' && (i + n) % 5 != 0)
				return (0);
			if ((i + n) % 5 == 0 && buf[i] != '\n')
				return (0);
			i++;
		}
		if (buf[i++] != '\0' && buf[i] != '.' && buf[i] != '#')
			return (0);
	}
	convert_int((n * -1) + 2, buf);
	return (1);
}

/*
** Основная функция
*/

int			read1(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
		return (0);
	buf[ret] = '\0';
	if (ret < 20)
		return (0);
	if (!(check_mass(buf)))
		return (0);
	return (1);
}
