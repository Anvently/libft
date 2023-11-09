/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:15:11 by npirard           #+#    #+#             */
/*   Updated: 2023/11/09 17:37:39 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	split(char const *s, char **buffer, char sep, int mode)
{
	int	i;
	int	j;
	int	word_index;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		while (s[i] && sep == s[i])
			i++;
		j = 0;
		while (s[i + j] && sep != s[i + j])
			j++;
		if (j)
			word_index++;
		if (j && mode == 1)
		{
			buffer[word_index - 1] = ft_substr(s, i, j);
			if (!buffer[word_index - 1])
				return (-1);
		}
		i += j;
	}
	return (word_index);
}

/// @brief Return a list of allocated string for each substring
///found in s using c as a delimiter. The list is null terminated.
/// @param s string to split using the delimiter
/// @param c delimiter used to split the string
/// @return Address of a null terminated list of string.
/// NULL if allocation fails.
char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = split(s, NULL, c, 0);
	strings = (char **) malloc((nb_words + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	strings[nb_words] = NULL;
	split(s, strings, c, 1);
	return (strings);
}
