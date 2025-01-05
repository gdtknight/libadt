/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:45:16 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 01:06:01 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_err.h"
#include "libadt.h"

t_hashtable	*create_hashtable(size_t size)
{
	t_hashtable	*new_table;
	size_t		idx;

	new_table = (t_hashtable *) malloc(sizeof(t_hashtable));
	if (!new_table)
	{
		set_common_err_code(MALLOC_FAIL);
		return (NULL);
	}
	new_table->size = size;
	new_table->bucket = (t_record **) malloc(sizeof(t_record *) * size);
	if (!(new_table->bucket))
	{
		set_common_err_code(MALLOC_FAIL);
		free(new_table);
		return (NULL);
	}
	idx = 0;
	while (idx < size)
		(new_table->bucket)[idx++] = (NULL);
	return (new_table);
}

void	release_hashtable(t_hashtable **table, t_flag release_key, t_flag release_value)
{
	size_t		idx;
	t_record	*cur;
	t_record	*next;

	if (!table || *table)
	{
		set_common_err_code(INVALID_PARAMS);
		return ;
	}
	idx = 0;
	while (idx++ < (*table)->size)
	{
		cur = ((*table)->bucket)[idx - 1];
		while (cur)
		{
			next = cur->next;
			delete_record(&cur, release_key, release_value);
			cur = next;
		}
		((*table)->bucket)[idx - 1] = (NULL);
	}
	free((*table)->bucket);
	(*table)->bucket = NULL;
	free(*table);
	*table = (NULL);
}
