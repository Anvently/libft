/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:39:36 by npirard           #+#    #+#             */
/*   Updated: 2023/09/11 11:39:43 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (i < n && s1[i] && !s2[i])
		return (1);
	else if (i < n && !s1[i] && s2[i])
		return (-1);
	return (0);
}

/*int	main(void)
{
	char s1[] = "ABCD";
	char s2[] = "ABCd";
	char s3[] = "ABC";
	char s4[] = "ABCD";
	char s5[] = "ABC";
	char s6[] = "ABC";

	printf("%d, %d\n", ft_strncmp(s1, s2, 3), strncmp(s1, s2, 3));
	printf("%d, %d\n", ft_strncmp(s3, s4, 5), strncmp(s3, s4, 5));
	printf("%d, %d\n", ft_strncmp(s5, s6, 1), strncmp(s5, s6, 1));
	printf("%d, %d\n", ft_strncmp(s5, s5, 0), strncmp(s5, s5, 0));
}*/
