/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:21:21 by stempels          #+#    #+#             */
/*   Updated: 2025/03/19 17:23:08 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static t_list	*parse_arg(int argc, char **argv);
static t_list	*parse_str(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack_a = parse_str(argc, argv);
	if (argc > 2)
		stack_a = parse_arg(argc, argv);
	if (!stack_a)
		return (0);
	if (!arg_valid(stack_a))
	{
		
	}
	push_swap(&stack_a);
	lst_free(&stack_a);
	return (1);
}

static t_list	*parse_str(int argc, char **argv)
{
	int		i;
	char	**array;
	t_list	*new;
	t_list	*stack_a;

	stack_a = NULL;
	array = ft_split(argv[argc - 1], ' ');
	i = 0;
	while (array[i])
	{
		new = ft_lstnew(ft_atoi(array[i]));
		if (!new)
			return (NULL);
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	arr_free(array);
	return (stack_a);
}

static t_list	*parse_arg(int argc, char **argv)
{
	int		i;
	t_list	*new;
	t_list	*stack_a;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
			return (NULL);
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_atoi(argv[i]) > INT_MAX)
		}
	}
	
}
