/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:52:16 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 17:52:21 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Return an allocated substring of s, starting at
/// index start with len characters
/// @param s String to extract the substring from
/// @param start Index where the substring starts
/// @param len Maximum number of char to extract from s.
/// len parameter will be overrided with actual size of s if overflow.
/// @return Address of the allocated substring.
/// NULL if allocation failed
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;

	if (!s || start < 0 || len < 0)
		return (NULL);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}
