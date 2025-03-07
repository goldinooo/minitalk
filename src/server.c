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


void ft_signal_handler(int signal)
{
	static int bit = 0;
	static char mychar = 0;

	if (signal != SIGUSR1 && signal != SIGUSR2)
        return;
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
}

int main(int ac, char **av)
{	
	
	(void)av;
	if (ac != 1)
	{
		ft_putstr("error");
		return 0;
	}
	ft_putstr("this is my honorable pid ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, ft_signal_handler); // treating signals
	signal(SIGUSR2, ft_signal_handler); // treating signals
	while (1)
		pause();
	return 0;
}