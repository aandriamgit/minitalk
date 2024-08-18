/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:20:16 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/18 13:20:54 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	add_bck(t_list **head, char c)
{
	t_list	*temp;
	t_list	*point;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->c = c;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		return ;
	}
	point = *head;
	while (point->next != NULL)
		point = point->next;
	point->next = temp;
}

static void	put_list(t_list **head)
{
	t_list	*temp;
	t_list	*nxt;

	temp = *head;
	while (temp)
	{
		nxt = temp->next;
		ft_putchar_fd(temp->c, 1);
		free(temp);
		temp = nxt;
	}
	(*head) = NULL;
	ft_putchar_fd('\n', 1);
}

int	get_bit(int bit)
{
	int	lol[8];

	lol[0] = 128;
	lol[1] = 64;
	lol[2] = 32;
	lol[3] = 16;
	lol[4] = 8;
	lol[5] = 4;
	lol[6] = 2;
	lol[7] = 1;
	return (lol[bit]);
}

static void	build_list(int signal, siginfo_t *siginfo, void *context)
{
	static char		c;
	static int		bit;
	static t_list	*lst;

	(void)context;
	if (signal == SIGUSR1)
		c = c + get_bit(bit);
	bit++;
	if (bit == 8)
	{
		add_bck(&lst, c);
		if (c == '\0')
		{
			put_list(&lst);
			lst = NULL;
		}
		c = 0;
		bit = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("PID  ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = build_list;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
