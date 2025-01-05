/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:45:33 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 00:58:06 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_err.h"

t_common_err_code	*get_common_err_code(void)
{
	static t_common_err_code	code;

	return (&code);
}

void	set_common_err_code(t_common_err_code myerr_code)
{
	(*get_common_err_code()) = myerr_code;
}
