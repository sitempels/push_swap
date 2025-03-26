/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:21:21 by stempels          #+#    #+#             */
/*   Updated: 2025/03/26 11:17:25 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	parse_str(t_list **stack_a, char **argv);
static int	check_str(char **array, t_list **stack_a);
static int	check_arg(int argc, char **argv);
static int	check_dupli(t_list *stack_a, int content);

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (!check_arg(argc, argv))
		return (write(1, "Error\n", 6));
	parse_str(&stack_a, argv);
	if (!stack_a)
		return (write(1, "Error\n", 6));
	if (!stack_a->next)
	{
		lst_free(&stack_a);
		return (0);
	}
	push_swap(&stack_a);
	lst_free(&stack_a);
	return (1);
}

static void	parse_str(t_list **stack_a, char **argv)
{
	int		j;
	char	**array;

	(*stack_a) = NULL;
	j = 1;
	while (argv[j])
	{
		array = ft_split(argv[j], ' ');
		if (!check_str(array, stack_a))
			return ;
		arr_free(array);
		j++;
	}
	return ;
}

static int	check_str(char **array, t_list **stack_a)
{
	int		i;
	int		content;
	t_list	*new;

	i = 0;
	while (array[i])
	{
		content = ft_atoi(array[i]);
		if ((content == -1 && array[i][0] != '-')
			|| (content == 0 && array[i][0] != '0')
			|| (!check_dupli(*stack_a, content)))
		{
			free_on_close(stack_a, array, 0);
			return (0);
		}
		new = ft_lstnew(ft_atoi(array[i]));
		if (!new)
		{
			free_on_close(stack_a, array, 0);
			return (0);
		}
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}

static int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (j < (int)ft_strlen(argv[i])
				&& !ft_isdigit(argv[i][j + 1])))
				return (0);
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (j > 0 && !ft_isspace(argv[i][j - 1])))
				return (0);
			if (!ft_isdigit(argv[i][j])
				&& !ft_isspace(argv[i][j])
				&& !(argv[i][j] == '-' || argv[i][j] == '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
