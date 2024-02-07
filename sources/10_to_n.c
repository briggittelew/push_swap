/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_to_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:53:57 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:54:01 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/headers/libft.h"
#include <stdio.h>

int	_10_to_n(int val, int base)
{
	if (!val)
		return(0);
	return (_10_to_n(val / base, base) * 10 + (val % base));
}

// res = 10 * res + (val % base);
// 		val = val / base;

int	main(int argc, char **argv)
{
	int		base;
	int		table_size;
	int		i;

	if (argc != 3)
		return (1);
	base = ft_atoi(argv[1]);
	table_size = ft_atoi(argv[2]);
	i = 0;
	while (++i <= table_size)
		printf("%5d %10d\n", i, _10_to_n(i, base));
	return (0);
}