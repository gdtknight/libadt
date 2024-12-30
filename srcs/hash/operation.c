/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:47:03 by yoshin            #+#    #+#             */
/*   Updated: 2024/12/30 08:15:03 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

void	put(t_hashtable *table, void *key, void *data)
{
	size_t		idx;
	t_record	*cur;
	t_record	*prev;

	idx = hashcode(key, table->size);
	prev = (NULL);
	cur = (table->bucket)[idx];
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
	{
		cur = create_new_record(key, data);
		if (prev)
			prev->next = cur;
		return ;
	}
	cur->value->data = data;
}

t_node	*get(t_hashtable *table, void *key, t_flag (*equal_key)(void *, void *))
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
			delete_record(&cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
