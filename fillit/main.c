/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:15:43 by bedavis           #+#    #+#             */
/*   Updated: 2019/10/30 13:53:44 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ar, char **av)
{
	int fd;

	if (ar != 2)
	{
		ft_putstr("usage: sourse_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(read1(fd)))
		ft_putstr("error\n");
	close(fd);
	return (0);
}
