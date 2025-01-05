/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adt_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:00:08 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 00:48:10 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

t_adt_err_code	*get_adt_err_code(void)
{
	static t_adt_err_code	adt_err_code;

	return (&adt_err_code);
}

void	set_adt_err_code(t_adt_err_code adt_err_code)
{
	(*get_adt_err_code()) = adt_err_code;
}
