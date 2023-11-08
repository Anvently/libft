/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:41 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 12:28:41 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Write c on given file descriptor
/// @param c Char
/// @param fd File descriptor. 0 stdin. 1 stdout. 2 stderr.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/// @brief Write s on given file descriptor
/// @param s String
/// @param fd File descriptor. 0 stdin. 1 stdout. 2 stderr.
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

/// @brief Write s on given file descriptor followed by a newline
/// @param s String
/// @param fd File descriptor. 0 stdin. 1 stdout. 2 stderr.
void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(1, "\n", 1);
}

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
