/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:51 by retahri           #+#    #+#             */
/*   Updated: 2025/03/06 23:51:42 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <sys/signal.h>


static void delivered(int signal)
{
	(void)signal;
	ft_putstr("✅\n");
}

void	send_bits(pid_t pid, char *str)
{
	int	bit;
	int idx;
	int len;

	idx = 0;
	len = ft_strlen(str);
	while (idx <= len)
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((str[idx] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(90);
			bit--;
		}
		idx++;
	}
}

int	main(int ac, char **av)
{
	pid_t				server_pid;
	int					i;
	struct sigaction	sig;
	
	i = 0;
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		sig.sa_handler = delivered;
		sigaction(SIGUSR1, &sig , NULL);
		send_bits(server_pid, av[2]);
		if (server_pid < 3)
		{
			ft_putstr("wrong pid :)");
			return (0);
		}
	}
	else
		ft_putstr("wrong argument :), Try: ./client <PID> <MESSAGE>");
	return (0);
}
