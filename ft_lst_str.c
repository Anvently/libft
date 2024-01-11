/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:42:54 by npirard           #+#    #+#             */
/*   Updated: 2024/01/11 10:47:19 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Append a string to a list of string.
/// @param lst
/// @param str
/// @return ```0``` for success.
/// ```-1``` if allocation error, list is freed.
int	ft_lst_str_append(t_list **lst, char *str)
{
	t_list	*node;
	char	*content;

	content = ft_strdup(str);
	if (!content)
	{
		ft_lstclear(lst, free);
		return (-1);
	}
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		ft_lstclear(lst, free);
		return (-1);
	}
	ft_lstadd_back(lst, node);
	return (0);
}

void	ft_lst_str_print(t_list *lst)
{
	char	*str;

	while (lst)
	{
		str = (char *) lst->content;
		ft_putendl_fd(str, 1);
		lst = lst->next;
	}
}
