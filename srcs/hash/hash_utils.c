/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:41:15 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/03 05:28:44 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

size_t	hashcode(void	*key, size_t bucket_size)
{
	size_t	idx;
	size_t	ul;

	idx = 0;
	ul = (unsigned long) key;
	while (ul)
	{
		idx = ((idx + ul % 10) * 31) % bucket_size;
		ul /= 10;
	}
	return (idx);
}

t_record	*create_record(void *key, void *value)
{
	t_record	*record;

	record = (t_record *) malloc(sizeof(t_record));
	if (!record)
		return (NULL);
	record->key = key;
	record->value = value;
	record->next = (NULL);
	return (record);
}

void	delete_record(
	t_record **record,
	t_flag release_key,
	t_flag release_value)
{
	if (!record || !*record)
	{
		set_adt_err_code(INVALID_PARAMETER);
		return ;
	}
	if (release_key)
		free((*record)->key);
	if (release_value)
		free((*record)->value);
	(*record)->key = (NULL);
	(*record)->value = (NULL);
	(*record)->next = (NULL);
	free(*record);
	*record = (NULL);
}
