/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:43:44 by npirard           #+#    #+#             */
/*   Updated: 2023/09/11 11:09:49 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_content(void *addr, int r_size)
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)
	{
		if (i < r_size)
		{
			if (*(unsigned char *)(addr + i) >= 32
			&& *(unsigned char *)(addr + i) <= 126)
				c = *(unsigned char *)(addr + i);
			else
				c = '.';
		}
		else
			return ((void)0);
		write(1, &c, 1);
		i++;
	}
}

void	write_hexa(unsigned char c, int is_hexa)
{
	unsigned char	c2;

	if (!is_hexa)
	{
		if (c / 16 < 10)
			c2 = '0' + (c / 16);
		else
			c2 = 'a' + (c / 16 - 10);
		write(1, &c2, 1);
	}
	if (c % 16 < 10)
		c2 = '0' + (c % 16);
	else
		c2 = 'a' + (c % 16 - 10);
	write(1, &c2, 1);
}

void	print_hexa(void *addr, unsigned int r_size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < r_size)
			write_hexa(*(unsigned char *)(addr + i), 0);
		else
			write(1, "  ", 2);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
}

//Cast address inside long int => 4 bytes / 32 bits / 8 char of 4 bits each
//Loop through each 4 bits which represent one hexa char (0 to f)
//Shift each bits to the right starting from the 28th (first char)
//Mask with bit 15 (binary = ...00001111) to retrieve the proper char
//Get the return char between '0' and 'f' and write it 
void	print_address(void *addr)
{
	unsigned long	ptr;
	int				i;

	ptr = (unsigned long) addr;
	i = 60;
	while (i >= 0)
	{	
		write_hexa((unsigned char)((ptr >> i) & 15), 1);
		i -= 4;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		print_address(addr + i);
		write(1, ": ", 2);
		print_hexa(addr + i, (size - i));
		print_content(addr + i, (size - i));
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

/*int	main(void)
{
	char str[1000];
	ft_print_memory(str, sizeof(str));
	char str2[] = "Ceci est un test d'affichage de print memory!SegFault";
	ft_print_memory(str2, sizeof(str2));
}*/
