/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:30:14 by stempels          #+#    #+#             */
/*   Updated: 2025/01/28 15:38:34 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	min;
	int	max;
	t_elem	*stack_a;

	if (argc < 2)
		return (error_handler(ER_01));
	else if (argc == 2)
		stack_a = parse_str(argv[1], &min, &max);
	else
		stack_a = parse_arg(argc, argv, &min, &max);
	if (!stack_a)
		return (/*ERROR*/);
	return (push_swap(stack_a, min, max));
}
