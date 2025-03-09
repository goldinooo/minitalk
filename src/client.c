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
#include <unistd.h>

static int signal_flag = 0;

void ack(int sig)
{
	if (sig == SIGUSR1)
		signal_flag = 2;
	else if(sig == SIGUSR2)
		signal_flag = 1;
}

void	send_8bits(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		signal_flag = 0;
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (signal_flag == 0)		
			usleep(200);
		bit--;
	}
}

void send_string(int pid, char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        send_8bits(pid, str[i++]);
    // Send null terminator
    send_8bits(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_putstr("Invalid pid :)");
			return (1);
		}
		signal(SIGUSR1, ack);
		signal(SIGUSR2, ack);
		send_string(server_pid, av[2]);
	}
	else
		ft_putstr("wrong argument :), Try: ./client <PID> <MESSAGE>");
	return (0);
}
