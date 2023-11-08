/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:11:27 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 12:05:34 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Allocate and return a new string where function f
/// was applied to every character of s.
/// @param s String to tranform.
/// @param f Function used for transformation. Takes as argument
///  the index of each char and the char
/// @return Address of the newly allocated function.
/// NULL if allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(ft_strlen(s) + 1);
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		(*f)(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/// @brief Transform the string s using the given f function.
/// @param s String to transform
/// @param f Function used for tranformation.
/// Takes as argument the index and the address of each char.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
