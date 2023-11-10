/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:41:44 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 17:41:48 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	put_nbr(long nb, int fd)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd('0' + nb, fd);
	else
	{
		put_nbr(nb / 10, fd);
		put_nbr(nb % 10, fd);
	}
}

/// @brief Write n on given file descriptor
/// @param n Number to write
/// @param fd File descriptor. 0 stdin. 1 stdout. 2 stderr.
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd('0' + nb, fd);
	else
	{
		put_nbr(nb / 10, fd);
		put_nbr(nb % 10, fd);
	}
}
