/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:52:37 by npirard           #+#    #+#             */
/*   Updated: 2023/09/11 16:52:39 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l_dest;
	unsigned int	l_src;

	l_dest = str_len(dest);
	l_src = str_len(src);
	if (size <= l_dest)
		return (l_src + size);
	i = 0;
	while (src[i] && i < (size - l_dest - 1))
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + l_src);
}

/*int	main(void)
{
	char s1a[10] = "";
	char s2a[] = "";
	char s1b[10] = "";
	char s2b[] = "";
	char s3a[10] = "Same";
	char s4a[] = "Size";
	char s3b[10] = "Same";
	char s4b[] = "Size";
	char s5a[20] = "Shorter";
	char s6a[] = "ThanMyself";
	char s5b[20] = "Shorter";
	char s6b[] = "ThanMyself";
	char s7a[20] = "Shorter";
	char s8a[] = "ThanMyself";
	char s7b[20] = "Shorter";
	char s8b[] = "ThanMyself";
	
	
	printf("%s\n", ft_strlcat(s1a, s2a, 6) 
	== strlcat(s1b, s2b, 6) ? "Success" : "Fail");
	printf("%s\n", strcmp(s1a, s1b) == 0 
	&& strcmp(s2a, s2b) == 0 ? "Success" : "Fail");
	printf("%s\n", ft_strlcat(s3a, s4a, 10) 
	== strlcat(s3b, s4b, 10) ? "Success" : "Fail");
	printf("%s\n", strcmp(s3a, s3b) == 0 
	&& strcmp(s4a, s4b) == 0 ? "Success" : "Fail");
	printf("%s\n", ft_strlcat(s5a, s6a, 4) 
	== strlcat(s5b, s6b, 4) ? "Success" : "Fail");
	printf("%s\n", strcmp(s5a, s5b) == 0 
	&& strcmp(s6a, s6b) == 0 ? "Success" : "Fail");
	printf("%s\n", ft_strlcat(s7a, s8a, 0) 
	== strlcat(s7b, s8b, 0) ? "Success" : "Fail");
	printf("%s\n", strcmp(s7a, s7b) == 0
	 && strcmp(s8a, s8b) == 0 ? "Success" : "Fail");
	printf("%d;%d\n", ft_strlcat(s5a, s6a, 0), 
	(int) strlcat(s5b, s6b, 0));
	
	
	printf("\n\nDetails:\n");

	printf("%s:%s\n%s:%s\n", s1a, s1b, s2a, s2b);
	printf("%s:%s\n%s:%s\n", s3a, s3b, s4a, s4b);
	printf("%s:%s\n%s:%s\n", s5a, s5b, s6a, s6b);
	printf("%s:%s\n%s:%s\n", s7a, s7b, s8a, s8b);
	
}*/
