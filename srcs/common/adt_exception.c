/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adt_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:00:08 by yoshin            #+#    #+#             */
/*   Updated: 2024/12/28 14:11:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

t_flag	*get_adt_err_code(void)
{
	static int	code;

	return (&code);
}

void	set_adt_err_code(int err_code)
{
	t_flag	*stack_err_code;

	stack_err_code = get_adt_err_code();
	*stack_err_code = err_code;
}