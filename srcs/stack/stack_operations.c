/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:18:31 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 02:18:32 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_err.h"
#include "libadt.h"

/**
 * @brief Pushes a new data onto the top of the stack.
 *
 * This function creates a new node containing the provided data and 
 * adds it to the top of the stack. The stack's size is updated accordingly.
 * If the stack is empty, the new node becomes both the top and the bottom.
 * Error codes are set if the input parameters are invalid or memory allocation fails.
 *
 * @param stack
 * - A pointer to the stack where the data will be added.
 * @param data
 * - A pointer to the data to be stored in the new node.
 *
 * @details
 * - If `stack` or `data` is NULL, the function sets the error code 
 *   to `INVALID_PARAMETER` and returns without modifying the stack.
 * - If memory allocation for the new node fails, the error code 
 *   is set to `MALLOC_FAIL` and the function returns without modifying the stack.
 * - The function increments the stack size and assigns the appropriate 
 *   index to the newly created node.
 *
 * @error
 * - `INVALID_PARAMETER` if `stack` or `data` is NULL.
 * - `MALLOC_FAIL` if memory allocation for the new node fails.
 *
 * @note
 * - The `idx` field of the newly added node is set to the current size 
 *   of the stack before incrementing the size.
 * 
 * @see create_node, is_empty, set_adt_err_code
 */
void	push(t_stack *stack, void *data)
{
	t_node	*new_node;

	new_node = (NULL);
	if (!stack || !data)
	{
		set_common_err_code(INVALID_PARAMS);
		return ;
	}
	new_node = create_node(data);
	if (!new_node)
	{
		set_common_err_code(MALLOC_FAIL);
		return ;
	}
	if (is_empty(stack))
		stack->bottom = new_node;
	else
	{
		stack->top->next = new_node;
		new_node->prev = stack->top;
	}
	stack->top = new_node;
	new_node->idx = stack->size++;
}

void	push_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
	{
		set_common_err_code(INVALID_PARAMS);
		return ;
	}
	if (is_empty(stack))
		stack->bottom = node;
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
	}
	stack->top = node;
	node->idx = stack->size++;
}

void	*pop(t_stack *stack)
{
	void	*data;
	t_node	*top_node;

	if (!stack)
	{
		set_common_err_code(INVALID_PARAMS);
		return (NULL);
	}
	if (is_empty(stack))
	{
		set_adt_err_code(EMPTY_STACK);
		return (NULL);
	}
	top_node = stack->top;
	data = top_node->data;
	stack->top = top_node->prev;
	free(top_node);
	top_node = NULL;
	stack->size--;
	if (is_empty(stack))
		stack->bottom = (NULL);
	else
		stack->top->next = (NULL);
	return (data);
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*top_node;

	if (!stack)
	{
		set_common_err_code(INVALID_PARAMS);
		return (NULL);
	}
	if (is_empty(stack))
	{
		set_adt_err_code(EMPTY_STACK);
		return (NULL);
	}
	top_node = stack->top;
	stack->top = top_node->prev;
	stack->size--;
	if (is_empty(stack))
		stack->bottom = (NULL);
	else
		stack->top->next = (NULL);
	return (top_node);
}
