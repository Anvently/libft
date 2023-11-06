/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:21:16 by npirard           #+#    #+#             */
/*   Updated: 2023/09/12 14:26:53 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	contain(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_check(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (contain(str + i + 1, str[i]) >= 0
			|| str[i] == '+'
			|| str[i] == '-'
			|| !(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char*base)
{
	int	i;
	int	n;
	int	is_signed;

	i = 0;
	is_signed = 1;
	n = 0;
	if (base_check(base) <= 1)
		return (0);
	while (str[i] && contain(" \f\n\r\t\v", str[i]) >= 0)
		i++;
	if (!str[i] || (str[i] && !(contain("+-", str[i]) >= 0
				|| contain(base, str[i]) >= 0)))
		return (0);
	while (contain("+-", str[i]) >= 0)
	{
		if (str[i++] == '-')
			is_signed = -is_signed;
	}
	while (contain(base, str[i]) >= 0)
	{
		n = n * base_check(base) + contain(base, str[i++]);
	}
	return (n * is_signed);
}

/*int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2ebc585999a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}*/
