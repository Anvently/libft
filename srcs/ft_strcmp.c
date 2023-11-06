/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:18:27 by npirard           #+#    #+#             */
/*   Updated: 2023/09/11 11:30:15 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (s1[i] && !s2[i])
		return (1);
	else if (!s1[i] && s2[i])
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

	printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("%d, %d\n", ft_strcmp(s3, s4), strcmp(s3, s4));
	printf("%d, %d\n", ft_strcmp(s5, s6), strcmp(s5, s6));
	printf("%d, %d\n", ft_strcmp(s5, s5), strcmp(s5, s5));
}*/
