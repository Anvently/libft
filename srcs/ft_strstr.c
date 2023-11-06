/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:49:37 by npirard           #+#    #+#             */
/*   Updated: 2023/09/11 12:49:39 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (!s2[i])
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!to_find[0])
		return (str);
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str + i, to_find) == 0)
			return (str + i);
		i++;
	}
	return ((void *) 0);
}

/*int	main(void)
{
	char s1a[] = "";
	char s2a[] = "";
	char s1b[] = "";
	char s2b[] = "";
	char s3a[] = "Same";
	char s4a[] = "";
	char s3b[] = "Same";
	char s4b[] = "";
	char s5a[] = "Shorter";
	char s6a[] = "Than";
	char s5b[] = "Shorter";
	char s6b[] = "Than";

	printf("%s:%s\n", ft_strstr(s1a, s2a), strstr(s1b, s2b));
	printf("%s\n", strcmp(s1a, s1b) == 0 
	&& strcmp(s2a, s2b) == 0 ? "Success" : "Fail");
	printf("%s:%s\n", ft_strstr(s3a, s4a), strstr(s3b, s4b));
	printf("%s\n", strcmp(s3a, s3b) == 0 
	&& strcmp(s4a, s4b) == 0 ? "Success" : "Fail");
	printf("%s:%s\n", ft_strstr(s5a, s6a), strstr(s5b, s6b));
	printf("%s\n", strcmp(s5a, s5b) == 0 
	&& strcmp(s6a, s6b) == 0 ? "Success" : "Fail");
}*/
