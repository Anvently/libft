/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:26:42 by npirard           #+#    #+#             */
/*   Updated: 2024/01/04 14:33:53 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Search a string in a list of string
/// @param strs List of strings. Ends with ```NULL```.
/// @param str String to find in strs
/// @return Pointer toward first occurence of str in strs.
/// ```NULL``` if none found.
int	ft_strschr(char **strs, char *str)
{
	if (!strs || !str)
		return (NULL);
	while (*strs && ft_strcmp(*strs, str))
		strs++;
	return (*strs);
}
