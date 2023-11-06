/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:15:01 by npirard           #+#    #+#             */
/*   Updated: 2023/09/14 10:47:26 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i != nb)
	{
		if (i > 46340)
			return (0);
		if (i * i > nb)
			return (0);
		i++;
	}
	return (i);
}

/*int	main(void)
{
	printf("2000:%d\n", ft_sqrt(4000000));
	printf("10:%d\n", ft_sqrt(100));
	printf("6:%d\n", ft_sqrt(36));
	printf("0:%d\n", ft_sqrt(0));
	printf("100:%d\n", ft_sqrt(10000));
	printf("0:%d\n", ft_sqrt(10001));
	
	printf("0:%d\n", ft_sqrt(-36));
	return (0);
}*/
