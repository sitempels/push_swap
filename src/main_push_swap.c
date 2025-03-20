/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:21:21 by stempels          #+#    #+#             */
/*   Updated: 2025/03/20 17:07:12 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	parse_arg(t_list **stack_a, int argc, char **argv);
static void	parse_str(t_list **stack_a, int argc, char **argv);
static int	check_arg(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (!check_arg(argc, argv))
		return (0);
	if (argc == 2)
		parse_str(&stack_a, argc, argv);
	if (argc > 2)
		parse_arg(&stack_a, argc, argv);
	if (!stack_a)
		return (0);
	push_swap(&stack_a);
	lst_free(&stack_a);
	return (1);
}

static void	parse_str(t_list **stack_a, int argc, char **argv)
{
	int		i;
	int		content;
	char	**array;
	t_list	*new;

	(*stack_a) = NULL;
	array = ft_split(argv[argc - 1], ' ');
	i = 0;
	while (array[i])
	{
		content = ft_atoi(array[i]);
		if ((content == -1 && array[i][0] != '-') ||
			(content == 0 && array[i][0] != 0))
			return (lst_free(stack_a));
		new = ft_lstnew(ft_atoi(array[i]));
		if (!new)
			return (lst_free(stack_a));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	arr_free(array);
	return ;
}

static void	parse_arg(t_list **stack_a, int argc, char **argv)
{
	int		i;
	int		content;
	t_list	*new;

	(*stack_a) = NULL;
	i = 1;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		if ((content == -1 && argv[i][0] != '-') ||
			(content == 0 && argv[i][0] != 0))
		{
			lst_free(stack_a);
			return ;
		}
		new = ft_lstnew(content);
		if (!new)
		{
			lst_free(stack_a);
			return ;
		}
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return ;
}

static int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') 
				&& (i < (int)ft_strlen(argv[i]) 
				&& !ft_isdigit(argv[i][j + 1])))
				return (0);
			if ((argv[i][j] == '-' || argv[i][j] == '+') 
				&& (i > 0 && !ft_isspace(argv[i][j - 1])))
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
