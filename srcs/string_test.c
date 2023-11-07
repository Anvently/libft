/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:24:21 by npirard           #+#    #+#             */
/*   Updated: 2023/11/07 16:33:11 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Search for c in s starting from the beginning of s
/// @param s String to search in
/// @param c Char to find in s
/// @return Address of the first occurence of c in s.
/// NULL if not found
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] || (c == '\0'))
		return ((char *) s + i);
	return (NULL);
}

/// @brief Search for c in s starting from the end of s
/// @param s String to search in
/// @param c Char to find in s
/// @return Address of the last occurence of c in s.
/// NULL if not found
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *) s + i);
	while (i >= 0 && s[i] != c)
		i--;
	if (i >= 0)
		return ((char *) s + i);
	return (NULL);
}

/// @brief Compares s1 and s2 using ascii value of character.
/// @param s1 Null terminated string
/// @param s2 Null terminated string
/// @return difference between s1 and s2 where the first character differs
/// 0 if s1 and s2 are equal.
/// Negative value if s1 < s2.
/// Positive value if s1 > s2.
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/// @brief Compares the firt n characters of s1
/// and s2 using ascii value of character.
/// @param s1 Null terminated string
/// @param s2 Null terminated string
/// @return difference between s1 and s2 where the first character differs
/// 0 if s1 and s2 are equal.
/// Negative value if s1 < s2.
/// Positive value if s1 > s2.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/// @brief Find the first occurence of little in the len first characters of big
/// @param big String where the search occcurs
/// @param little Substring to find
/// @param len Number of character to search in big
/// @return Address where little starts in big if found.
/// Big if little is empty.
/// NULL if little wasn't found is the len first characters of big.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!little[0])
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		if (!ft_strncmp(big + i, little, len - i))
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}


