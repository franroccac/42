#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
}

int main()
{
	int fd = open("putnbr.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return 1;
	ft_putnbr_fd(189487, fd);
	close (fd);
	return 0;
}