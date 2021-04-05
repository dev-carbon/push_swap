/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:33:28 by humanfou          #+#    #+#             */
/*   Updated: 2021/04/05 12:35:22 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "push_swap.h"

t_args	*init_args(t_args *args, int argc, char **argv);
t_stack	*init_stack(t_stack *stack, t_args *args);

#endif
