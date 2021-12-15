/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:28:40 by atouhami          #+#    #+#             */
/*   Updated: 2021/12/12 11:28:41 by atouhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stddef.h>

/* printf functions */

int		ft_printf(const char *format, ...);
void	ft_put_adress(int *ret, unsigned long adrs);
void	ft_convert_hex(int *ret, char c, unsigned int n);
void	ft_put_unsigned_nbr(int *ret, unsigned int n);
void	ft_putnbr(int *ret, int n);
void	ft_putstr(int *ret, char *str);
void	ft_putchar(int *ret, char c);

/* libft functions */
int		ft_atoi(const char *str);

#endif
