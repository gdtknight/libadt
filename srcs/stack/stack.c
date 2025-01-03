/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:35:22 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/03 05:46:19 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!new_stack)
	{
		set_adt_err_code(MALLOC_FAIL);
		return (NULL);
	}
	return (new_stack);
}

int	empty(t_stack *stack)
{
	return (stack->size == 0);
}

void	clear_stack(t_stack *stack, t_flag release_data)
{
	if (!stack)
	{
		set_adt_err_code(INVALID_PARAMETER);
		return ;
	}
	while (!empty(stack))
	{
		if (release_data)
			free(pop(stack));
		else
			pop(stack);
	}
}

void	release_stack(t_stack **stack, t_flag release_data)
{
	if (!stack || !*stack)
	{
		set_adt_err_code(INVALID_PARAMETER);
		return ;
	}
	clear_stack(*stack, release_data);
	free(*stack);
	*stack = (NULL);
}
