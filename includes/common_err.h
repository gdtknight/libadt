/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_err.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:45:19 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 00:58:28 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_ERR_H
# define COMMON_ERR_H

typedef enum e_common_err_code {
	NULL_PARAMS,
	INVALID_PARAMS,
	MALLOC_FAIL
}	t_common_err_code;

t_common_err_code	*get_common_err_code(void);
void				set_common_err_code(t_common_err_code myerr_code);

#endif
