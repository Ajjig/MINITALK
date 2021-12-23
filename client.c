/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:13:03 by majjig            #+#    #+#             */
/*   Updated: 2021/12/23 13:14:38 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - '0') + (nb * 10);
		i++;
	}
	return (nb * sign);
}

void	signal_recived(int sig)
{
	if (sig == SIGUSR1)
		write(1, "\x1b[32mSignal Recived\n", 20);
}

void	send_bits(int c, int pid)
{
	int	i;
	int	send;

	i = 7;
	while (i > -1)
	{
		send = c >> i-- & 1;
		if (send)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, &signal_recived);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (*av[2])
			send_bits(*av[2]++, pid);
		send_bits(*av[2]++, pid);
	}
	else
		write(2, "Error\n\targument error\n", 22);
}
