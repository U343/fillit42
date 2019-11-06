/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:50:21 by wanton            #+#    #+#             */
/*   Updated: 2019/10/31 11:26:57 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1000

int					is_valid_tetr(int n, __uint128_t *mas);
int					read1(int fd);
int					ft_sqrt(int nb);
__uint128_t			ft_power(int num, int pow);
__uint128_t			up_border(void);
__uint128_t			left_border(void);
__uint128_t			right_border(int n);
__uint128_t			bottom_border(int n);
int					init_move(int n, __uint128_t *mas);
int					find_place(int *mass_info, __uint128_t *res,
		__uint128_t *pole, char pole_alpha[16][16]);
void				int_move_one(__uint128_t *x);
void				init_pole(char pole_alpha[16][16], int m);
void				print_pole(char pole_alpha[16][16], int m);
void				put_pole(int n, __uint128_t *res, char pole_alpha[16][16]);
void				unput_pole(int n, __uint128_t *res,
					char pole_alpha[16][16]);
void				map_clear(char pole_alpha[16][16]);
void				ft_putchar(char c);
void				ft_putstr(char *s);

#endif
