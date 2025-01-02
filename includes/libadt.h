/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libadt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:35:06 by yoshin            #+#    #+#             */
/*   Updated: 2025/01/03 05:47:10 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBADT_H
# define LIBADT_H

# include <unistd.h>
# include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////////// */
/* //                                                                      // */
/* //                         Common Definitions                           // */
/* //                                                                      // */
/* ////////////////////////////////////////////////////////////////////////// */

# ifndef COMMON_DEF

#  define COMMON_DEF

#  define TRUE (1)
#  define FALSE (0)

#  define SUCCESS (1)
#  define FAIL (0)

typedef int	t_flag;

# endif

/* ////////////////////////////////////////////////////////////////////////// */
/* //                                                                      // */
/* //                          Error / Exception                           // */
/* //                                                                      // */
/* ////////////////////////////////////////////////////////////////////////// */

# ifndef ADT_EXCEPTION_DEF

#  define ADT_EXCEPTION_DEF

#  define INVALID_PARAMETER (-1)
#  define MALLOC_FAIL (-1)
#  define EMPTY_STACK (-1)

# endif

/* ************************************************************************** */
/*                           common/adt_exception.c                           */
/* ************************************************************************** */

t_flag		*get_adt_err_code(void);
void		set_adt_err_code(t_flag err_code);

/* ////////////////////////////////////////////////////////////////////////// */
/* //                                                                      // */
/* //                                Stack                                 // */
/* //                                                                      // */
/* ////////////////////////////////////////////////////////////////////////// */

typedef struct s_node
{
	size_t			idx;
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	size_t	size;
}	t_stack;

/* ************************************************************************** */
/*                               stack/stack.c                                */
/* ************************************************************************** */

t_stack		*create_stack(void);
int			empty(t_stack *stack);
void		clear_stack(t_stack *stack, t_flag release_data);
void		release_stack(t_stack **stack, t_flag release_data);

/* ************************************************************************** */
/*                             stack/operation.c                              */
/* ************************************************************************** */

void		push(t_stack *stack, void *data);
void		*pop(t_stack *stack);

/* ************************************************************************** */
/*                           common/stack_utils.c                             */
/* ************************************************************************** */

t_node		*create_node(void *data);
void		release_node(t_node *node);

/* -------------------------------------------------------------------------- */

/* ////////////////////////////////////////////////////////////////////////// */
/* //                                                                      // */
/* //                                Hash                                  // */
/* //                                                                      // */
/* ////////////////////////////////////////////////////////////////////////// */

typedef struct s_record
{
	void			*key;
	void			*value;
	struct s_record	*next;
}	t_record;

typedef struct s_hashtable
{
	t_record	**bucket;
	size_t		size;
}	t_hashtable;

/* ************************************************************************** */
/*                               hash/hash.c                                  */
/* ************************************************************************** */

t_hashtable	*create_hashtable(size_t size);
void		release_hashtable(
				t_hashtable **table,
				t_flag release_key,
				t_flag release_value);

/* ************************************************************************** */
/*                            hash/operation.c                                */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                            hash/utilities.c                                */
/* ************************************************************************** */

size_t		hashcode(void *key, size_t bucket_size);
t_record	*create_record(void *key, void *data);
void		delete_record(
				t_record **record,
				t_flag release_key,
				t_flag release_value);

/* -------------------------------------------------------------------------- */

#endif
