/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:21:21 by stempels          #+#    #+#             */
/*   Updated: 2025/03/24 15:54:01 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	parse_arg(t_list **stack_a, int argc, char **argv);
static void	parse_str(t_list **stack_a, int argc, char **argv);
static int	check_arg(int argc, char **argv);
static int	check_dupli(t_list *stack_a, int content);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*ptr;

	if (argc < 2)
		return (write(1, "Error\n", 6));
	if (!check_arg(argc, argv))
		return (write(1, "Error\n", 6));
	if (argc == 2)
		parse_str(&stack_a, argc, argv);
	if (argc > 2)
		parse_arg(&stack_a, argc, argv);
	if (!stack_a || !stack_a->next) 
		return (write(1, "Error\n", 6));
	ptr = (stack_a);

	printf("Before push_swap \n");
	while (ptr)
	{
		printf("%d ", ptr->content);
		ptr = ptr->next;
	}
	printf("\n");
	push_swap(&stack_a);
	ptr = (stack_a);
	printf("Before push_swap \n");
	while (ptr)
	{
		printf("%d ", ptr->content);
		ptr = ptr->next;
	}
	printf("\n");
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
			return (free_on_close(stack_a, array, 0));
		if (!check_dupli(*stack_a, content))
			return (free_on_close(stack_a, array, 0));
		new = ft_lstnew(ft_atoi(array[i]));
		if (!new)
			return (free_on_close(stack_a, array, 0));
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
			return (free_on_close(stack_a, NULL, 0));
		if (!check_dupli(*stack_a, content))
			return (free_on_close(stack_a, NULL, 0));
		new = ft_lstnew(content);
		if (!new)
			return (free_on_close(stack_a, NULL, 0));
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
				&& (j < (int)ft_strlen(argv[i])
				&& !ft_isdigit(argv[i][j + 1])))
				return (0);
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (j > 0 && !ft_isspace(argv[i][j - 1])))
				return (0);
			if (ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_dupli(t_list *stack_a, int content)
{
	t_list	*ptr;

	if (!stack_a)
		return (1);
	ptr = stack_a;
	while (ptr)
	{
		if (ptr->content == content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
