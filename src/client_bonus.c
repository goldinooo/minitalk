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
#include <unistd.h>

static void delivered(int signal)
{
	(void)signal;
	ft_putstr("✅ Message sent\n");
}

static void bit_received(int signal)
{
    (void)signal;
}

void	send_bits_at_len(pid_t pid, char *str)
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
			pause();
			bit--;
		}
		idx++;
	}
}

int	main(int ac, char **av)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	pid_t				server_pid;
	struct sigaction	sig;
	struct sigaction	sig2;
	
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);

		sig.sa_handler = delivered;
		sigaction(SIGUSR1, &sig , NULL);

		sig2.sa_handler = bit_received;
		sigaction(SIGUSR2, &sig2, NULL);

		if (server_pid <= 0)
		{
			ft_putstr("wrong pid :)");
			return (0);
		}
		send_bits_at_len(server_pid, av[2]);
	}
	else
		ft_putstr("wrong argument :), Try: ./client <PID> <MESSAGE>");
	return (0);
}
