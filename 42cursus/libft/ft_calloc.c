#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(size * n);
	if (!buffer)
		return (0);
	ft_bzero(buffer, size * n);
	return (buffer);
}