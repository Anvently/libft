#include <libft.h>

static void	put_nbr(char **s, unsigned long nb, unsigned int* nwrite, unsigned int size)
{
	if (*nwrite >= size)
		return;
	if (nb <= 9)
	{
		**s = '0' + nb;
		*s = *s + 1;
		(*nwrite)++;
	}
	else
	{
		put_nbr(s, nb / 10, nwrite, size);
		put_nbr(s, nb % 10, nwrite, size);
	}

}

unsigned int	ft_putunbr_buffer(unsigned long nbr, char* buffer, unsigned int size) {
	unsigned int	nwrite = 0;

	put_nbr(&buffer, nbr, &nwrite, size);
	return (nwrite);
}