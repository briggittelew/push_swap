/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:58:14 by karlewis          #+#    #+#             */
/*   Updated: 2022/12/15 18:25:07 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n_bytes)
{
	size_t		i;

	i = 0;
	if (n_bytes == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < n_bytes - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n_bytes)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
