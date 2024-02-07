/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:27:34 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 12:27:36 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int chr, size_t n)
{
	size_t	index;

	index = 0;
	while (index != n)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		if (((unsigned char *)dest)[index] == ((unsigned char)chr))
			return (((void *)(dest + index + 1)));
		index++;
	}
	return (NULL);
}
