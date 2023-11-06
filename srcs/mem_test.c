/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:57 by npirard           #+#    #+#             */
/*   Updated: 2023/11/06 18:01:05 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Search for c in the first n bytes of s
/// @param s Address of a memory area
/// @param c Byte to find in s.
/// @param n Number of byte to scan in s.
/// @return Adress where the matching byte was found.
/// NULL if not found.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((int *) s)[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

/// @brief Compares the first n bytes from the memory areas s1 and s2.
/// @param s1
/// @param s2
/// @param n
/// @return difference between s1 and s2 where the first character differs
/// 0 if s1 and s2 are equal.
/// Negative value if s1 < s2.
/// Positive value if s1 > s2.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n && ((int *) s1)[i] == ((int *) s2)[i])
		i++;
	return (((int *) s1)[i] - ((int *) s2)[i]);
}
