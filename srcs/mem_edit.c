/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:23 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 12:05:46 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

/// @brief Fill n bytes of given memory address pointed by s with given c byte.
/// @param s Address to fill
/// @param c Value to fill address with
/// @param n Number of byte to fill
/// @return s memory address
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((int *)(s + i++)) = c;
	return (s);
}

/// @brief Erase n bytes of given memory address pointed by s,
/// by writing '\0' byte.
/// @param s Memory address
/// @param n Number of byte to erase
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((int *) s)[i] = '\0';
	}
}

/// @brief Copy n bytes from memory address src to memory address dest.
/// The memory areas must not overlap.
/// @param dest Memory address
/// @param src  Memory address
/// @param n Number of byte to copy from src to dest
/// @return Memory area pointed by dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

/// @brief Move n byte from dest to src.
/// Both area may overlap so a temp buffer is used.
/// @param dest Memory address
/// @param src  Memory address
/// @param n Number of byte to move from src to dest
/// @return Memory area pointed by dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		direction;

	if (dest <= src)
	{
		i = 0;
		direction = 1;
	}
	else
	{
		i = n;
		direction = -1;
	}
	while (i >= 0 && i <= n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i += direction;
	}
	return (dest);
}

/// @brief Allocates memory for nmenb element of size bytes.
/// @param nmenb number of element
/// @param size size of each element
/// @return Address of allocated memory area.
/// NULL if nmenb or size is 0 or if nmenb * size > INT_MAX
void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*buffer;

	if (!nmenb || !size || nmenb * size > INT_MAX)
		return (NULL);
	buffer = malloc(nmenb * size);
	return (buffer);
}
