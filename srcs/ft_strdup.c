/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:56:24 by npirard           #+#    #+#             */
/*   Updated: 2023/09/15 09:54:06 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	size_t	l_src;
	char	*buffer;

	l_src = ft_strlen(src);
	buffer = (char *) malloc(l_src * sizeof(char));
	if (l_src && buffer)
		ft_strcpy(buffer, src);
	return (buffer);
}

/*int	main(void)
{
	char buffer[0];
	char *dest;

	dest = ft_strdup(buffer);
	printf("%p:%d \n", dest,dest[0]);
	
	return (0);
}*/
