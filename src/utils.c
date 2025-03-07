/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:36 by retahri           #+#    #+#             */
/*   Updated: 2025/03/06 22:11:03 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}
int ft_isspace(char c)
{
	return(c >= 9 && c <= 13) || c == 32;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
int	ft_atoi(const char *str)
{
	int	n;
	int	rest;

	n = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	rest = 0;
	while (ft_isdigit(*str) == 1)
	{
		rest = (rest * 10) + (*str - '0');
		str++;
	}
	if (!ft_isdigit(*str))
	{
		ft_putstr("Error\n");
		exit(0);
	}
	return (rest * n);
}
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
