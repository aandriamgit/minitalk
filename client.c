/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:06:35 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/18 13:03:04 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

int		g_did_the_server_send_signal = 0;

void	better_pause(int signum)
{
	if (signum == SIGUSR1)
		g_did_the_server_send_signal = 1;
	else
		g_did_the_server_send_signal = 0;
}

void	mini_sig_handler(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		while (1)
		{
			if (g_did_the_server_send_signal == 1)
				break ;
		}
		better_pause(42);
	}
}

void	sig_handler(char **arv)
{
	int	i;
	int	j;
	int	pid;

	pid = ft_atoi(arv[1]);
	j = 0;
	while (arv[2][j])
	{
		i = 8;
		while (i--)
		{
			send_bin(arv[2][j], i, pid);
			while (1)
			{
				if (g_did_the_server_send_signal == 1)
					break ;
			}
			better_pause(42);
		}
		j++;
	}
	mini_sig_handler(pid);
}

int	valid_pid(char *lol)
{
	int	i;

	i = 0;
	while (lol[i])
	{
		if (!(lol[i] >= '0' && lol[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3 && valid_pid(argv[1]))
	{
		if (ft_atoi(argv[1]) < 1)
		{
			write(1, "[Error] please, one valid PID with one \"\" message\n",
				50);
			return (1);
		}
		signal(SIGUSR1, better_pause);
		sig_handler(argv);
	}
	else
		write(1, "[Error] please, one valid PID with one \"\" message\n", 50);
	return (0);
}
