/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libadt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:35:06 by yoshin            #+#    #+#             */
/*   Updated: 2024/12/28 16:08:31 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBADT_H
# define LIBADT_H

# include <unistd.h>
# include <stdlib.h>

//////////////////////////////////////////////
//                                          //
//            Common Definitions            //
//                                          //
//////////////////////////////////////////////

# ifndef COMMON_DEF
#  define COMMON_DEF

#  define TRUE (1)
#  define FALSE (0)

#  define SUCCESS (1)
#  define FAIL (0)

# endif

/* ---------------------------------------- */

//////////////////////////////////////////////
//                                          //
//          ADT Exception Code              //
//                                          //
//////////////////////////////////////////////

# ifndef ADT_EXCEPTION_DEF
#  define ADT_EXCEPTION_DEF

#  define INVALID_PARAMETER (-1)
#  define MALLOC_FAIL (-1)
#  define EMPTY_STACK (-1)

# endif

/* ---------------------------------------- */

//////////////////////////////////////////////
//                                          //
//         Common Types & Structure         //
//                                          //
//////////////////////////////////////////////

typedef int	t_flag;

typedef struct s_node
{
	void			*data;
	size_t			idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* ******************** */
/*  common/exception.c  */
/* ******************** */

t_flag		*get_adt_err_code(void);
void		set_adt_err_code(t_flag err_code);

/* ********************* */
/*  common/node_utils.c  */
/* ********************* */

t_node		*create_new_node(void *data);
void		release_node(t_node *node);

/* ---------------------------------------- */

//////////////////////////////////////////////
//                                          //
//                  Stack                   //
//                                          //
//////////////////////////////////////////////

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	size_t	size;
}	t_stack;

/* *************** */
/*  stack/stack.c  */
/* *************** */

t_stack		*create_stack(void);
int			empty(t_stack *stack);
void		clear_stack(t_stack *stack);
void		release_stack(t_stack **stack);

/* ******************* */
/*  stack/operation.c  */
/* ******************* */

void		push(t_stack *stack, void *data);
void		*pop(t_stack *stack);
/* ************* */
/*  hash/hash.c  */
/* ************* */


/* ****************** */
/*  hash/operation.c  */
/* ****************** */


/* ****************** */
/*  hash/utilities.c  */
/* ****************** */


#endif
