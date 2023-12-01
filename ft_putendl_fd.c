/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:41:29 by npirard           #+#    #+#             */
/*   Updated: 2023/12/01 16:56:36 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Write s on given file descriptor followed by a newline
/// @param s String
/// @param fd File descriptor. 0 stdin. 1 stdout. 2 stderr.
void	ft_putendl_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
