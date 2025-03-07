/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:51 by retahri           #+#    #+#             */
/*   Updated: 2025/02/05 22:22:31 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_putstr("Invalid pid :)");
			return (0);
		}
		while (av[2][i])
		{
			send_bits(server_pid, av[2][i]);
			i++;
		}
		send_bits(server_pid, '\n');
	}
	else
	{
		ft_putstr("wrong argument :)");
		ft_putstr("Try: ./client <PID> <MESSAGE>");
	}
	return (0);
}
