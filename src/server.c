/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:43 by retahri           #+#    #+#             */
/*   Updated: 2025/03/07 01:20:56 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>


void ft_signal_handler(int signal, siginfo_t *info, void *s)
{
	static int bit = 0;
	static char mychar = 0;
	static int prev_pid = 0;

	(void)s;
	if (prev_pid != info->si_pid)
	{
		bit = 0;
		mychar = 0;
		prev_pid = info->si_pid;
	}
	mychar = mychar << 1; //making space for the new bit
	if (signal == SIGUSR1)
		mychar = mychar | 1; // add 1
	bit++;
	if (bit == 8)
	{
		ft_putchar(mychar);
		bit = 0;
		mychar = 0;
	}
	kill(info->si_pid, SIGUSR2); // send signal to client to confirm that the server received the bit
}

int main(int ac, char **av)
{	
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

	sig.sa_sigaction = ft_signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return 0;
}