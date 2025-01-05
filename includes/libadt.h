/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libadt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:19:49 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/06 02:15:19 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libadt.h
 * @brief Header file for Abstract Data Type (ADT) library.
 *
 * Provides common definitions, error handling, and interfaces for stack
 * and hash table data structures.
 */

#ifndef LIBADT_H
# define LIBADT_H

# include <unistd.h>
# include <stdlib.h>
# include "common.h"
# include "common_err.h"

/** @defgroup Exceptions Error and Exception Handling
 *  @brief Error codes and utilities for error handling in ADT.
 *  @{
 */

# ifndef ADT_EXCEPTION_DEF
#  define ADT_EXCEPTION_DEF

typedef enum e_adt_err_code {
	EMPTY_STACK = -1,
	EMPTY_TABLE,
}	t_adt_err_code;

t_adt_err_code	*get_adt_err_code(void);
void			set_adt_err_code(t_adt_err_code err_code);

# endif /* ADT_EXCEPTION_DEF */

/** @} */ // End of Exceptions

/** @defgroup Stack Stack Data Structure
 *  @brief Interface and utilities for stack implementation.
 *  @{
 */

/* Stack Definitions */
typedef struct s_node {
	size_t			idx;
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	size_t	size;
}	t_stack;

/* Stack Managing Function Prototypes */
t_stack		*create_stack(void);
int			is_empty(t_stack *stack);
void		clear_stack(t_stack *stack, t_flag release_data);
void		release_stack(t_stack **stack, t_flag release_data);

/* Stack Operation Function Prototypes */
void		push(t_stack *stack, void *data);
void		*pop(t_stack *stack);
void		push_node(t_stack *stack, t_node *node);
t_node		*pop_node(t_stack *stack);

/* Stack Utility Function Prototypes */
t_node		*create_node(void *data);
void		release_node(t_node *node);

/** @} */ // End of Stack

/** @defgroup HashTable Hash Table Data Structure
 *  @brief Interface and utilities for hash table implementation.
 *  @{
 */

/* Hash Table Definitions */
typedef struct s_record {
	void			*key;
	void			*value;
	struct s_record	*next;
}	t_record;

typedef struct s_hashtable {
	t_record	**bucket;
	size_t		size;
}	t_hashtable;

/* Hash Table Managing Function Prototypes */
t_hashtable	*create_hashtable(
				size_t size);

void		release_hashtable(
				t_hashtable **table,
				t_flag release_key,
				t_flag release_value);

/* Hash Table Operation Function Prototypes */
void		put(
				t_hashtable *table,
				void *key,
				void *value,
				t_flag (*equal_key)(void *, void *));

void		*get(
				t_hashtable *table,
				void *key,
				t_flag (*equal_key)(void *, void *));

void		delete(
				t_hashtable *table,
				void *key,
				t_flag release_value,
				t_flag (*equal_key)(void *, void *));

/* Hash Table Utility Function Prototypes */
size_t		hashcode(
				void *key,
				size_t bucket_size);

t_record	*create_record(
				void *key,
				void *data);

void		delete_record(
				t_record **record,
				t_flag release_key,
				t_flag release_value);

/** @} */ // End of HashTable

#endif
