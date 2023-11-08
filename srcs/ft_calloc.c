/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:47:02 by npirard           #+#    #+#             */
/*   Updated: 2023/11/08 17:48:27 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
