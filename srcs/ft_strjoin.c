/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:29:12 by npirard           #+#    #+#             */
/*   Updated: 2023/09/19 10:41:25 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_join(int size, char **strs, char *sep, char *buffer)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			buffer[k++] = strs[i][j++];
		j = 0;
		while (i != size - 1 && sep[j])
			buffer[k++] = sep[j++];
		i++;
	}
	buffer[k] = '\0';
	return (buffer);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*buffer;
	int		total_size;
	int		i;

	buffer = (void *) 0;
	total_size = 0;
	i = 0;
	while (i < size)
		total_size += ft_strlen(strs[i++]);
	total_size += ft_strlen(sep) * (size - 1);
	if (size <= 0)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
		return (buffer);
	}
	else
		buffer = malloc(total_size * sizeof(char) + 1);
	if (buffer)
		buffer = ft_join(size, strs, sep, buffer);
	return (buffer);
}

/*int	main(int argc, char **argv)
{
	char	*dest;

	if (argc > 1)
	{
		dest = ft_strjoin(argc - 2, argv + 2, argv[1]);
		printf("%s\n", dest);
	}
	return (0);
}*/
