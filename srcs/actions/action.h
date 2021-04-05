/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:11:48 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 11:11:50 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "push_swap.h"

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
t_stack	*push(t_stack *dst, t_stack *src);
t_stack	*pop(t_stack *stack);
void	execute(t_stack **a, t_stack **b, t_action *action);

#endif
