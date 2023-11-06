/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:22:08 by npirard           #+#    #+#             */
/*   Updated: 2023/09/13 15:31:16 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*int	main(void)
{
	printf("%d\n%d\n%d\n%d\n", ft_recursive_power(10,5), ft_recursive_power(-5,1),
		 ft_recursive_power(0,0), ft_recursive_power(0,2));
	return (0);
}*/
