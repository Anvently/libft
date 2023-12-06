/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:59:13 by npirard           #+#    #+#             */
/*   Updated: 2023/12/06 18:01:29 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_isspace(char c)
{
	if ((c >= '\b' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

/// @brief Convert the initial part of a string to a long.
/// Format : \\[n spaces\\](+-)[n digit]
/// Does not check for overflow
/// @param nptr String to convert
/// @return Convert value or 0 if error.
int	ft_atol(const char *nptr)
{
	size_t	i;
	int		sign;
	long	n;

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
