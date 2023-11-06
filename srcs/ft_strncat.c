/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:31:41 by npirard           #+#    #+#             */
/*   Updated: 2023/09/11 12:32:52 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < nb)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char s1a[10] = "";
	char s2a[] = "";
	char s1b[10] = "";
	char s2b[] = "";
	char s3a[10] = "Same";
	char s4a[10] = "Size";
	char s3b[10] = "Same";
	char s4b[10] = "Size";
	char s5a[20] = "Shorter";
	char s6a[] = "ThanMyselffgdgdgdfgdggfggfgff";
	char s5b[20] = "Shorter";
	char s6b[] = "ThanMyselffgdgdgdfgdggfggfgff";

	printf("%s:%s\n", ft_strncat(s1a, s2a, 0), strncat(s1b, s2b, 0));
	printf("%s\n", strcmp(s1a, s1b) == 0 
	&& strcmp(s2a, s2b) == 0 ? "Success" : "Fail");
	printf("%s:%s\n", ft_strncat(s3a, s4a, 0), strncat(s3b, s4b, 0));
	printf("%s\n", strcmp(s3a, s3b) == 0 
	&& strcmp(s4a, s4b) == 0 ? "Success" : "Fail");
	printf("%s:%s\n", ft_strncat(s5a, s6a, 10), strncat(s5b, s6b, 10));
	printf("%s\n", strcmp(s5a, s5b) == 0 
	&& strcmp(s6a, s6b) == 0 ? "Success" : "Fail");
}*/
