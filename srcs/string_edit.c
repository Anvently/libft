/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:03:13 by npirard           #+#    #+#             */
/*   Updated: 2023/11/06 16:04:06 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Return the number of non empty bytes in a string
/// @param s Null terminated string
/// @return Size if the given string, excluding the null terminating byte
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s + i)
		i++;
	return (i);
}

/// @brief Try to copy the full length of src into dst,
/// adding a null byte at the end.
/// If src doesn't fit into dst, size - 1 byte wille be copied,
/// assuring the null byte at the end of dst.
/// @param dst Buffer into which src is copied.
/// @param src String to copy into dst
/// @param size Full size of the buffer dst
/// @return The length of the intended dst string, meaning the length of src.
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/// @brief Try to copy the full length of src after dst,
/// adding a null byte at the end.
/// If the resulting string doesn't fit into dst, size - 1 byte will be copied,
/// assuring the null byte at the end of dst.
/// @param dst The string receiving the concatenation.
/// @param src String to concatenate with dst
/// @param size Full size of the buffer dst.
/// @return The length of the intended resulting string,
/// meaning len(dst) len(src).
/// If dst is not null terminated, return size + len(src)
/// and dst will not be null terminated.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i])
		i++;
	if (i >= size)
		return (size + ft_strlen(src));
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
