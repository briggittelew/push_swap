/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:09 by karlewis          #+#    #+#             */
/*   Updated: 2024/02/07 11:57:12 by karlewis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(int	*arr, int size)
{
	int		sorted;

	sorted = 1;
	while (size--)
		if (arr[size] > arr[size + 1])
			sorted = 0;
	return (sorted);
}

static void	choose_alg(t_stack **a, t_stack **b, t_technical *t, int argc)
{
	if (argc == 3)
		swap(a, t, A);
	if (argc == 4)
		sort_3(a, t, A);
	if (argc == 5)
		sort_4(a, b, t, 1);
	if (argc == 6)
		sort_5(a, b, t);
	if (argc > 6)
		asipes_algorithm(a, b, t);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_technical	t;
	int			sorted;

	init(&a, &b, &t);
	if (argc > 1)
	{
		fill_stack_and_arr(&a, &t, argc, argv);
		sorted = check_if_sorted(t.sorted_arr, t.a_num - 1);
		heap_sort(t.sorted_arr, t.a_num);
		check_doubles(t.sorted_arr, t.a_num - 1, sorted);
		assign_expected_positions(a, &t);
		choose_alg(&a, &b, &t, argc);
		inst_compress(t.inst);
		print_instructions(t.inst);
	}
	clean(&a, &b, &t);
	return (0);
}
