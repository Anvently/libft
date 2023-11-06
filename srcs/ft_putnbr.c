/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:45:39 by npirard           #+#    #+#             */
/*   Updated: 2023/09/09 19:30:22 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digits(char *digits, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		write(1, digits + (length - 1 - i), 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	long	n;
	char	digits[10];

	if (nb == 0)
		write(1, "0", 1);
	i = 0;
	n = nb;
	n = n * 10;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		digits[i] = '0' + (n % 10);
		i++;
	}
	print_digits(digits, i);
}

/*int	main(void)
{
	ft_putnbr(-2147483646);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(00003);
	write(1, "\n", 1);
	ft_putnbr(-0);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}*/
