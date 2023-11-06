/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:19:41 by npirard           #+#    #+#             */
/*   Updated: 2023/09/08 11:35:19 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/*void	print_tab(int *tab, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = '0' + tab[i];
		write(1, &c, 1);
		i++;
	}
}

int	main(void)
{
	int tab[] = {7, 5, 6, 5, 5, 2, 3, 9, 0};

	ft_sort_int_tab(tab, 9);
	print_tab(tab, 9);
	return (0);
}*/
