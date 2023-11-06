/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:53:15 by npirard           #+#    #+#             */
/*   Updated: 2023/09/09 18:40:48 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				overlap;

	overlap = 0;
	i = 0;
	while (i < n)
	{
		if (src[i] && overlap == 0)
		{
			dest[i] = src[i];
			i++;
			continue ;
		}
		else if (src[i] == '\0')
			overlap = 1;
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char dest[6];
	char src[] = "123456789112345";
	printf("%s\n%s\n%s\n", src, ft_strncpy(dest, src, 6), dest);
	return (0);
}*/
