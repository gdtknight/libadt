/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:17:13 by yoshin            #+#    #+#             */
/*   Updated: 2024/12/30 07:37:38 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

t_node	*create_new_node(void *data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = (NULL);
	new_node->next = (NULL);
	return (new_node);
}

void	release_node(t_node *node)
{
	node->data = (NULL);
	node->next = (NULL);
	node->prev = (NULL);
	free(node);
	node = (NULL);
}
