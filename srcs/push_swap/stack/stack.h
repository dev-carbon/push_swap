/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:18:07 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/06 19:18:09 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

t_stack		*pop(t_stack *stack, int *top);
t_stack		*push(t_stack *stack, int top);
int			peek(t_stack *stack);
int			is_empty(t_stack *stack);
int			is_sorted(t_stack *stack);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);
void		display_stack(t_stack *stack);
void		destroy_stack(t_stack *stack);
t_stack		*create_stack(size_t size);

#endif
