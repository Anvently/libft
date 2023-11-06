/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:20:53 by npirard           #+#    #+#             */
/*   Updated: 2023/09/17 18:45:51 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

long	ft_abs(long nb);
int		ft_strlen(char *str);
int		base_check(char *base);
int		contain(char *str, char c);
int		is_space(char c);

long	increment_number(long nb, char c, int sign, char *base_from)
{
	int	remain_to_max;
	int	digit;
	int	base_l;

	base_l = ft_strlen(base_from);
	remain_to_max = INT_MAX % base_l;
	digit = contain(base_from, c);
	if (sign > 0 && (nb > INT_MAX / base_l
			|| (nb == INT_MAX / base_l && digit > remain_to_max)))
		return (INT_MAX);
	else if (sign < 0 && (nb > INT_MAX / base_l
			|| (nb == INT_MAX / base_l && digit > (remain_to_max + 1))))
		return (INT_MIN);
	else
		return (nb * base_l + digit);
}

long	parse_digit(char *str, char *base_from)
{
	int			sign;
	long		nb;
	int			i;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && contain(base_from, str[i]) >= 0)
	{
		nb = increment_number(nb, str[i], sign, base_from);
		if (nb == INT_MIN || nb == INT_MAX)
			return (nb);
		i++;
	}
	return (nb * sign);
}

int	len_number(int len, long nb, char *base_to)
{
	if (ft_abs(nb) > 0)
		len = len_number(len + 1, nb / ft_strlen(base_to), base_to);
	return (len);
}

void	convert_number(long nb, char *nbr_convert, char *base_to, int i)
{
	if (ft_abs(nb) > ft_strlen(base_to) - 1)
	{
		convert_number(nb / ft_strlen(base_to), nbr_convert, base_to, i - 1);
		convert_number(nb % ft_strlen(base_to), nbr_convert, base_to, i);
	}
	else if (ft_abs(nb) <= ft_strlen(base_to) - 1)
		nbr_convert[i] = base_to[ft_abs(nb)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*nbr_convert;
	long	nb;
	int		len_convert;

	nbr_convert = 0;
	if (!base_check(base_from) || !base_check(base_to))
		return ((void *) 0);
	nb = parse_digit(nbr, base_from);
	if (nb < 0)
		len_convert = len_number(0, (long) nb, base_to) + 2;
	else if (nb == 0)
		len_convert = 2;
	else
		len_convert = len_number(0, (long) nb, base_to) + 1;
	nbr_convert = (char *) malloc(len_convert * sizeof(char));
	if (!nbr_convert)
		return (nbr_convert);
	if (nb < 0)
		nbr_convert[0] = '-';
	convert_number((long) nb, nbr_convert, base_to, len_convert - 2);
	nbr_convert[len_convert - 1] = '\0';
	return (nbr_convert);
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 4)
	{
		str = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("%s\n", str);
	}
	return (0);
}
