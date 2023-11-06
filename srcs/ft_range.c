/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:12:48 by npirard           #+#    #+#             */
/*   Updated: 2023/09/15 09:41:34 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	size;
	int	i;

	i = 0;
	size = max - min;
	array = 0;
	if (size > 0)
		array = (int *) malloc(size * sizeof(int));
	if (array)
	{
		while (i < size)
			array[i++] = min++;
		return (array);
	}
	return (0);
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;	

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n <= 9)
		ft_putchar('0' + n);
}

void	print_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i++]);
		write(1, " , ", 1);
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int *range;

	range = ft_range(0, 0);
	//print_tab(range, 10);
	range = ft_range(3, 3);
	
	range = ft_range(-1, 1);
	printf("-1, 0 : %d, %d", range[0], range[1]);
}*/
