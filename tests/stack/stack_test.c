/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:44:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/12/28 15:22:02 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"
#include "stack_test.h"
#include <string.h>

void	stack_create_test(void)
{
	t_stack	*test_stack;

	test_stack = create_new_stack();
	if (*(get_adt_err_code()) != MALLOC_FAIL && !test_stack)
	{
		write(1, CREATION_FAILED_MSG, strlen(CREATION_FAILED_MSG));
		return ;
	}
	write(1, CREATION_SUCCESS_MSG, strlen(CREATION_SUCCESS_MSG));
}

int	main(void)
{
	create_new_stack();
	return (0);
}
