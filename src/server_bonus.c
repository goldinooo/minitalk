/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:43 by retahri           #+#    #+#             */
/*   Updated: 2025/03/07 01:11:16 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <sys/signal.h>
#include <stdio.h>
#include <unistd.h>

int v_bits = 7;

void signal_handler(int signal, siginfo_t *info ,void *s)
{
	static int	mychar;
	static int	prev_pid;
	static int	done;

	if (info->si_pid != prev_pid)
	{
		prev_pid = info->si_pid;
		mychar = 0;
		done = 0;
		v_bits = 7;		
	}
	if (signal == SIGUSR1)
		mychar = (1 << v_bits) | mychar;
	v_bits--;
	if (v_bits < 0)
	{
		if (mychar == '\0')
			(kill(info->si_pid, SIGUSR1), ft_putchar('\n'), done = 1);
		else
			(ft_putchar(mychar), mychar = 0, v_bits = 7);
	}
	usleep(100);
	if (!done)
		kill(info->si_pid, SIGUSR2);
}

int main(int ac, char **av)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	struct sigaction sig;
	(void)av;
	if (ac != 1)
	{
		ft_putstr("error");
		return 0;
	}
	ft_putstr("this is my honorable pid ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL); // treating signals
	sigaction(SIGUSR2, &sig, NULL); // treating signals
	while (1)
	{
		pause();
	}
	return 0;
}