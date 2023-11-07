/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:57:33 by npirard           #+#    #+#             */
/*   Updated: 2023/11/07 17:33:02 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static int	ft_isspace(char c)
{
	if ((c >= '\b' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static size_t	len_nb(size_t len, long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	else if (nb > 0)
		len = len_nb(len + 1, nb / 10);
	if (len > 0)
		return (len);
	else
		return (1);
}

static void	put_nbr(char **s, long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		**s = '-';
		*s = *s + 1;
	}
	if (nb >= 0 && nb <= 9)
	{
		**s = '0' + nb;
		*s = *s + 1;
	}
	else
	{
		put_nbr(s, nb / 10);
		put_nbr(s, nb % 10);
	}
}

/// @brief Convert the initial part of a string to an integer.
/// Format : \\[n spaces\\](+-)[n digit]
/// Does not check for overflow
/// @param nptr String to convert
/// @return Convert value or 0 if error.
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		n;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		n = n * 10 + (nptr[i++] - '0');
	return (sign * n);
}

/// @brief Return an allocated string representing n.
/// @param n Positive or negative integer to convert.
/// @return String representing n. NULL if allocation fails.
char	*ft_itoa(int n)
{
	char	*buffer;
	char	*index;
	size_t	size;

	size = len_nb(0, (long) n);
	buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	index = buffer;
	put_nbr(&index, (long) n);
	return (buffer);
}
