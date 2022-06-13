/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:56:33 by gilee             #+#    #+#             */
/*   Updated: 2021/06/21 20:56:47 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

int		g_get_cnt = 0;
int		g_char = 0;

void	sig_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (signo == SIGUSR1)
	{
		g_get_cnt++;
		g_char <<= 1;
		kill(info->si_pid, SIGUSR1);
	}
	else if (signo == SIGUSR2)
	{
		g_get_cnt++;
		g_char <<= 1;
		g_char |= 1;
		kill(info->si_pid, SIGUSR1);
	}
	if (g_get_cnt == 8)
	{
		write(1, &g_char, 1);
		g_char = 0;
		g_get_cnt = 0;
	}
}

int		main(int argc, char **argv)
{
	struct sigaction	s_sigact;
	char				*pid;

	(void)argv;
	if (argc != 1)
		exit(0);
	pid = ft_itoa(getpid());
	s_sigact.sa_sigaction = &sig_handler;
	s_sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigact, NULL);
	sigaction(SIGUSR2, &s_sigact, NULL);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	while (1)
		pause();
}
