/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:51:38 by npirard           #+#    #+#             */
/*   Updated: 2023/09/10 12:53:04 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (!size)
		return (i);
	j = 0;
	while (src[j] && (j < (size - 1)))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

/*int	main(void)
{
	char	str1[] = "DDfsffee eger";
	char	str2[2] = "";
	int	length;
	
	length = 0;
	length = ft_strlcpy(str2, str1, 0);
	printf("%s, %d\n", str2, length);
	return (0);
}*/
