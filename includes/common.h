/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:38:10 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 00:38:36 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef enum e_boolean {
	TRUE = 1,
	FALSE = 0
}	t_boolean;

typedef enum e_status {
	SUCCESS = 1,
	FAIL = 0
}	t_status;

typedef enum e_flag {
	ON = 1,
	OFF = -1
}	t_flag;

#endif
