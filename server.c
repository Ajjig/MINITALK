#include "minitalk.h"

int	pid_client = 0;

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		while (*str)
			write(fd, str++, 1);
}

void	signal_reciver(int sig, siginfo_t *sa, void *unused)
{
	static int	bit;
	static char	c;

	unused += 0;
	if (sa->si_pid != pid_client)
	{
		bit = 0;
		c = 0;
		pid_client = sa->si_pid;
	}
	c = c << 1 | (sig - 30);
	if (++bit != 8)
		return ;
	write(1, &c, 1);
	bit = 0;
	c = 0;
}

int	main()
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_reciver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("%d\n", getpid());
	while(1);
}
