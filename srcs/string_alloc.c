/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:22:50 by npirard           #+#    #+#             */
/*   Updated: 2023/11/07 18:20:16 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Allocate and return a copy of s
/// @param s String to copy
/// @return Address of the copy
///NULL if allocation fails
char	*ft_strdup(const char *s)
{
	char	*buffer;

	buffer = mll
}

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

/// @brief Allocate and return the concatenation of s1 and s2
/// @param s1 Null terminated string
/// @param s2 Null terminated string
/// @return Address of allocated string
/// NULL if allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buffer = malloc(size);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, size);
	ft_strlcat(buffer, s2, size);
	return (NULL);
}

/// @brief Allocate and return a string where chars contained in set
/// are trimmed, only at the beginning and the end of s1
/// @param s1 String to trim
/// @param set Set of characters to trim in s1
/// @return Address of trimmed string.
/// NULL if allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	trim_len;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	trim_len = len;
	while (ft_strchr(set, s1[i]))
	{
		trim_len--;
		i++;
	}
	while (ft_strchr(set, s1[len]))
	{
		trim_len--;
		len--;
	}
	return (ft_substr(s1, i, trim_len));
}


