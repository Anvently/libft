/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:57:54 by npirard           #+#    #+#             */
/*   Updated: 2024/01/19 11:31:02 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Compares the last n characters of s1
/// and s2 using ascii value of character.
/// @param s1 Null terminated string
/// @param s2 Null terminated string
/// @param n Number of characters to compare
/// @return difference between s1 and s2 where the first character differs
/// (starting from the end) . ```0``` if s1 and s2 are equal.
/// ```< 0``` if ```s1 < s2```.
/// ```> 0``` if ```s1 > s2```.
int	ft_strncmp_rev(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			len_s1;
	size_t			len_s2;
	unsigned char	c1 = 0, c2= 0;

	i = 0;
	if (n == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 && len_s2) {
		do {
			c1 = s1[len_s1 - i - 1];
			c2 = s2[len_s2 - i - 1];
			i++;
		} while (i < n && (len_s1 - i >= 1) && (len_s2 - i >= 1) && c1 == c2);
	}
	if (!(len_s1 && len_s2) || (c1 == c2 && i < n)) {
		if (len_s1 - i == 0)
			c1 = 0;
		else
			c1 =  s1[len_s1 - i - 1];
		if (len_s2 - i == 0)
			c2 = 0;
		else
			c2 = s2[len_s2 - i - 1];
	}
	return ((unsigned char) c1 - (unsigned char) c2);
}
