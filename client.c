#include "minitalk.h"

void	signal_recived(int sig)
{
	if (sig == SIGUSR1)
		write(1, "\x1b[32mSignal Recived\n", 19);
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
		pid = atoi(av[1]);
		while(*av[2])
			send_bits(*av[2]++, pid);
		send_bits(*av[2]++, pid);
	}
	else
		write(2, "Error\nargument error\n", 21);
}
