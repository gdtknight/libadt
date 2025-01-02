/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:47:03 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/03 05:33:10 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

void	put(
			t_hashtable *table,
			void *key,
			void *value,
			t_flag (*equal_key)(void *, void *))
{
	size_t		table_idx;
	t_record	*cur;
	t_record	*prev;

	table_idx = hashcode(key, table->size);
	prev = (NULL);
	cur = (table->bucket)[table_idx];
	while (cur)
	{
		prev = cur;
		if (equal_key(key, cur->key))
		{
			cur->value = value;
			return ;
		}
		cur = cur->next;
	}
	if (prev)
		prev->next = create_record(key, value);
	else
		(table->bucket)[table_idx] = create_record(key, value);
}

void	*get(t_hashtable *table, void *key, t_flag (*equal_key)(void *, void *))
{
	size_t		idx;
	t_record	*cur;

	idx = hashcode(key, table->size);
	cur = (table->bucket)[idx];
	while (cur)
	{
		if (equal_key(cur->key, key))
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

void	delete(
	t_hashtable *table,
	void *key,
	t_flag release_value,
	t_flag (*equal_key)(void *, void *))
{
	size_t		idx;
	t_record	*prev;
	t_record	*cur;

	idx = hashcode(key, table->size);
	prev = (NULL);
	cur = (table->bucket)[idx];
	while (cur)
	{
		if (equal_key(cur->key, key))
		{
			if (!prev)
				(table->bucket)[idx] = cur->next;
			else
				prev->next = cur->next;
			delete_record(&cur, FALSE, release_value);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
