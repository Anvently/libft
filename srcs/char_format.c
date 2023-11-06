/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:59:07 by npirard           #+#    #+#             */
/*   Updated: 2023/11/06 16:00:01 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Check if char is lowercase and convert it to uppercase.
/// @param c Ascii character to convert
/// @return Uppercase equivalent of c if exist
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

/// @brief Check if char is uppercase and convert it to lowercase.
/// @param c Ascii character to convert
/// @return Lowercase equivalent of c if exist
int	ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}
