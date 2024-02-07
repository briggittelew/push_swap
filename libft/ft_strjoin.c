/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:48:01 by karlewis          #+#    #+#             */
/*   Updated: 2022/12/19 12:08:24 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*n_str;
	size_t	len_str1;
	size_t	len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	n_str = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!n_str)
		return (NULL);
	ft_strcpy(n_str, (char *)str1);
	ft_strcat(n_str, (char *)str2);
	return (n_str);
}
