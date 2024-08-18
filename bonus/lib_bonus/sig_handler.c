/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:18:54 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/18 13:19:08 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	send_bin(char c, int i, int pid)
{
	if ((c >> i) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}
