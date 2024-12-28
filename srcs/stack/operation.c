/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:40:56 by yoshin            #+#    #+#             */
/*   Updated: 2024/12/28 15:22:23 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

void	push(t_stack *stack, void *data)
{
	t_node	*new_node;

	new_node = (NULL);
	if (!stack || !data)
	{
		set_adt_err_code(INVALID_PARAMETER);
		return ;
	}
	new_node = create_new_node(data);
	if (!new_node)
	{
		set_adt_err_code(MALLOC_FAIL);
		return ;
	}
	if (empty(stack))
		stack->bottom = new_node;
	else
	{
		stack->top->next = new_node;
		new_node->prev = stack->top;
	}
	stack->top = new_node;
	new_node->cur_idx = stack->size++;
}

void	*pop(t_stack *stack)
{
	void	*data;
	t_node	*top_node;

	top_node = (NULL);
	if (!stack || empty(stack))
	{
		set_adt_err_code(EMPTY_STACK);
		return (NULL);
	}
	top_node = stack->top;
	data = top_node->data;
	stack->size--;
	stack->top = top_node->prev;
	free(top_node);
	top_node = NULL;
	if (empty(stack))
		stack->bottom = (NULL);
	if (!empty(stack))
		stack->top->next = (NULL);
	return (data);
}
