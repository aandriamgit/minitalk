/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:08:13 by aandriam          #+#    #+#             */
/*   Updated: 2024/08/18 13:09:05 by aandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;

}					t_list;

int					ft_atoi(const char *nptr);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				send_bin(char c, int i, int pid);

#endif
