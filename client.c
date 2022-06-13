/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:55:44 by gilee             #+#    #+#             */
/*   Updated: 2021/06/21 20:59:58 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	sig_handler(int signo)
{
	(void)signo;
	write(1, "[ACK]", 5);
}

void	my_kill(int pid, int signo)
{
	kill(pid, signo);
	usleep(50);
}

int		main(int argc, char **argv)
{
	int	pid;
	int	cur;
	int	bit;

	if (argc != 3)
		exit(0);
	cur = 0;
	bit = 7;
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_handler);
	while (argv[2][cur])
	{
		while (bit > -1)
		{
			if ((argv[2][cur] >> bit) & 1)
				my_kill(pid, SIGUSR2);
			else
				my_kill(pid, SIGUSR1);
			bit--;
		}
		write(1, " ", 1);
		cur++;
		bit = 7;
	}
	return (0);
}
