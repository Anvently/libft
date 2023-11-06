/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:27:31 by npirard           #+#    #+#             */
/*   Updated: 2023/09/18 19:27:33 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

char	*add_str(char **strs, int index, char *str, int size)
{
	int	i;

	strs[index] = (char *) malloc((size + 1) * sizeof(char));
	if (!strs[index])
		return (0);
	i = 0;
	while (i < size)
	{
		strs[index][i] = str[i];
		i++;
	}
	strs[index][i] = '\0';
	return (strs[index]);
}

int	split(char **strs, char *str, char *charset, int mode)
{
	int	i;
	int	j;
	int	count_str;

	i = 0;
	count_str = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && contain(charset, str[i + j]) < 0)
			j++;
		if (j != i && mode == 0)
			count_str++;
		else if (j != i && mode == 1)
			if (!add_str(strs, count_str++, str + i, j))
				return (0);
		while (contain(charset, str[i + j]) >= 0)
			j++;
		i += j;
	}
	if (mode == 0)
		return (count_str);
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		nb_str;

	strs = 0;
	nb_str = split(strs, str, charset, 0);
	if (!nb_str)
		return (0);
	strs = (char **) malloc((nb_str + 1) * sizeof(char *));
	if (!strs)
		return (strs);
	strs[nb_str] = 0;
	split(strs, str, charset, 1);
	return (strs);
}

/*void	print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs + i && strs[i])
	{
		printf("%p:%s\n", strs + i, strs[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**strs;
	(void) argv;

	if (argc == 3)
	{
		strs = ft_split(argv[1], argv[2]);
		print_strs(strs);
		printf("%p\n", strs);
	}
	return (0);
}*/
