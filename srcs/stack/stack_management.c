/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:18:27 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 02:18:27 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 *         Stack management functions for creating, clearing,
 *         and releasing a stack.
 */

#include <stdlib.h>
#include "common_err.h"
#include "libadt.h"

/**
 * @brief Creates a new stack.
 *
 * Allocates memory for a new stack and initializes it.
 *
 * @return 
 *        A pointer to the newly created stack,
 *        or NULL if memory allocation fails.
 */
t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
	{
		set_common_err_code(MALLOC_FAIL);
		return (NULL);
	}
	return (new_stack);
}

/**
 * @brief Checks if a stack is empty.
 *
 * @param[in] stack
 *        A pointer to the stack to check.
 *
 * @return
 *        1 if the stack is empty, 0 otherwise.
 */
int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

/**
 * @brief Clears all elements from the stack.
 *
 * Removes all elements from the stack.
 * Optionally releases the memory of the data.
 * 
 * @param[in, out] stack 
 *        A pointer to the stack to clear.
 * @param[in] release_data 
 *        A flag indicating whether to free the data in each element
 *        (non-zero value).
 */
void	clear_stack(t_stack *stack, t_flag release_data)
{
	if (!stack)
	{
		set_common_err_code(MALLOC_FAIL);
		return ;
	}
	while (!is_empty(stack))
	{
		if (release_data)
			free(pop(stack));
		else
			pop(stack);
	}
}

/**
 * @brief Releases the memory of a stack.
 * 
 * Clears the stack and then frees the stack structure itself.
 * 
 * @param[in, out] stack 
 *		A double pointer to the stack to release.
 * @param[in] release_data 
 *		A flag indicating whether to free the data in each element (non-zero value).
 */
void	release_stack(t_stack **stack, t_flag release_data)
{
	if (!stack || !*stack)
	{
		set_common_err_code(MALLOC_FAIL);
		return ;
	}
	clear_stack(*stack, release_data);
	free(*stack);
	*stack = NULL;
}
