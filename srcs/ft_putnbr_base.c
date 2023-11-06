/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:42:14 by npirard           #+#    #+#             */
/*   Updated: 2023/09/12 12:55:30 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

int	contain(char *str, unsigned char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	base_check(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (contain(str + i + 1, str[i])
			|| str[i] == '+'
			|| str[i] == '-'
			|| !(str[i] > 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	l_base;

	l_base = base_check(base);
	if (l_base <= 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = -nbr;
	}
	else
		n = nbr;
	if (n > l_base - 1)
		ft_putnbr_base(n / l_base, base);
	ft_putchar(*(base + (n % l_base)));
}

/*int		main(void)
{
	ft_putnbr_base(-449582, "\x81\x69\x5a\x56");
	write(1, "\n42:", 4);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}*/
