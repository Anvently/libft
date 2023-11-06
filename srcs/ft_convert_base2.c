/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:11:17 by npirard           #+#    #+#             */
/*   Updated: 2023/09/18 19:11:29 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_abs(long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

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

int	base_check(char *base)
{
	int	i;

	i = 0;
	if (!base[i])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| is_space(base[i])
			|| ft_strlen(base) <= 1
			|| contain(base + i + 1, base[i]) >= 0)
			return (0);
		i++;
	}
	return (1);
}
