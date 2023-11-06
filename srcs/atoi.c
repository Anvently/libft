/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:57:33 by npirard           #+#    #+#             */
/*   Updated: 2023/11/06 18:12:54 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

static int	isspace(char c)
{
	if ((c >= '\b' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

/// @brief Convert the initial part of a string to an integer
/// Format : [n spaces](+-)[n digit]
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
	while (isspace(nptr[i]))
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
