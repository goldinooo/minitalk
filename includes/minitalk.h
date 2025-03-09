/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:00:18 by retahri           #+#    #+#             */
/*   Updated: 2025/03/06 23:37:08 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);

void	signal_handler(int signum, siginfo_t *info, void *p);
void	ft_signal_handler(int signal, siginfo_t *info, void *s);
void	send_8bits(pid_t pid, char c);
void	send_bits_at_len(pid_t pid, char *str);

#endif