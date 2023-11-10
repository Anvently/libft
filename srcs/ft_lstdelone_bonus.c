/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:59:43 by npirard           #+#    #+#             */
/*   Updated: 2023/11/10 13:09:26 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Free the content of given element using fct del
/// then free the element.
/// @param element Element to free
/// @param del Function used to free content of the element.
void	ft_lstdelone(t_list *element, void (*del)(void *))
{
	if (!element || !del)
		return ;
	(*del)(element->content);
	free(element);
}
