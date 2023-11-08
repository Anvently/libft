/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:57:06 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 11:48:22 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Check alphabetic character [A-Za-z]
/// @param c Character to check
/// @return Non-zero if true, zero otherwise
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/// @brief Check digit character [0-9]
/// @param c Character to check
/// @return Non-zero if true, zero otherwise
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/// @brief Check digit or alphabetic character [0-9A-Za-z]
/// @param c Character to check
/// @return Non-zero if true, zero otherwise
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/// @brief Check if c fits into ascii table [0-127]
/// @param c Character to check
/// @return Non-zero if true, zero otherwise
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/// @brief Check if c is a printable character. Include space.
/// @param c Character to check
/// @return Non-zero if true, zero otherwise
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
