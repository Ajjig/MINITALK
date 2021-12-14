#include "minitalk.h"

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

	if (ac == 3)
	{
		pid = atoi(av[1]);
		while(*av[2])
			send_bits(*av[2]++, pid);
	}
	else
		write(2, "Error\nargument error\n", 21);
}
