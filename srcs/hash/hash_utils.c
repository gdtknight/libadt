/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:41:15 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/02 17:23:06 by yoshin           ###   ########.fr       */
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

t_record	*create_new_record(void *key, void *data)
{
	t_record	*record;
	t_node		*value;

	record = (t_record *) malloc(sizeof(t_record));
	if (!record)
		return (NULL);
	value = create_node(data);
	if (!value)
	{
		free(record);
		return (NULL);
	}
	record->key = key;
	record->value = value;
	record->next = (NULL);
	return (record);
}

void	delete_record(t_record **record)
{
	if (!record || !*record)
	{
		set_adt_err_code(INVALID_PARAMETER);
		return ;
	}
	free((*record)->key);
	(*record)->key = (NULL);
	release_node((*record)->value);
	(*record)->value = (NULL);
	(*record)->next = (NULL);
	free(*record);
	*record = (NULL);
}
